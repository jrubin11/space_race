#ifndef VIEW_H
#define VIEW_H
#include "Game_Object.h"

using namespace std;

const int view_maxsize=20;//const value for grid max size
//view class initialization
class View
{
private:
    //private member variables
    int size;
    double scale;
    Cart_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &ix, int &iy, Cart_Point location);
    
public:
    //constructor
    View();
    
    //public memer functions
    void clear();
    void plot(Game_Object * ptr);
    void draw();
    
};

#endif

