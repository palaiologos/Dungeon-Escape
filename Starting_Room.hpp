/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Starting_Room class. Inherits from abstract
** class 'Space' and is the room the player starts out in when the game starts.
*******************************************************************************/
#include "Space.hpp"

#ifndef STARTING_ROOM_HPP
#define STARTING_ROOM_HPP

class Starting_Room : public Space
{
  private:
    Space *up,
          *down,
          *left,
          *right;
    int lockbox_code;
    int room_num;
    
  public:
    Starting_Room();
    virtual void description();
    virtual Space* room_options(Player *);
    virtual void set_up(Space *);
    virtual void set_down(Space *);
    virtual void set_left(Space *);
    virtual void set_right(Space *);
    virtual void open_lockbox(Player *);
    virtual int get_room_num();
};

#endif