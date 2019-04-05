/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Player class.
*******************************************************************************/

#include "Item.hpp"
#include <vector>
#include <iostream>


#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
  private:
    std::vector<Item*> inventory;
    int health;
  public:
    Player();
    ~Player();
    int get_health();
    void add_item_to_inventory(Item*);
    void get_inventory();
    void decrease_health(int);
    void increase_health(int);
    bool search_inventory(std::string);
};

#endif