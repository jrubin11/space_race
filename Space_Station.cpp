#include "Space_Station.h"

using namespace std;

Space_Station::Space_Station(): Game_Object('s') {//deafult constructor
    //initialize variables
    amount_moonstones=0.0;
    number_astronauts=0;
    display_code='s';
    state='o';
    cout<<"Space_Station default constructed."<<endl;
}

Space_Station::Space_Station(const Cart_Point& inputLoc, int inputId): Game_Object(inputLoc, inputId, 's') {//deafult constructor
    //initialize variables
    id_num=inputId;
    location=inputLoc;
    amount_moonstones=0.0;
    number_astronauts=0;
    display_code='s';
    state='o';
    cout<<"Space_Station constructed."<<endl;
}

Space_Station::~Space_Station() {//space_station destructor
    cout<<"Space_Station destructed."<<endl;
}

void Space_Station::deposit_moonstones(double deposit_amount) {//deposit moonstone function
    amount_moonstones+=deposit_amount;//add moonstones
}

bool Space_Station::add_astronaut() {//add astronauts functions
    if (state=='u') {//if its upgraded add the astronaut and return true
        number_astronauts++;
        return true;
    } else {//else return false
        return false;
    }
}

int Space_Station::get_astronauts() const {//get number of astronauts
    return number_astronauts;
}

bool Space_Station::update() {//update function
    if (amount_moonstones>=10 && state!='u') {//if not upgraded yet and has 10 moonstones, upgrade and return true
        state='u';
        display_code='S';
        cout<<display_code<<id_num<<" has been upgraded."<<endl;
        return true;
    } else {//else return false
        return false;
    }
}

void Space_Station::show_status() {//show status function
    cout<<"Space Station status: ";
    Game_Object::show_status();
    cout<<" contains "<<amount_moonstones<<" moon stones and contains "<<number_astronauts<<" astronauts. ";
    if (state=='u') {//if upgraded display its upgraded
        cout<<"Upgraded."<<endl;
    } else {//else deisplay its not
        cout<<"Not yet upgraded."<<endl;
    }
}
