#include <iostream>
using namespace std;

int main(void) {
	/*
	int *array = new int[2];
	array[0] = 1;
	// don't understand why we don't use *array[0] = 1
	cout << array[0] << endl;
	
	delete [] array;
	*/
	/* 
	// doesn't work
	int *a;
	*a = 3;
	cout << a << " " << *a << endl;
	
	*/
	/*
	int *a = new int{5};
	int *b;
	int num = 6;
	b = &num;
	cout << a << " " << *a << endl;
	cout << b << " " << *b << endl;

	delete a;
	cout << a << " " << *a << endl;

	delete b;
	cout << b << " " << *b << endl;
	cout << "num: " << num << endl;
	// for some reason i can delete and still use a but not b! what is happening?
	*/
	return 0;
}