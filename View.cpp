#include "View.h"
#include <iostream>

using namespace std;

bool View::get_subscripts(int &ix, int &iy, Cart_Point location) {//get_subscripts function
    //setup location for grid
    Cart_Vector temp=(location-origin);
    ix=temp.x/scale;
    iy=temp.y/scale;
    if (ix<=view_maxsize/2 && ix>=0 && iy<=view_maxsize/2 && iy>=0) {//check to see if object is in grid and return true
        return true;
    } else {//else return false and say its outside of the display
        cout<<"An object is outside the display."<<endl;
        return false;
    }
}

View::View() {//default destructor
    //intialize variables
    size=11;
    scale=2;
    origin=Cart_Point(0,0);
}

void View::clear() {//clear function
    for (int i=0;i<size;i++) {//make the entire grid into a "clear" state
        for (int j=0;j<view_maxsize;j++) {
            grid[i][j][0]='.';//each element is '. '
            grid[i][j][1]=' ';
        }
    }
}

void View::plot(Game_Object * ptr) {//plot function
    int x,y;
    if (get_subscripts(x,y, ptr->get_location())) {//if in range plot the object on the grid
        if (grid[x][y][0]!='.') {//if object already on spot put '* '
            grid[x][y][0]='*';
            grid[x][y][1]=' ';
        } else {//else plot object
            ptr->drawself(grid[x][y]);
        }
    }
}

void View::draw() {//draw function
    bool skip=false;
    int axis=view_maxsize;
    for (int j=size-1;j>=0;j--) {//to draw grid
        if (!skip) {//for the y axis scale
            if (axis<10) {//if number is less than 10 you need an extra space
                cout<<axis<<" ";
            } else {
                cout<<axis;
            }
        } else {//every other line has a number
            cout<<"  ";
        }
        for (int i=0;i<size;i++) {//print out grid line
            cout<<grid[i][j][0]<<grid[i][j][1];
        }
        if (!skip) {//flip value to make it every other line
            skip=true;
        } else {
            skip=false;
        }
        cout<<endl;
        axis-=scale;//decrease axis by two for each line
    }
    axis+=scale;//get axis back to zero
    cout<<"  ";
    skip=false;
    for (;axis<=view_maxsize;axis+=scale) {//for x axis
        if (!skip) {//for every other column
            if (axis<10) {//if axis is less than 10 you need an extra space
                cout<<axis<<"   ";
            } else {
                cout<<axis<<"  ";
            }
        }
        if (!skip) {//flip value to make it every other line
            skip=true;
        } else {
            skip=false;
        }
    }
    cout<<endl;
}
