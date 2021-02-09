#include <iostream>
using namespace std;
int main()
{
  int *badptr = new int[10];
  delete [] badptr;
    //char *badptr = 0;
    //*badptr = 0;
    cout << "everything wokred\n";
}

//g++ -g -std=c++11 seg.cpp -o seg
// valgrind ./seg