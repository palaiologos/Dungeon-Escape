/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Outside class. Inherits from abstract
** class 'Space' and is a room the player can enter.
*******************************************************************************/
#include "Space.hpp"
#include <cstdlib>

#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

class Outside : public Space
{
  private:
    Space *up,
          *down,
          *left,
          *right;
          
    int room_num;
  public:
    Outside();
    virtual void description();
    virtual Space* room_options(Player *);
    virtual void set_up(Space *);
    virtual void set_down(Space *);
    virtual void set_left(Space *);
    virtual void set_right(Space *);
    virtual int get_room_num();
};

#endif