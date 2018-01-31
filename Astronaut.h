#ifndef ASTRONAUT_H
#define ASTRONAUT_H
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"

using namespace std;
//astronaut class initialization
class Astronaut: public Person
{
public:
    //constructors and destructors
    Astronaut();
    Astronaut(int in_id, const Cart_Point& in_loc);
    ~Astronaut();
    
    //public member functions
    bool update();
    void start_supplying(Oxygen_Depot* inputDepot);
    void start_depositing(Space_Station* inputStation);
    void go_to_station(Space_Station* inputStation);
    void show_status();
    
private:
    //private member variables
    double amount_moonstones;
    double amount_oxygen;
    Oxygen_Depot* depot;
    Space_Station* home;
};

#endif
