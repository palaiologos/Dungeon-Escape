/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for The_Pit class.
*******************************************************************************/
#include "The_Pit.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

The_Pit::The_Pit()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  
  room_num = 3;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn. 
*******************************************************************************/

void The_Pit::description()
{
  std::cout << "A large hole in the ground takes up most of the room." << std::endl;
  std::cout << "You cannot see further than a few feet down as it appears to be dug through the floor into the ground and there is almost no light." << std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * The_Pit::room_options(Player * player)
{
  std::cout << "==========================" << std::endl;
  std::cout << "What do you want to do?" << std::endl;
  std::cout << "1. Go Up" << std::endl;
  std::cout << "2. Go Down" << std::endl;
  std::cout << "3. Go Left" << std::endl;
  std::cout << "4. Go Right" << std::endl;
  std::cout << "5. Examine the hole" << std::endl;
  
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
      std::cout << "5. Examine the hole" << std::endl;
    }
    int choice = int_validation_range(5);
    
    switch (choice)
    {
      case 1:
        // Up.
        std::cout << "The northern wall is an unremarkable, stone surface. It is covered in grime and dirt." << std::endl;
        break;
      case 2:
        // Down.
        std::cout << "There southern end of the room has a large pile of dirt and a shovel leaning against the wall." << std::endl;
        break;
      case 3:
        // Left.
        std::cout << "" << std::endl;
        return left;
        break;
      case 4:
        // Right.
        std::cout << "There is no door on this side of the room." << std::endl;
        std::cout << "Can't go that way" << std::endl;
        break;
      case 5:
        // The Pit.
        std::cout << "You peer into the blackness of the large hole. It smells like it has been used to bury waste or garbage." << std::endl;
        
        // If player has flashlight AND battery, they can use it to illuminate the pit.
        if (player->search_inventory("flashlight") && player->search_inventory("battery") )
        {
          std::cout << "You shine your flashlight down into the pit. The light doesn't reach the bottom so it must be very deep." << std::endl;
          std::cout << "You notice some scratches in the wall of the pit near the top that look like they were made recently" << std:: endl;
          std::cout << "They make out the shape of a few numeric-looking symbols, although they are quite rough. It looks like... 8... 6... and a 7?" << std::endl;
        }
        
        // Otherwise they can't read the message code.
        std::cout << "You start to feel uneasy as if someone or something is watching you so you back away from the pit." << std::endl;
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

void The_Pit::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void The_Pit::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void The_Pit::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void The_Pit::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int The_Pit::get_room_num()
{
  return room_num;
}






