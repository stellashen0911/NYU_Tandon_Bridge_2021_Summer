//
// Created by StellaShen on 2021/9/12.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class organism; //the base class for ant and bug
class ant;
class bug;
class world; //aka grid map

//four move directions
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

//create the Point object
struct Point {
    int x;
    int y;
};

//define the header of the class world
class world {
public:
    world(); //initialize a world with 20x20 grid
    ~world(); //delete world
    organism* valueAt(const Point& a_point) const; //getter
    void set_Value_At(const Point& a_point, organism* newVal); //setter
    void remove_organism(const organism* organism_ptr);
    void move_Value_at(const Point& a_point, const Point& newPoint);
    bool is_Empty_At(const Point& a_point) const;
    vector<Point> get_available_adjacent_cells(const Point& curr_pos) const;
    void print_World() const;
    void run_world();

private:
    organism* grid[20][20];
};

//define the header of the class organism, which is the base class for ant and bug
class organism {
public:
    organism(const Point& a_point, world* a_world, char a_type);
    organism();
    ~organism();

    //set them pure virtual functions
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual bool is_dead() = 0;
    virtual char get_type() const = 0;
    virtual void starve() = 0;

    Point getThePoint() const;
    bool getMoved() const;
    int getNoBreed() const;
    char getType() const;
    world* getWorldPtr() const;

    void setThePoint(const Point& aPoint);
    void setMoved(bool flag);
    void setNoBreed(int NoB);
    void setWorldPtr(world* aWorld);

    bool isInGrid(int x, int y) const;
    void die(world& world) const;

private:
    Point a_point;
protected:
    //these function can only be used in the derived class of organism
    Point thePoint; // location in the grid
    bool moved; // if moved, true. False otherwise.
    int noBreed; // Number of steps after breed
    char type; // 'o' means an Ant, 'X' is a Doodlebug
    world* worldPtr;
};

//derived class ant
class ant : public organism {
public:
    ant(const Point& a_point, world* a_world, char a_type);
    ant();
    ~ant();
    void move() override;
    void breed() override;
    bool is_dead() override;
    char get_type() const override;
    void starve() override;

private:
    int breed_timer;
};

//derived class bug
class bug : public organism {
public:
    bug(const Point& a_point, world* a_world, char a_type);
    bug();
    ~bug();

    void move() override;
    void breed() override;
    bool is_dead() override;
    char get_type() const override;
    void starve() override;

private:
    int breed_timer;
    int starve_timer;
    vector<Point> find_adjacent_ants(world& world);
};

ostream& operator <<(ostream& outs, const Point& pos);

int main () {
    srand(time(0));

    world World;
    int time = 0;

    while (true) {
        cout << "\nWorld at time = " << time << ":\n\n";
        World.print_World();
        cout << "\nPress ENTER to continue";
        cin.get();
        World.run_world();
        time++;
    }
    return 0;
}

organism::organism(const Point &a_point, world *a_world, char a_type) {
    thePoint = a_point;
    noBreed = 0;
    type = a_type;
    moved = false;
    worldPtr = a_world;
    worldPtr ->set_Value_At(a_point, this);
}
organism::organism() {}
organism::~organism() {}
Point organism::getThePoint() const {
    return thePoint;
}
bool organism::getMoved() const {
    return moved;
}
int organism::getNoBreed() const {
    return noBreed;
}
char organism::getType() const {
    return type;
}
world* organism::getWorldPtr() const {
    return worldPtr;
}
void organism::setThePoint(const Point& aPoint) {
    thePoint.x = aPoint.x;
    thePoint.y = aPoint.y;
}
void organism::setMoved(bool flag) {
    moved = flag;
}
void organism::setNoBreed(int NoB) {
    noBreed = NoB;
}
void organism::setWorldPtr(world* aWorld) {
    worldPtr = aWorld;
}
bool isInGrid(int x, int y)  {
    if (x >= 0 && x < 20 && y >= 0 && y < 20) {
        return true;
    }
    return false;
}
void organism::die(world& world) const {
    world.remove_organism(this);
}

ant::ant(const Point &a_point, world *a_world, char a_type) : organism(a_point, a_world, a_type){
    //deliberately empty
}
ant::ant() : organism(), breed_timer(0) {}
ant::~ant() {}
char ant::get_type() const {
    return 'o';
}
void ant::move() {
    int direction = rand() % 4;
    Point curr_pos = getThePoint();
    Point next_pos = curr_pos;

    switch (direction) {
        case UP:
            next_pos.x--;
            break;
            case DOWN:
                next_pos.x++;
                break;
                case LEFT:
                    next_pos.y--;
                    break;
                    case RIGHT:
                        next_pos.y++;
                        break;
                        default:
                            break;
    }

    if (worldPtr->is_Empty_At(next_pos)) {
        worldPtr->move_Value_at(curr_pos, next_pos);
    }
    breed_timer++;
}
void ant::breed() {
    if (breed_timer < 3) {
        return;
    }
    Point curr_pos = getThePoint();
    vector<Point> available_adjacent_cells = worldPtr->get_available_adjacent_cells(curr_pos);
    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Point new_ant_pos = available_adjacent_cells[random_pick];
        worldPtr->set_Value_At(new_ant_pos, new ant);
    }
    breed_timer = 0;
}
bool ant::is_dead() {
    return false;
}
void ant::starve() {}

bug::bug(const Point &a_point, world *a_world, char a_type) : organism(a_point, a_world, a_type){
    //deliberately empty
}
bug::bug() : organism(), breed_timer(0), starve_timer(0) {}
bug::~bug() {}
char bug::get_type() const {
    return 'X';
}
void bug::move() {
    Point curr_pos =getThePoint();
    vector<Point> adjacent_ants = find_adjacent_ants(*worldPtr);

    if (!adjacent_ants.empty()) {
        int random_pick = rand() % adjacent_ants.size();
        Point target_ant_pos = adjacent_ants[random_pick];

        worldPtr->valueAt(target_ant_pos)->die(*worldPtr);
        worldPtr->move_Value_at(curr_pos, target_ant_pos);
        breed_timer++;
        starve_timer = 0;
    } else {
        int direction = rand() % 4;
        Point next_pos = curr_pos;

        switch (direction) {
            case UP:
                next_pos.x--;
                break;
                case DOWN:
                    next_pos.x++;
                    break;
                    case LEFT:
                        next_pos.y--;
                        break;
                        case RIGHT:
                            next_pos.y++;
                            break;
                            default:
                                break;
        }

        if (worldPtr->is_Empty_At(next_pos)) {
            worldPtr->move_Value_at(curr_pos, next_pos);
        }
        breed_timer++;
        starve_timer++;
    }
}
void bug::breed() {
    if (breed_timer < 8) {
        return;
    }
    Point curr_pos = getThePoint();
    vector<Point> available_adjacent_cells = worldPtr->get_available_adjacent_cells(curr_pos);
    if (!available_adjacent_cells.empty()) {
        int random_pick = rand() % available_adjacent_cells.size();
        Point new_ant_pos = available_adjacent_cells[random_pick];
        worldPtr->set_Value_At(new_ant_pos, new bug);
    }
    breed_timer = 0;
}
bool bug::is_dead() {
    return false;
}
void bug::starve() {
    if (starve_timer < 3) {
        return;
    }
    die(*worldPtr);
}
vector<Point> bug::find_adjacent_ants(world& world) {
    Point curr_pos = getThePoint();
    vector<Point> adjacent_ants;
    vector<Point> candidates = {
            {curr_pos.x - 1, curr_pos.y},
            {curr_pos.x + 1, curr_pos.y},
            {curr_pos.x, curr_pos.y - 1},
            {curr_pos.x, curr_pos.y + 1}
    };

    for (Point pos: candidates) {
        organism* organism_ptr = worldPtr->valueAt(pos);
        if ((organism_ptr != nullptr) && (organism_ptr->get_type() == 'o')) {
            adjacent_ants.push_back(pos);
        }
    }
    return adjacent_ants;
}

world::world() {
        //create a 20x20 grid
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                grid[i][j] = nullptr;
            }
        }
        //create 5 initial doodlebugs
        for (int i = 0; i < 5; i++) {
            int x = rand() % 20;
            int y = rand() % 20;
            while (grid[x][y] != nullptr) {
                x = rand() % 20;
                y = rand() % 20;
            }
            Point a_point;
            a_point.x = x;
            a_point.y = y;
            grid[x][y] = new bug(a_point, this, 'X');
        }

        //create 100 initial ants
        for (int i = 0; i < 100; i++) {
            int x = rand() % 20;
            int y = rand() % 20;
            while (grid[x][y] != nullptr) {
                x = rand() % 20;
                y = rand() % 20;
            }
            Point a_point;
            a_point.x = x;
            a_point.y = y;
            grid[x][y] = new ant(a_point, this, 'o');
        }
}
world::~world() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
            }
        }
    }
}
organism* world::valueAt(const Point& a_point) const {
    return grid[a_point.x][a_point.y];
}
void world::set_Value_At(const Point& a_point, organism* newVal) {
    grid[a_point.x][a_point.y] = newVal;
    newVal ->setThePoint(a_point);
}
void world::remove_organism(const organism* organism_ptr) {
    Point point = organism_ptr ->getThePoint();
    grid[point.x][point.y] = nullptr;
    delete organism_ptr;
}
void world::move_Value_at(const Point& a_point, const Point& newPoint) {
    grid[newPoint.x][newPoint.y] = grid[a_point.x][a_point.y];
    grid[newPoint.x][newPoint.y] ->setThePoint(newPoint);
    grid[a_point.x][a_point.y] = nullptr;
}
bool world::is_Empty_At(const Point& a_point) const {
    if (grid[a_point.x][a_point.y] == nullptr) {
        return true;
    }
    return false;
}
vector<Point> world::get_available_adjacent_cells(const Point& curr_pos) const {
    vector<Point> available_adjacent_cells;
    vector<Point> candidates = {
            {curr_pos.x - 1, curr_pos.y},
            {curr_pos.x + 1, curr_pos.y},
            {curr_pos.x, curr_pos.y- 1},
            {curr_pos.x, curr_pos.y + 1}
    };
    for (Point pos: candidates) {
        if (is_Empty_At(pos)) {
            available_adjacent_cells.push_back(pos);
        }
    }
    return available_adjacent_cells;
}
void world::print_World() const{
    int numAnt;
    numAnt = 0;
    int numDBug;
    numDBug = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (grid[i][j] == nullptr) {
                cout << "-";
            } else if (grid[i][j] -> getType() == 'o') {
                cout << "o";
                numAnt++;
            } else {
                cout << "X";
                numDBug++;
            }
        }
        cout << endl;
    }
    cout << endl << "Ants: " << numAnt;
    cout << "    Doodlebugs: " << numDBug << endl;
}
void world::run_world() {
    vector<organism*> ants;
    vector<organism*> doodlebugs;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == 'X')) {
                doodlebugs.push_back(grid[i][j]);
            }
        }
    }

    for (organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->move();
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if ((grid[i][j] != nullptr) && (grid[i][j]->get_type() == 'o')) {
                ants.push_back(grid[i][j]);
            }
        }
    }

    for (organism* ant_ptr: ants) {
        ant_ptr->move();
    }

    for (organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->breed();
    }

    for (organism* doodlebug_ptr: doodlebugs) {
        doodlebug_ptr->starve();
    }

    for (organism* ant_ptr: ants) {
        ant_ptr->breed();
    }
}

