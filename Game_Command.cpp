#include <iostream>
#include "Game_Command.h"

using namespace std;

void do_move_command(Model* model,int astro_id, Cart_Point loc) {//move command
    char choice;
    cout<<"Move Astronaut (enter 'a') or Alien (enter 'x'): ";
    cin>>choice;
    if (choice!='a' && choice!='x') {
        throw Invalid_Input("Was expecting an 'a' or an 'x'");
    }
    if (choice=='a') {
        Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
            if (ptr_person==0) {
                throw Invalid_Input("Not a valid person id");
            }
        if (ptr_person->get_state()=='l') {//if youre locked you can't move
            cout<<'A'<<astro_id<<": I'm locked and can't move!"<<endl;
            return;
        } else {
            ptr_person->start_moving(loc);//start moving person to the location
            return;
        }
    } else if (choice=='x') {
        Alien* ptr_alien=model->get_Alien_ptr(astro_id);//get the right alien pointer
        if (ptr_alien==0) {
            throw Invalid_Input("Not a valid alien id");
        } else {
            ptr_alien->start_moving(loc);//start moving alien to location
            return;
        }
    }
}


void do_work_a_depot_command(Model* model,int astro_id,int depot_id) {
    Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
    Oxygen_Depot* ptr_depot=model->get_Oxygen_Depot_ptr(depot_id);//get the right depot pointer
    if (ptr_depot==0 || ptr_person==0) {//if person or depot does not exist
        if (ptr_depot==0) {
            throw Invalid_Input("Not a valid depot id");
        } else {
            throw Invalid_Input("Not a valid person id");
        }
    } else if (ptr_person->get_state()=='l') {//if youre locked you can't move
        cout<<'A'<<astro_id<<": I'm locked and can't move!"<<endl;
        return;
    }
    ptr_person->start_supplying(ptr_depot);//start supplying the person to the depot
}

void do_deposit_moon_stones_command(Model* model,int astro_id,int station_id) {
    Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
    Space_Station* ptr_station=model->get_Space_Station_ptr(station_id);//get the right station pointer
    if (ptr_station==0 || ptr_person==0) {//if person or station does not exist
        if (ptr_station==0) {
            throw Invalid_Input("Not a valid station id");
        } else {
            throw Invalid_Input("Not a valid person id");
        }
    } else if (ptr_person->get_state()=='l') {//if youre locked you can't move
        cout<<'A'<<astro_id<<": I'm locked and can't move!"<<endl;
        return;
    }
    ptr_person->start_depositing(ptr_station);//start depositing the moonstones to the station
}

void do_stop_command(Model* model,int astro_id) {
    Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
    if (ptr_person==0) {//if person does not exist
        if (ptr_person==0) {
            throw Invalid_Input("Not a valid station id");
        }
    } else if (ptr_person->get_state()=='l') {//if youre locked you can't move
        cout<<'A'<<astro_id<<": I'm locked and can't move!"<<endl;
        return;
    }
    ptr_person->stop();//stop the person
}

void do_lock_in_at_station_command(Model* model,int astro_id,int station_id) {
    Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
    Space_Station* ptr_station=model->get_Space_Station_ptr(station_id);//get the right station pointer
    if (ptr_station==0 || ptr_person==0) {//if person or station does not exist
        if (ptr_station==0) {
            throw Invalid_Input("Not a valid station id");
        } else {
            throw Invalid_Input("Not a valid person id");
        }
    } else if (ptr_station->get_state()!='u') {//check if the station is upgraded
        cout<<"Astronaut "<<astro_id<<" cannot lock in at Space Station "<<station_id<<" because it is not upgraded."<<endl;
        return;
    } else if (ptr_person->get_state()=='l') {//if youre locked you can't move
        cout<<'A'<<astro_id<<": I'm locked and can't move!"<<endl;
        return;
    }
    ptr_person->go_to_station(ptr_station);//start locking into the station
}

void do_go_command(Model* model) {//go command
    cout<<"Advancing one tick."<<endl;
    model->update();//call update function
}

void do_run_command(Model* model) {//run command
    cout<<"Advancing to next event."<<endl;
    for (int i=0;i<5;i++) {//call upadate function either five times or until it return true
        if (model->update()) {
            break;
        }
    }
}

void do_quit_command(Model* model) {//quit command
    delete model;//delete objects
    exit(1);//quit program
}

void do_attack_command(Model* model,int alien_id,int astro_id) {
    Person* ptr_person=model->get_Person_ptr(astro_id);//get the right person pointer
    Alien* ptr_alien=model->get_Alien_ptr(alien_id);//get the right alien
    if (ptr_person==0 || ptr_alien==0) {//if person does not exist
        if (ptr_person==0) {
            throw Invalid_Input("Not a valid person id");
        } else {
            throw Invalid_Input("Not a valid alien id");
        }
    }
    ptr_alien->start_attack(ptr_person);//start moving person to the location
}
