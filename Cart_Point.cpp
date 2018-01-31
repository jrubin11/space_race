#include "Cart_Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Cart_Point::Cart_Point() {//default constructor
    //initialize variables
    x=0.0;
    y=0.0;
}
    
Cart_Point::Cart_Point(double inputx, double inputy) {//other constructor
    //initialize variables
    x=inputx;
    y=inputy;
}
    
double cart_distance(const Cart_Point& p1, const Cart_Point& p2) {//find distance between two points
    double difx=p1.x-p2.x;
    double dify=p1.y-p2.y;
    double partx=difx*difx;
    double party=dify*dify;
    return sqrt(partx+party);
}

ostream& operator<<(ostream& out, const Cart_Point& cart) {//overload output operator
    out<<"("<<cart.x<<","<<cart.y<<")";
    return out;
}

Cart_Point operator+(const Cart_Point& p1, const Cart_Vector& v1) {//overload addition operator
    double x=p1.x+v1.x;
    double y=p1.y+v1.y;
    return Cart_Point(x,y);
}

Cart_Vector operator-(const Cart_Point& p1, const Cart_Point& p2) {//overload subtraction operator
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return Cart_Vector(x,y);
}
