#ifndef CART_POINT_H
#define CART_POINT_H
#include "Cart_Vector.h"
#include <iostream>

using namespace std;
//cart_point class class initialization
class Cart_Point
{
public:
    //public member variables
    double x;
    double y;
    
    //constructors
    Cart_Point();
    Cart_Point(double inputx, double inputy);
    
    //friend overloaded operator
    friend ostream& operator<<(ostream& out, const Cart_Point& cart);
};
//non-member functions including overloaded operators
double cart_distance(const Cart_Point& p1, const Cart_Point& p2);
Cart_Point operator+(const Cart_Point& p1, const Cart_Vector& v1);
Cart_Vector operator-(const Cart_Point& p1, const Cart_Point& p2);

#endif
