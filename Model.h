#ifndef MODEL_H
#define MODEL_H
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Astronaut.h"
#include "View.h"
#include "Alien.h"
#include <list>
#include "Input_Handling.h"

using namespace std;
//model class initialization
class Model
{
private:
    //private member variables
    int time;
    int count_down;
    list <Game_Object*> object_ptrs;
    list <Person*> person_ptrs;
    list <Oxygen_Depot*> depot_ptrs;
    list <Space_Station*> station_ptrs;
    list <Alien*> alien_ptrs;
    list <Game_Object*> active_ptrs;
    

public:
    //consturctor and destructor
    Model();
    ~Model();
    
    //public member functions
    Alien* get_Alien_ptr(int id);
    Person* get_Person_ptr(int id);
    Oxygen_Depot* get_Oxygen_Depot_ptr(int id);
    Space_Station* get_Space_Station_ptr(int id);
    bool update();
    void display(View* view);
    void show_status();
    void handle_new_command();
};
#endif
