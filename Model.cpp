#include "Model.h"
#include <iostream>

using namespace std;

Model::Model() {//default constructor
    //initialize variables
    time=0;
    count_down=10;
    Cart_Point cart1(5,1);
    Cart_Point cart2(10,1);
    Astronaut* a1=new Astronaut(1,cart1);
    Astronaut* a2=new Astronaut(2,cart2);
    object_ptrs.push_back(a1);
    object_ptrs.push_back(a2);
    active_ptrs.push_back(a1);
    active_ptrs.push_back(a2);
    person_ptrs.push_back(a1);
    person_ptrs.push_back(a2);
    Cart_Point cart3(1,20);
    Cart_Point cart4(10,20);
    Oxygen_Depot* o1=new Oxygen_Depot(cart3,1);
    Oxygen_Depot* o2=new Oxygen_Depot(cart4,2);
    object_ptrs.push_back(o1);
    object_ptrs.push_back(o2);
    active_ptrs.push_back(o1);
    active_ptrs.push_back(o2);
    depot_ptrs.push_back(o1);
    depot_ptrs.push_back(o2);
    Cart_Point cart5(5,5);
    Space_Station* s1=new Space_Station();
    Space_Station* s2=new Space_Station(cart5,2);
    object_ptrs.push_back(s1);
    object_ptrs.push_back(s2);
    active_ptrs.push_back(s1);
    active_ptrs.push_back(s2);
    station_ptrs.push_back(s1);
    station_ptrs.push_back(s2);
    Cart_Point cart6(7,14);
    Cart_Point cart7(7,5);
    Alien* al1=new Alien(1,cart6);
    Alien* al2=new Alien(2,cart7);
    object_ptrs.push_back(al1);
    object_ptrs.push_back(al2);
    active_ptrs.push_back(al1);
    active_ptrs.push_back(al2);
    alien_ptrs.push_back(al1);
    alien_ptrs.push_back(al2);
    cout<<"Model default constructed."<<endl;
}

Model::~Model() {//model destructor
    for (list<Game_Object*>::iterator it=object_ptrs.begin();it != object_ptrs.end(); ++it) {//delete all objects
        delete (*it);
    }
    cout<<"Model destructed."<<endl;
}

Person* Model::get_Person_ptr(int id) {//get the ptr for the person id
    for (list<Person*>::iterator it=person_ptrs.begin();it != person_ptrs.end(); ++it) {//go through all objects
        if ((*it)->get_id()==id) {//if correct pointer
            return (*it);//return the pointer
        }
    }
    return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id) {
    for (list<Oxygen_Depot*>::iterator it=depot_ptrs.begin();it != depot_ptrs.end(); ++it) {//go through all objects
        if ((*it)->get_id()==id) {//if correct pointer
            return (*it);//return the pointer
        }
    }
    return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id) {
    for (list<Space_Station*>::iterator it=station_ptrs.begin();it != station_ptrs.end(); ++it) {//go through all objects
        if ((*it)->get_id()==id) {//if correct pointer
            return (*it);//return the pointer
        }
    }
    return 0;
}

Alien* Model::get_Alien_ptr(int id) {
    for (list<Alien*>::iterator it=alien_ptrs.begin();it != alien_ptrs.end(); ++it) {//go through all objects
        if ((*it)->get_id()==id) {//if correct pointer
            return (*it);//return the pointer
        }
    }
    return 0;
}

bool Model::update() {
    time++;//incrament time
    //initialize variables for function
    bool check=false;
    bool upgrade_check=true;
    bool countdown=false;
    int astronauts=0;
    int dead=0;
    
    for (list<Space_Station*>::iterator it=station_ptrs.begin();it != station_ptrs.end(); ++it) {//go through all objects
        if (((*it))->get_state()!='u') {//if stations are upgraded
            upgrade_check=false;//not ready for take off
        }
    }
    if (upgrade_check) {
        if (count_down==0) {//if countdown 0 you lose the game
            cout<<"Unmanned takeoff... You lose!"<<endl;
            exit(1);//exit program
        }
        cout<<"Ready for takeoff? "<<count_down<<"..."<<endl;
        for (list<Space_Station*>::iterator it=station_ptrs.begin();it != station_ptrs.end(); ++it) {//go through all objects
            if ((*it)->get_astronauts()==0) {//check to see if a space station is missing an astronaut
                astronauts++;//counts how many are missing
                countdown=true;//start countdown
            }
        }
        if (astronauts!=0) {//check to see if astronauts are missing
            cout<<"Missing "<<astronauts<<" astronauts!"<<endl;
        }
    }
    if (countdown || !upgrade_check) {//updates all objects if countdown or not all space stations are upgraded
        for (list<Game_Object*>::iterator it=active_ptrs.begin();it != active_ptrs.end(); ++it) {//go through all objects
            if ((*it)->update()) {//update object
                check=true;//make check true since "something happened"
            }
        }
        for (list<Game_Object*>::iterator it=active_ptrs.begin();it != active_ptrs.end(); ++it) {
            if ((*it)!=0) {//to check for empty space since an object could be deleted
                Person* p = dynamic_cast<Person*>(*it);
                if (p!=NULL) {
                    if ((*it)->is_alive()==false) {
                        active_ptrs.remove(*it);
                    }
                }
            } else {
                break;
            }
        }
        if (countdown) {//if countdown is true minus one from countdown
            count_down--;
        }
    } else {//else you win the game
        cout<<"Blast off! You win!"<<endl;
        exit(1);//quit program
    }
    return check;//return whether "something happened" or not
}

void Model::display(View* view) {//view function
    view->clear();//clear display
    for (list<Game_Object*>::iterator it=active_ptrs.begin();it != active_ptrs.end(); ++it) {//go through all objects
        view->plot((*it));//plot the object
    }
    view->draw();//draw the display
}

void Model::show_status() {//show status function
    cout<<"Time: "<<time<<endl;//show time
    for (list<Game_Object*>::iterator it=object_ptrs.begin();it != object_ptrs.end(); ++it) {//go through all objects
        (*it)->show_status();//show object status
    }
}

void Model::handle_new_command() {//new object function
    char type;
    int id_num,x,y;
    cin>>type>>id_num>>x>>y;
    Cart_Point cart(x,y);
    switch(type) {
        case 'd': {//for new depot object
            if (get_Oxygen_Depot_ptr(id_num)!=0) {
                throw Invalid_Input("id number already taken for this object");
            }
            Oxygen_Depot* o=new Oxygen_Depot(cart,id_num);
            //add to lists
            object_ptrs.push_back(o);
            active_ptrs.push_back(o);
            depot_ptrs.push_back(o);
            break;
        }
        case 's': {//for new station object
            if (get_Space_Station_ptr(id_num)!=0) {
                throw Invalid_Input("id number already taken for this object");
            }
            Space_Station* s=new Space_Station(cart,id_num);
            //add to lists
            object_ptrs.push_back(s);
            active_ptrs.push_back(s);
            station_ptrs.push_back(s);
            break;
        }
        case 'a': {//for new astro object
            if (get_Person_ptr(id_num)!=0) {
                throw Invalid_Input("id number already taken for this object");
            }
            Astronaut* a=new Astronaut(id_num,cart);
            //add to lists
            object_ptrs.push_back(a);
            active_ptrs.push_back(a);
            person_ptrs.push_back(a);
            break;
        }
        case 'x': {//for new alien object
            if (get_Alien_ptr(id_num)!=0) {
                throw Invalid_Input("id number already taken for this object");
            }
            Alien* al=new Alien(id_num,cart);
            //add to lists
            object_ptrs.push_back(al);
            active_ptrs.push_back(al);
            alien_ptrs.push_back(al);
            break;
        }
        default://else
            throw Invalid_Input("invalid object type");
            break;
    }
}

