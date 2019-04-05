/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Basement class.
*******************************************************************************/
#include "Basement.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Basement::Basement()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  
  room_num = 5;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn. 
*******************************************************************************/

void Basement::description()
{
  std::cout << "You enter the room and see a bit of light coming through a chained window." << std::endl;
  std::cout << "The room appears to be a standard residential basement. The wooden staircase leading up to a door has been smashed. There is no way to climb up there." << std::endl;
  std::cout << "However, there is a small ground-level window on the right-side of the room that is just large enough for you to squeeze through." << std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * Basement::room_options(Player * player)
{
  std::cout << "==========================" << std::endl;
  std::cout << "What do you want to do?" << std::endl;
  std::cout << "1. Go Up" << std::endl;
  std::cout << "2. Go Down" << std::endl;
  std::cout << "3. Go Left" << std::endl;
  std::cout << "4. Go Right" << std::endl;
  
  int counter = 1;
  while (true)
  {
    // User makes a choice based on the options presented.
    // If it is the second time around, the options are presented again.
    if (counter > 1)
    {
      std::cout << "Your options:" << std::endl;
      std::cout << "1. Go Up" << std::endl;
      std::cout << "2. Go Down" << std::endl;
      std::cout << "3. Go Left" << std::endl;
      std::cout << "4. Go Right" << std::endl;
    }
    int choice = int_validation_range(4);
    
    switch (choice)
    {
      case 1:
        // Change current room to the room that the up pointer points to.
        std::cout << "A long workbench lines the northern wall. There is a series of tools strewn about in a messy fashion." << std::endl;
        
        // If player already has the flashlight but no battery, they'll be looking for a battery.
        if (player->search_inventory("flashlight") && !player->search_inventory("battery") )
        {
          std::cout << "There are also a few batteries in an old shoebox on the bench. You rummage through it. Maybe one fits into your flashlight." << std::endl;
          std::cout << "After testing a few, you find one that fits inside. You flick the switch on the flashlight and it works!" << std::endl;
          player->add_item_to_inventory(new Item("battery"));
        }
        // Otherwise, they don't think a battery would be useful and they continue on.
        else
        {
          std::cout << "Doesn't looks like there is anything useful here." << std::endl;
        }
        break;
      case 2:
        // Change current room to the room that the up pointer points to.
        std::cout << "You walk through the door to the south" << std::endl;
        return down;
        break;
      case 3:
        // Change current room to the room that the up pointer points to.
        std::cout << "A large cistern sits on the west side of the room. It is old and rusty and has not been used in a while." << std::endl;
        std::cout << "Some of the metal is flaking off the exterior." << std::endl;
        std::cout << "There is no door on this side of the room." << std::endl;
        break;
      case 4:
        // Change current room to the room that the up pointer points to.
        std::cout << "The light coming form the window is bright. It appears to be early morning." << std::endl;
        std::cout << "You try to slide it open but notice that it is chained shut. The chain is secured with a single padlock with a keyhole." << std::endl;
        
        // If player has key, they can unlock and escape.
        if (player->search_inventory("key") )
        {
          std::cout << "You use the key on the padlock. It fits into the lock. You turn it and..." << std::endl;
          std::cout << "...it works! The lock opens and you are able to remove the chain from the window. You open the window and squeeze through." << std::endl;
          return right;
        }
        
        std::cout << "If you were to remove the chain, you would be able to get through the window to safety." << std::endl;
        break;
      default:
        std::cout << "error in room_options" << std::endl;
        break;
    }
    counter++;
  }
}

/*******************************************************************************
** Function Name: set_up
** Description: Sets the 'up' pointer of this room to another room object.
*******************************************************************************/

void Basement::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void Basement::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void Basement::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void Basement::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int Basement::get_room_num()
{
  return room_num;
}






