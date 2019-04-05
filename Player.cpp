/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Player class.
*******************************************************************************/
#include "Player.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Player::Player()
{
  health = 65;
}

/*******************************************************************************
** Function Name: Default Destructor
*******************************************************************************/

Player::~Player(){}

/*******************************************************************************
** Function Name: get_health
** Description: Returns the player's current health.
*******************************************************************************/

int Player::get_health()
{
  return health;
}

/*******************************************************************************
** Function Name: get_inventory
** Description: Returns the player's current inventory.
*******************************************************************************/

void Player::get_inventory()
{
  for (int i = 0; i < inventory.size(); i++)
  {
    std::cout << inventory[i]->get_name() << ", ";
  }
}

/*******************************************************************************
** Function Name: increase_health
** Description: Increases the player's health by a certain amount.
*******************************************************************************/

void Player::increase_health(int change)
{
  health += change;
}

/*******************************************************************************
** Function Name: decrease_health
** Description: Decreases the player's health by a certain amount.
*******************************************************************************/

void Player::decrease_health(int change)
{
  health -= change;
}

/*******************************************************************************
** Function Name: add_item_to_inventory
** Description: Adds an item to the player's inventory vector.
*******************************************************************************/

void Player::add_item_to_inventory(Item * new_item)
{
  inventory.push_back(new_item);
}

/*******************************************************************************
** Function Name: search_inventory
** Description: Searches the player's inventory for an item by name and returns
** true if the item exists in the inventory. False if otherwise.
*******************************************************************************/

bool Player::search_inventory(std::string name)
{
  for (int i = 0; i < inventory.size(); i++)
  {
    if (inventory[i]->get_name() == name)
    {
      return true;
    }
  }
  
  return false;
}


































