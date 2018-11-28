#include "Alien.h"
#include <math.h>

using namespace std;

Alien::Alien(): Game_Object('X') {//default constructor
    //initialize variables
    attack_strength=2;
    range=2.0;
    target=NULL;
    speed=5;
    cout<<"Alien default constructed."<<endl;
}

Alien::Alien(int in_id, const Cart_Point& in_loc): Game_Object(in_loc, in_id, 'X') {//other constructor
    //initialize variables
    attack_strength=2;
    range=2.0;
    target=NULL;
    speed=5;
    cout<<"Alien constructed."<<endl;
}

Alien::~Alien() {//alien destructor
    cout<<"Alien destructed."<<endl;
}

void Alien::start_attack(Person* in_target) {//attack function
    if (cart_distance(location,in_target->get_location())<=range) {//check if in range
        cout<<display_code<<id_num<<": Smash!"<<endl;
        target=in_target;//if so set as target and change state
        state='a';
    } else {//otherwise display message
        cout<<display_code<<id_num<<": Target is out of range"<<endl;
    }
}

bool Alien::update() {//update function
    switch (state) {//depends on state
        case 's'://stop state
            return false;
        case 'm': {//moving state
            if (Alien::update_location()) {//if alien gets to location
                state='s';
                return true;//return true because "something happened"
            } else {//keep moving is not at location
                state='m';
            }
            break;
        }
        case 'a': {//attacking state
            if (cart_distance(location,target->get_location())<=range) {//check if in range
                if (target->is_alive()) {//if astronaut is alive
                    cout<<display_code<<id_num<<": Take that!"<<endl;
                    target->take_hit(attack_strength);//call take hit function for target and return false
                    return false;
                } else {//if astronaut is dead set state to s and return true
                    cout<<display_code<<id_num<<": I triumph!"<<endl;
                    state='s';
                    return true;
                }
            } else {//if out of range set state to s and return true
                cout<<display_code<<id_num<<": Target is out of range"<<endl;
                state='s';
                return true;
            }
        }
        default:
            break;
    }
    return false;
}

void Alien::show_status() {
    cout<<"Alien status: ";
    Game_Object::show_status();
    if (state=='s') {//if stopped
        cout<<" is stopped"<<endl;
    } else if (state=='a') {//if attacking
        cout<<" is attacking astronaut A"<<target->get_id()<<endl;
    } else {//else
        cout<<" is moving at a speed of "<<speed<<" towards "<<destination<<", amounts on each step are "<<delta<<"."<<endl;
    }
}
void Alien::start_moving(const Cart_Point& dest) {//start moving function
    state='m';//change state
    cout<<"Moving "<<id_num<<" to "<<dest<<"\n"<<display_code<<id_num<<": ";
    if (get_location().x==dest.x && get_location().y==dest.y) {//check if already there
        cout<<"I'm already there. See?"<<endl;
        state='s';
    } else {//else set up destination
        cout<<"On my way."<<endl;
        setup_destination(dest);
    }
}

void Alien::stop() {//stop function
    state='s';//change state
    cout<<display_code<<id_num<<": Stopped"<<endl;
}
    
void Alien::setup_destination(const Cart_Point& dest) {//setup destination function
    destination=dest;//make destintation
    delta=(destination-location)*(speed/cart_distance(destination,location));//calculate delta
}

bool Alien::update_location() {//update location function
    Cart_Point near;
    near.x=fabs(destination.x-location.x);
    near.y=fabs(destination.y-location.y);
    if (location.x==destination.x && location.y==destination.y) {//if already there
        return false;
    } else if (near.x<=fabs(delta.x) && near.y<=fabs(delta.y)) {//if within one step make location destination
        location=destination;
        cout<<display_code<<id_num<<": I'm there!"<<endl;
        return true;
    } else {//else go foward one step
        location=location+delta;
        cout<<display_code<<id_num<<": step..."<<endl;
        return false;
    }
}
