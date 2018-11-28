#include "Cart_Vector.h"
#include <iostream>

using namespace std;

Cart_Vector::Cart_Vector() {//default constructor
    //initialize variables
    x=0.0;
    y=0.0;
}
    
Cart_Vector::Cart_Vector(double inputx, double inputy) {//other constructor
    //initialize variables
    x=inputx;
    y=inputy;
}

Cart_Vector operator*(const Cart_Vector& v1, double d) {//overload multiplicaiton operator
    double x=v1.x*d;
    double y=v1.y*d;
    return Cart_Vector(x,y);
}

Cart_Vector operator/(const Cart_Vector& v1, double d) {//overload division operator
    if (d==0) {
        return v1;
    }
    double x=v1.x/d;
    double y=v1.y/d;
    return Cart_Vector(x,y);
}

ostream& operator<<(ostream& out, const Cart_Vector& vector) {//overload output operator
    out<<"<"<<vector.x<<","<<vector.y<<">";
    return out;
}

