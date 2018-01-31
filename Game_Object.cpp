#include "Game_Object.h"
#include <iostream>

using namespace std;

Game_Object::Game_Object(char in_code) {//first game_object constructor
    //initialize variables
    display_code=in_code;
    id_num=1;
    state='s';
    cout<<"Game_Object constructed."<<endl;
}

Game_Object::Game_Object(const Cart_Point& in_loc, int in_id, char in_code) {//other game_object constructor
    //initialize variables
    display_code=in_code;
    id_num=in_id;
    location=in_loc;
    state='s';
    cout<<"Game_Object constructed."<<endl;
}

Game_Object::~Game_Object() {//game_object destructor
    cout<<"Game_Object destructed."<<endl;
}

Cart_Point Game_Object::get_location() const {//return location
    return location;
}

int Game_Object::get_id() const {//return id_num
    return id_num;
}

char Game_Object::get_state() const {//return state
    return state;
}

void Game_Object::show_status() {//return the loction of an object
    cout<<display_code<<id_num<<" at "<<location;
}

void Game_Object::drawself(char * ptr) {//set up object for view
    ptr[0]=display_code;
    ptr[1]='0'+id_num;
}

bool Game_Object::is_alive() {//check if game_object is alive
    return true;
}
