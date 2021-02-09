#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
	list<string> mystrings;
  int n = 40000; // The number of inserts 
  for(int i = 0; i < n; i++) {
    mystrings.insert(mystrings.end(),"Hello");
  }

	return 0;
}