// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public:
    Circle(double r) : radius{r} { }
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : height(h) ,base{r} {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder foo (10,20);

  cout << "foo's volume: " << foo.volume() << '\n';
  return 0;
}

//int a {5}; use instead of () for initializing objects, because {} won't be confused with function decl like int a() or int a(int b), and because you can call default constructors by leaving them blank.
//plus you must use initialization if the class has a member of another class that has only non-default constructor
//prefer unifrom initiailization, meaing radius{r} instead of (r)