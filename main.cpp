#include <iostream>
#include "Astronaut.h"
#include "Game_Command.h"
#include "View.h"

using namespace std;

void initialize();//prototype of initialize
char get_char();
int get_int();


int main() {
    
    //input variables
    char command_code;
    int astro_id;
    int station_id;
    int depot_id;
    int alien_id;
    int x,y;
    Cart_Point loc;
    char check;
    char temp;
    
    //initialization and show game starting status
    initialize();
    Model* model=new Model;//create new model object
    View* view=new View;//create new view object
    model->show_status();//show starting status
    model->display(view);//show starting view

    while (true) {//infinite loop to run game until won, lost, or quit
        cout<<"Enter command: ";//ask for game command
        try {
            //command_code=get_char();//take in the game command
            switch (get_char()) {//switch statement determines what to do
                case 'm'://for moving command
                    //take in other inputs
                    astro_id=get_int();
                    x=get_int();
                    y=get_int();
                    loc=Cart_Point(x,y);//create a Cart_Point for location
                    do_move_command(model, astro_id, loc);//run move command
                    model->display(view);//show view
                    break;
                case 'w'://for supplying command
                    //take in other inputs
                    astro_id=get_int();
                    depot_id=get_int();
                    do_work_a_depot_command(model, astro_id, depot_id);//run supply command
                    model->display(view);//show view
                    break;
                case 'd'://for depositing command
                    //take in other inputs
                    astro_id=get_int();
                    station_id=get_int();
                    do_deposit_moon_stones_command(model, astro_id, station_id);//run deposit command
                    model->display(view);//show view
                    break;
                case 's'://for stopping command
                    //take in other inputs
                    astro_id=get_int();
                    do_stop_command(model, astro_id);//run stop command
                    model->display(view);//show view
                    break;
                case 'l'://for locking command
                    //take in other inputs
                    astro_id=get_int();
                    station_id=get_int();
                    do_lock_in_at_station_command(model, astro_id, station_id);//run locking command
                    model->display(view);//show view
                    break;
                case 'g'://go foward one time step command
                    do_go_command(model);//run go command
                    model->show_status();//show status
                    model->display(view);//show view
                    break;
                case 'r'://for run command
                    do_run_command(model);//run run command
                    model->show_status();//show status
                    model->display(view);//show view
                    break;
                case 'q'://for quit command
                    do_quit_command(model);//run quit command
                    model->display(view);//show view
                    break;
                case 'a'://for attack command
                    //take in other inputs
                    alien_id=get_int();
                    astro_id=get_int();
                    do_attack_command(model,alien_id,astro_id);
                    model->display(view);//show view
                    break;
                case 'n'://for attack command
                    model->handle_new_command();
                    model->display(view);//show view
                    break;
                default://if invalid input
                    throw Invalid_Input("invalid command code");
                    break;
            }
        }
        catch (Invalid_Input& except){//exception catch
            cin.clear();
            cout<<"Invalid input - "<<except.msg_ptr<<endl;
        }
    }
    
    return 0;
}

void initialize() {//for initialization heading
    cout<<"EC327: Introduction to Software Engineering\nFall 2017\nProgramming Assignment 3"<<endl;
}

int get_int(){
    int i;
    cin>>i;
    if(cin.fail()) // do the input, then check: is stream good?
        throw Invalid_Input("Was expecting an integer"); // throw an exception for not an int
    return i;
}

char get_char(){
    char i;
    cin>>i;
    if(cin.fail()) // do the input, then check: is stream good?
        throw Invalid_Input("Was expecting a character"); // throw an exception for not a char
    return i;
}

char get_double(){
    double i;
    cin>>i;
    if(cin.fail()) // do the input, then check: is stream good?
        throw Invalid_Input("Was expecting a double"); // throw an exception for not a double
    return i;
}
