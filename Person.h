#ifndef PERSON_H
#define PERSON_H
#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"

using namespace std;
//person class initialization
class Person: public Game_Object
{
public:
    //constructors and destructors
    Person();
    Person(char in_code);
    Person(const Cart_Point& in_loc, int in_id, char in_code);
    virtual ~Person();
    
    //public member functions
    void start_moving(const Cart_Point& dest);
    void stop();
    void show_status();
    virtual void start_depositing(Space_Station* inputStation);
    virtual void start_supplying(Oxygen_Depot* inputDepot);
    virtual void go_to_station(Space_Station* inputStation);
    bool is_alive();
    void take_hit(int attack_strength);
    
protected:
    //protected member functions
    bool update_location();
    void setup_destination(const Cart_Point& dest);
    
    //protected member variables
    int health;
    
private:
    //private member variables
    double speed;
    Cart_Point destination;
    Cart_Vector delta;
};

#endif
