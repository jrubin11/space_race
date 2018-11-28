#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>

using namespace std;
//cart_vector class initialization
class Cart_Vector
{
public:
    //public member variables
    double x;
    double y;
    
    //constructors
    Cart_Vector();
    Cart_Vector(double inputx, double inputy);
    
    //friend overloaded operator
    friend ostream& operator<<(ostream& out, const Cart_Vector& vector);
};
//non-member functions with overloaded operators
Cart_Vector operator*(const Cart_Vector& v1, double d);
Cart_Vector operator/(const Cart_Vector& v1, double d);

#endif
