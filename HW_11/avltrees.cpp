#include <iostream>
#include <set>
#include <ctime>
#include <vector>

using namespace std;

void sortUsingTree(vector<int>& v){
	multiset<int> ms;
	for (int i = 0; i < v.size(); i++)
		ms.insert(v[i]);
	
	int pos = 0;
	for (multiset<int>::iterator i = ms.begin(); i != ms.end(); i++)
		v[pos++] = *i;
}

class Timer{
	int start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed(){ return ((double)(clock() - start)) / CLOCKS_PER_SEC; }
};

const int STEP = 100000;

int main(){
	srand(time(NULL));

	vector<int> v;
	for (int i = 0; i < STEP; i++)
		v.push_back(rand());
	
	Timer t;
	double elapsed;

	for (int i = 0; i < 10; i++){
		//enlarge the vector
		for (int j = 0; j < STEP; j++)
			v.push_back(rand());
		t.reset();
		sortUsingTree(v);
		elapsed = t.elapsed();
		cout << "v.size()=" << v.size() << "\tElapsed=" << elapsed << endl;
	}
	
}