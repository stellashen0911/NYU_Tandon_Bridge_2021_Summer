#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//class declaration
class Double_LinkedList;
class Double_LinkedList_Node;
class employee;

typedef Double_LinkedList_Node* Double_ptr;

//functions declaration
void open_input_file(ifstream& in_file);
void store_employees(Double_LinkedList& employee_list, ifstream& employees_file);
void update_total_pay(Double_LinkedList& employee_list, ifstream& payroll_file);
void fill_employee_vector(Double_LinkedList& employee_list, vector<employee>& employees);
void print_payroll(const vector<employee>& employees);
void sort(vector<employee>& employees);

//class employee
class employee {
public:
    //constructor
    employee() : name(""), ID(0), pay_per_hour(0), work_hour(0), total_pay(0) {}
    employee(string name_input, int ID_input, double pay) : name(name_input), ID(ID_input), pay_per_hour(pay), work_hour(0), total_pay(0) {}

    //accessor getter
    string get_name() const {return name;}
    int get_ID() const {return ID;}
    double get_pay_rate() const {return pay_per_hour;}
    double get_work_hour() const {return work_hour;}
    double get_total_pay() const {return total_pay;}
    //setter
    void set_work_hour(double hour) {this->work_hour += hour;}
    void set_total_pay() { this->total_pay = (this->work_hour * this->pay_per_hour);}

private:
    string name;
    int ID;
    double pay_per_hour;
    double work_hour;
    double total_pay;
};

//class Double_LinkedList_Node
class Double_LinkedList_Node {
public:
    //constructor
    Double_LinkedList_Node(Double_ptr next_ptr = nullptr , Double_ptr prev_ptr = nullptr, const employee& staff = employee()) : next(next_ptr), prev(prev_ptr), staff(staff) {}

    //accessor
    employee& get_employee();
    Double_ptr get_next() const;
    Double_ptr get_prev() const;

    //allow Double_LinkedList to access this class
    friend class Double_LinkedList;

private:
    employee staff;
    Double_ptr next;
    Double_ptr prev;
};
employee& Double_LinkedList_Node::get_employee() {
    return this->staff;
}
Double_ptr Double_LinkedList_Node::get_next () const {
    return this->next;
}
Double_ptr Double_LinkedList_Node::get_prev () const {
    return this->prev;
}

//class Double_LinkedList
class Double_LinkedList {
public:
    //constructor
    Double_LinkedList() : start(nullptr) {}
    ~Double_LinkedList() {clear();}

    //accessor
    Double_ptr get_start() const;
    Double_ptr get_tail() const;
    void insert_at_end(const employee& staff);
    int size() const;
    bool is_empty() const;

private:
    void clear();
    Double_ptr start;
};
Double_ptr Double_LinkedList::get_start() const {
    return this->start;
}
Double_ptr Double_LinkedList::get_tail() const {
    Double_ptr temp = this->start;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}
void Double_LinkedList::insert_at_end(const employee& staff) {
    if (is_empty()) {
        this->start = new Double_LinkedList_Node(nullptr, nullptr, staff);
    } else {
        Double_ptr end = this->get_tail();
        Double_ptr new_node = new Double_LinkedList_Node(nullptr, end, staff);
        end->next = new_node;
    }
}
int Double_LinkedList::size() const {
    int count = 0;
    Double_ptr temp = this->start;
    while(temp != nullptr) {
        temp = temp->next;
        count++;
    }
    return count;
}
bool Double_LinkedList::is_empty() const {
    return (start == nullptr);
}
void Double_LinkedList::clear() {
    Double_ptr temp = start;
    while(temp != nullptr) {
        Double_ptr discard = temp;
        temp = temp->next;
        delete discard;
    }
}


int main() {
    Double_LinkedList employee_list;
    vector<employee> employees;
    ifstream employees_file;
    ifstream pay_roll_file;

    cout<<"Open the employees file. \n";
    open_input_file(employees_file);
    cout <<"Read and store employees...\n\n";
    store_employees(employee_list,employees_file);
    cout << "Inputs read from file successfully!\n";
    employees_file.close();
    cout<<"\n";

    cout <<"Open the payroll file.\n";
    open_input_file(pay_roll_file);
    cout <<"Update payroll information...\n\n";
    update_total_pay(employee_list,pay_roll_file);
    cout << "Inputs read from file successfully!\n\n";
    pay_roll_file.close();

    fill_employee_vector(employee_list, employees);

    sort(employees);
    print_payroll(employees);

    return 0;
}

//detail implementations of the functions
bool operator <(const employee& employee1, const employee& employee2) {
    return employee1.get_total_pay() > employee2.get_total_pay();
}
void open_input_file(ifstream& in_file) {
    string name;
    cout<<"Please enter the file name: \n";
    cin>>name;
    in_file.open(name);

    while (!in_file) {
        cout << "Input file opening failed\n";
        cout << "Please enter the input file name again: ";
        cin >> name;
        in_file.clear();
        in_file.open(name);
    }
}
void store_employees(Double_LinkedList& employee_list, ifstream& employees_file) {
    int ID;
    double pay_rate;
    char symbol;

    while (employees_file >> ID) {
        employees_file >> pay_rate;
        employees_file.ignore(9999,' ');
        string Name = "";

        employees_file.get(symbol);
        while ((!employees_file.eof()) && (symbol != '\r') && (symbol != '\n')) {
            Name += symbol;
            employees_file.get(symbol);
        }
        employee employee(Name,ID,pay_rate);
        employee_list.insert_at_end(employee);
    }
}
void update_total_pay(Double_LinkedList& employee_list, ifstream& payroll_file) {
    double empWorkHours;
    int id;
    Double_ptr itr = employee_list.get_start();

    //Read inputs from second file
    while (payroll_file >> id ) {
        payroll_file >> empWorkHours;
        payroll_file.ignore(9999,'\n');

        //Iterate the list to find matching employee
        while (itr != nullptr) {
            if (itr->get_employee().get_ID() == id) {
                //Set employee working hours and net pay
                itr->get_employee().set_work_hour(empWorkHours);
                itr->get_employee().set_total_pay();
                break;
            }
            else
                itr = itr->get_next();
        }
    }
}
void fill_employee_vector(Double_LinkedList& employee_list, vector<employee>& employees) {
    int size = employee_list.size();
    Double_ptr curr = employee_list.get_start();
    for(int i = 0; i < size; i++) {
        employees.push_back(curr->get_employee());
        curr = curr->get_next();
    }
}
int partition(vector<employee>& employees, int low, int high) {
    int i = low - 1;
    double pivot = employees[high].get_total_pay();
    for (int j = low; j < high; j++) {
        if (employees[j].get_total_pay() < pivot) {
            i++;
            swap(employees[i], employees[j]);
        }
    }
    swap(employees[high], employees[i+1]);
    return (i+1);
}
void quick_sort(vector<employee>& employees, int low, int high)  {
    if (low < high) {
        int p = partition(employees, low, high);
        quick_sort(employees,low, p - 1);
        quick_sort(employees, p + 1, high);
    } else {
        return;
    }
}
//this sort is using quick sort, and the order is ascending (from smallest to largest).
void sort(vector<employee>& employees) {
    int low = 0;
    int high = employees.size() - 1;
    quick_sort(employees, low, high);
}
void print_payroll(const vector<employee>& employees) {
    int count = employees.size() - 1;

    cout << "*********Payroll Information********\n";
    //print from descending order; so the person who gets paid most prints first
    for (int i = count; i >= 0; i--) {
        cout << employees[i].get_name()<<", $"<< employees[i].get_total_pay() << endl;
    }
    cout << "*********End payroll**************\n";
}