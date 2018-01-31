#ifndef ALIEN_H
#define ALIEN_H
#include "Astronaut.h"

using namespace std;
//astronaut class initialization
class Alien: public Game_Object
{
public:
    //constructors and destructors
    Alien();
    Alien(int in_id, const Cart_Point& in_loc);
    ~Alien();
    
    //public member functions
    void start_attack(Person* in_target);
    bool update();
    void show_status();
    void start_moving(const Cart_Point& dest);
    void stop();
    void setup_destination(const Cart_Point& dest);
    bool update_location();
    
private:
    //private member variables
    int attack_strength;
    double range;
    Person* target;
    double speed;
    Cart_Point destination;
    Cart_Vector delta;
};

#endif

