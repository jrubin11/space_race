#include "Astronaut.h"

using namespace std;

Astronaut::Astronaut(): Person('A') {//default constructor
    //initialize astronaut variables
    amount_moonstones=0;
    amount_oxygen=20;
    depot=NULL;
    home=NULL;
    cout<<"Astronaut default constructed."<<endl;
}

Astronaut::Astronaut(int in_id, const Cart_Point& in_loc): Person(in_loc,in_id,'A') {//other astronaut constructor
    //initialize astronaut variables
    amount_moonstones=0;
    amount_oxygen=20;
    depot=NULL;
    home=NULL;
    cout<<"Astronaut constructed."<<endl;
}

Astronaut::~Astronaut() {//astronaut destructor
    cout<<"Astronaut destructed."<<endl;
}

bool Astronaut::update() {//astronaut update function
    if (health<3 && display_code=='A') {
        display_code='a';
    }
    switch (state) {//swtich statement depending on state
        case 's': {//keep state when state is s
            state='s';
            break;
        }
        case 'm': {
            if (amount_oxygen<=0) {//cant move when equal to or less than zero oxygen
                break;
            } else if (Person::update_location()) {//if astronaut gets to location
                state='s';
                return true;//return true because "something happened"
            } else {//keep moving is not at location
                state='m';
            }
            break;
        }
        case 'o': {
            if (Person::update_location()) {//if astronaut gets to location
                state='g';
                return true;//return true because "something happened"
            } else {//otherwise stay in same state
                state='o';
            }
            break;
        }
        case 'g': {
            double oxygen=depot->extract_oxygen();//take oxygen from depot
            amount_oxygen+=oxygen;//add it to astronauts oxygen
            cout<<display_code<<id_num<<": Got "<<oxygen<<" oxygen."<<endl;
            state='s';//change state to stopped
            return true;//return true because "something happened"
        }
        case 'i': {
            if (Person::update_location()) {//if astronaut gets to location
                state='d';//change state to deposit
                return true;//return true because "something happened"
            } else {
                state='i';//otherwise stay in same state
            }
            break;
        }
        case 'd': {
            cout<<display_code<<id_num<<": Deposit "<<amount_moonstones<<" moonstones."<<endl;
            home->deposit_moonstones(amount_moonstones);//deposit moonstones at station
            amount_moonstones=0;//reset amount of moonstones
            state='s';//stop astronaut
            return true;//return true because "something happened"
        }
        case 'l': {
            if (amount_oxygen<=0) {//cant move when astronaut has no oxygen
                cout<<"I can't move, I'm out of oxygen."<<endl;
            } else if (Person::update_location()) {//if astronaut gets to location
                home->add_astronaut();
            }
            return true;//return true because "something happened"
        }
        case 'x': {
            return false;
        }
        default://default statement
            break;
    }
    if (state=='m'||state=='o'||state=='i'||state=='l') {//if object is moving
        if (amount_oxygen>0) {//only if the astronaut has oxygen can it lose oxygen and pick up moonstones
            amount_moonstones++;//add a moonstone
            amount_oxygen--;//reduce oxygen by one
        }
        if (amount_oxygen<=0) {//is oxygen goes to 0 change state to dead
            if (state!='x') {
                state='x';
                return true;
            }
        }
    }
    return false;//return false if "nothing happened"
}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot) {//supply function
    if (state=='x') {//if you have no oxygen youcant move
        cout<<"I can't move, I'm dead."<<endl;
        return;
    }
    depot=inputDepot;
    Person::setup_destination(depot->get_location());//setup destination for astronaut
    state='o';//change the state
    cout<<"Astronaut "<<id_num<<" supplying from Oxygen Depot "<<inputDepot->get_id()<<".\n"<<display_code<<id_num<<": ";
    if (get_location().x==depot->get_location().x && get_location().y==depot->get_location().y) {//if already there
        state='g';
    } else {//else start moving towards depot
        cout<<"Yes, my lord."<<endl;
        Person::setup_destination(depot->get_location());
    }
}

void Astronaut::start_depositing(Space_Station* inputStation) {//deposit function
    if (state=='x') {//if you have no oxygen youcant move
        cout<<"I can't move, I'm dead."<<endl;
        return;
    }
    home=inputStation;
    Person::setup_destination(home->get_location());//setup destination for astronaut
    state='i';//change the state
    cout<<"Astronaut "<<id_num<<" depositing to Space Station "<<inputStation->get_id()<<".\n"<<display_code<<id_num<<": ";
    if (get_location().x==home->get_location().x && get_location().y==home->get_location().y) {//if already there
        state='d';
    } else {//else start moving towards station
        cout<<"Yes, my lord."<<endl;
        Person::setup_destination(home->get_location());
    }
}

void Astronaut::go_to_station(Space_Station* inputStation) {//locking function
    if (state=='x') {//if you have no oxygen youcant move
        cout<<"I can't move, I'm dead."<<endl;
        return;
    }
    home=inputStation;
    state='l';//change the state
    cout<<"Astronaut "<<id_num<<" locking in at Space Station "<<home->get_id()<<"."<<endl;
    if (get_location().x==home->get_location().x && get_location().y==home->get_location().y) {//if already there
        cout<<display_code<<id_num<<": I'm already there. See?"<<endl;
    } else {
        Person::setup_destination(home->get_location());//setup destination for astronaut
    }
}

void Astronaut::show_status() {//astronaut status function
    cout<<"Astronaut status: ";
    Person::show_status();//run person show status function first
    switch (state) {//switch statement based on state
        case 's'://for stopping state
            cout<<" with "<<amount_oxygen<<" oxygen and "<<amount_moonstones<<" moon stones."<<endl;
            break;
        case 'm'://for moving state
            cout<<endl;
            break;
        case 'o'://for heading to a depot
            cout<<" is outbound to a Depot with "<<amount_oxygen<<" oxygen and "<<amount_moonstones<<" moon stones."<<endl;
            break;
        case 'g'://for getting oxygen from depot
            cout<<" getting oxygen from Depot."<<endl;
            break;
        case 'i'://for heading to station
            cout<< " is inbound to home with load: "<<amount_moonstones<<" moon stones and "<<amount_oxygen<<" oxygen."<<endl;
            break;
        case 'd'://for depositing moonstones
            cout<<" is depositing "<<amount_moonstones<<" moon stones."<<endl;
            break;
        case 'l'://for locked state
            cout<<" is locked at Space Station."<<endl;
            break;
        case 'x':
            cout<<endl;
        default://default case
            break;
    }
}
