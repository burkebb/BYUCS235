#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = {};
	for (unsigned int i = 0; i < 1000000; ++i){
		v.insert(v.begin(),i);
	}
	return 0;
}