#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Model.h"

using namespace std;
//game_command protoypes
void do_move_command(Model* model,int astro_id, Cart_Point loc);
void do_work_a_depot_command(Model* model,int astro_id,int depot_id);
void do_deposit_moon_stones_command(Model* model,int astro_id,int station_id);
void do_stop_command(Model* model,int astro_id);
void do_lock_in_at_station_command(Model* model,int astro_id,int station_id);
void do_go_command(Model* model);
void do_run_command(Model* model);
void do_quit_command(Model* model);
void do_attack_command(Model* model,int alien_id, int astro_id);

#endif
