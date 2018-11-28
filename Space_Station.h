#ifndef SPACE_STATION_H
#define SPACE_STATION_H
#include "Game_Object.h"

using namespace std;
//space_staiton class initialization
class Space_Station: public Game_Object
{
private:
    //private member variables
    double amount_moonstones;
    int number_astronauts;
    
public:
    //constructors and destructors
    Space_Station();
    Space_Station(const Cart_Point& inputLoc, int inputId);
    ~Space_Station();
    
    //public member functions
    void deposit_moonstones(double deposit_amount);
    bool add_astronaut();
    int get_astronauts() const;
    bool update();
    void show_status();
};

#endif
