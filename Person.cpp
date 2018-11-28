#include "Person.h"
#include <math.h>

using namespace std;

Person::Person(): Game_Object('P') {//default constructor
    //initialize variables
    speed=5;
    health=5;
    cout<<"Person default constructed."<<endl;
}

Person::Person(char in_code): Game_Object(in_code) {//other constructor
    //initialize variables
    speed=5;
    health=5;
    state='s';
    display_code=in_code;
    cout<<"Person constructed."<<endl;
}

Person::Person(const Cart_Point& in_loc, int in_id, char in_code): Game_Object(in_loc, in_id, in_code)  {//third constructor
    //initialize variables
    health=5;
    speed=5;
    cout<<"Person constructed."<<endl;
}

Person::~Person() {//person destructor
    cout<<"Person destructed."<<endl;
}

void Person::start_moving(const Cart_Point& dest) {//start moving function
    if (state=='x') {//if you have no oxygen youcant move
        cout<<"I can't move, I'm dead."<<endl;
        return;
    }
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

void Person::stop() {//stop function
    state='s';//change state
    cout<<display_code<<id_num<<": Stopped."<<endl;
}

void Person::show_status() {//show status
    Game_Object::show_status();
    if (state=='s') {//if stopped
        cout<<" stopped";
    } else if (state=='l') {//if locked
        return;
    } else if (state=='x') {//if dead
        cout<<" is dead.";
    } else {//else
        cout<<" is moving at a speed of "<<speed<<" towards "<<destination<<", amounts on each step are "<<delta;
    }
}

bool Person::update_location() {//update locaiton function
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

void Person::setup_destination(const Cart_Point& dest) {//setup destination function
    destination=dest;//make destintation
    delta=(destination-location)*(speed/cart_distance(destination,location));//calculate delta
}

void Person::start_depositing(Space_Station* inputStation) {//start_depositing function
    cout<<"Sorry, I can't work a station."<<endl;
}

void Person::start_supplying(Oxygen_Depot* inputDepot) {//start_supplying function
    cout<<"Sorry, I can't work a depot."<<endl;
}
void Person::go_to_station(Space_Station* inputStation) {//go_to_station function
    cout<<"Sorry, I can't lock into a station."<<endl;
}

bool Person::is_alive() {
    if (state!='x') {
        return true;
    } else {
        return false;
    }
}

void Person::take_hit(int attack_strength) {
    health-=attack_strength;
    if (health<=0) {
        cout<<display_code<<id_num<<": Gasp! I'm dying..."<<endl;
        state='x';
    } else {
        cout<<display_code<<id_num<<": Ouch!"<<endl;
    }
}
