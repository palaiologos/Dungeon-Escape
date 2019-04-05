/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Game class.
*******************************************************************************/
#include "Player.hpp"
#include "Starting_Room.hpp"
#include "Jail_Room.hpp"
#include "The_Pit.hpp"
#include "Kitchen.hpp"
#include "Basement.hpp"
#include "Outside.hpp"


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
  private:
    Player *player;
    Space  *current_room,
           *starting_room,
           *jail_room,
           *the_pit,
           *kitchen,
           *basement,
           *outside;
  public:
    Game();
    ~Game();
    void main_menu();
    void print_map(Space *);
};

#endif