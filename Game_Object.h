#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;
//game_object class initialization
class Game_Object
{
protected:
    //protected member variables
    Cart_Point location;
    int id_num;
    char display_code;
    char state;
    
public:
    //constructors and destructors
    Game_Object(char in_code);
    Game_Object(const Cart_Point& in_loc, int in_id, char in_code);
    virtual ~Game_Object();//virtual for polymorphism
    
    //public member functions
    Cart_Point get_location() const;
    int get_id() const;
    char get_state() const;
    virtual void show_status();
    virtual bool update() = 0;
    void drawself(char * ptr);
    virtual bool is_alive();
};

#endif
