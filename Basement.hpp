/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Basement class. Inherits from abstract
** class 'Space' and is a room the player can enter.
*******************************************************************************/
#include "Space.hpp"

#ifndef BASEMENT_HPP
#define BASEMENT_HPP

class Basement : public Space
{
  private:
    Space *up,
          *down,
          *left,
          *right;
          
    int room_num;
  public:
    Basement();
    virtual void description();
    virtual Space* room_options(Player *);
    virtual void set_up(Space *);
    virtual void set_down(Space *);
    virtual void set_left(Space *);
    virtual void set_right(Space *);
    virtual int get_room_num();
};

#endif