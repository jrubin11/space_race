#include "Oxygen_Depot.h"

using namespace std;

Oxygen_Depot::Oxygen_Depot(): Game_Object('O') {//default constructor
    //initialize variables
    amount_oxygen=50;
    display_code='O';
    state='f';
    cout<<"Oxygen_Depot default constructed."<<endl;
}

Oxygen_Depot::Oxygen_Depot(const Cart_Point& inputLoc, int inputId): Game_Object(inputLoc, inputId, 'O') {//other constructor
    //initialize variables
    id_num=inputId;
    location=inputLoc;
    amount_oxygen=50;
    display_code='O';
    state='f';
    cout<<"Oxygen_Depot constructed."<<endl;
}

Oxygen_Depot::~Oxygen_Depot() {//oxygen_depot destructor
    cout<<"Oxygen_Depot destructed."<<endl;
}

bool Oxygen_Depot::is_empty() const {//check if empty function
    if (amount_oxygen<=0) {//if empty return true
        return true;
    } else {//else return false
        return false;
    }
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract) {//extract oxygen function
    if (amount_oxygen>=amount_to_extract) {//extract 20 oxygen if amount is grater than 20
        amount_oxygen-=amount_to_extract;
        return amount_to_extract;
    } else {//extract all oxygen and make oxygen equal zero
        double temp=amount_oxygen;
        amount_oxygen=0;
        return temp;
    }
}

bool Oxygen_Depot::update() {//update function
    if (amount_oxygen<=0 && state!='e') {//if empty but not yet changed
        state='e';
        display_code='o';
        cout<<"Oxygen_Depot "<<id_num<<" has been depleted."<<endl;
        return true;//return true if state changed
    } else {
        return false;//else return false
    }
}

void Oxygen_Depot::show_status() {//show status
    cout<<"Oxygen Depot status: "<<display_code<<id_num<<" at location "<<location<<" contains "<<amount_oxygen<<"."<<endl;
}
