/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Jail_Room class.
*******************************************************************************/
#include "Jail_Room.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Jail_Room::Jail_Room()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  
  room_num = 2;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn. 
*******************************************************************************/

void Jail_Room::description()
{
  std::cout << "There are prison cells lining the walls to your left and right. There doesn't seem to be any furniture in the room save for" << std::endl;
  std::cout << " a small wooden stool sits near the entrance to the room. You also notice a small cylinder-shaped item on the floor of one of the jail cells." << std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * Jail_Room::room_options(Player * player)
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
        // Up.
        std::cout << "The northern wall is at the far end of the jail cells lining the room, but you can make out dark stains and scratches on the wall." << std::endl;
        std::cout << "Looks like this place has not been occupied for a while." << std::endl;
        std::cout << "There is no door on this side of the room." << std::endl;
        std::cout << "Can't go that way" << std::endl;
        break;
      case 2:
        // Down.
        std::cout << "The southern wall is behind another row of jail cells, and too dimly lit to make out any details. The smell is terrible." << std::endl;
        
        // If player does NOT have the flashlight already, get them the flashlight.
        if (!player->search_inventory("flashlight") )
        {
          std::cout << "However, you do notice a small cylinder-shaped object on the floor of a nearby cell." << std::endl;
          std::cout << "You move closer to the bars of the jail cell containing the small object and reach for it." << std::endl;
          std::cout << "It is hard to reach, but you are finally able to grab it. It appears to be a small LED flashlight. You try to turn it on but the batteries are missing. It goes in your pocket." << std::endl;
          player->add_item_to_inventory(new Item("flashlight"));
        }
        // If they already have it, don't go through the same action again.
        else
        {
          std::cout << "There is no door on this side of the room." << std::endl;
          std::cout << "Can't go that way" << std::endl;
        }
        break;
      case 3:
        // Left.
        std::cout << "The ceiling on this end of the room has collapsed, covering most of what used to be a doorway. The rubble is too heavy to move." << std::endl;
        std::cout << "Can't go that way" << std::endl;
        break;
      case 4:
        // Right.
        std::cout << "You go through the door on the right." << std::endl;
        return right;
        break;
      default:
        std::cout << "error in room_options" << std::endl;
        break;
    }
    counter ++;
  }
}

/*******************************************************************************
** Function Name: set_up
** Description: Sets the 'up' pointer of this room to another room object.
*******************************************************************************/

void Jail_Room::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void Jail_Room::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void Jail_Room::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void Jail_Room::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int Jail_Room::get_room_num()
{
  return room_num;
}






