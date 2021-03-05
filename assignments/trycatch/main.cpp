#include <iostream>
#include <vector>
using namespace std;
int main() {
  try {
        cout << "Creating a vector of size 5... \n";
        vector<int> v(5);
        cout << "Accessing the 11th element of the vector...\n";
        cout << v.at(10); // vector::at() throws std::out_of_range
    } catch (const exception& e) { // caught by reference to base
        cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
    }
}
