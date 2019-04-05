/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for abstract space class.
*******************************************************************************/
#include <iostream>

#include "Helper_Functions.hpp"
#include "Player.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
  private:
    Space *up,
          *down,
          *left,
          *right;
    int room_num;
  public:
    Space();
    virtual ~Space();
    virtual void description() = 0;
    virtual Space * room_options(Player *) = 0; // Passing player object for adding inventory items.
    virtual void set_up(Space *) = 0;
    virtual void set_down(Space *) = 0;
    virtual void set_left(Space *) = 0;
    virtual void set_right(Space *) = 0;
    virtual int get_room_num() = 0;
};

#endif