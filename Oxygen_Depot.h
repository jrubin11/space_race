#ifndef OXYGEN_DEPOT_H
#define OXYGEN_DEPOT_H
#include "Game_Object.h"

using namespace std;
//oxygen_depot class initialization
class Oxygen_Depot: public Game_Object
{
private:
    //private member variables
    double amount_oxygen;
    
public:
    //constructors and destructor
    Oxygen_Depot();
    Oxygen_Depot(const Cart_Point& inputLoc, int inputId);
    ~Oxygen_Depot();
    
    //public member variables
    bool is_empty() const ;
    double extract_oxygen(double amount_to_extract = 20.0);
    bool update();
    void show_status();
};

#endif
