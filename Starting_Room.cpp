/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Starting_Room class.
*******************************************************************************/
#include "Starting_Room.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Starting_Room::Starting_Room()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;

  lockbox_code = 867;
  room_num = 1;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn.
*******************************************************************************/

void Starting_Room::description()
{
  std::cout << "The starting room. This is where you first woke up. It appears to be a run-down public restroom." << std::endl;
  std::cout << "The mirror is cracked and the once-white tile is grimy and discolored. You see three closed doors." << std::endl;
  std::cout << "One going left, one right and one up. The wall to the south is bare." << std::endl;
  std::cout << "Also, you notice a small lockbox near a trash can. It has a small 3-digit number combination lock on it." <<std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * Starting_Room::room_options(Player * player)
{
  std::cout << "==========================" << std::endl;
  std::cout << "Your options:" << std::endl;
  std::cout << "1. Go Up" << std::endl;
  std::cout << "2. Go Down" << std::endl;
  std::cout << "3. Go Left" << std::endl;
  std::cout << "4. Go Right" << std::endl;
  std::cout << "5. Examine lockbox" << std::endl;

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
      std::cout << "5. Examine lockbox" << std::endl;
    }
    int choice = int_validation_range(5);

    switch (choice)
    {
      case 1:
        // Change current room to the room that the up pointer points to.
        return up;
        break;
      case 2:
        // Change current room to the room that the up pointer points to.
        std::cout << "The wall is bare except for a few cracks in the tile here and there. There are also what appear to be scratch marks made by something sharp." << std::endl;
        std::cout << "It emits a musty odor that makes you gag." << std::endl;
        break;
      case 3:
        // Change current room to the room that the up pointer points to.
        return left;
        break;
      case 4:
        // Change current room to the room that the up pointer points to.
        return right;
        break;
      case 5:
        // Check the lockbox

        if (player->search_inventory("key"))
        {
          std::cout << "You already have the key from this box" << std::endl;
        }
        else
        {
          std::cout << "The box is about the size of a football and has 3-digit combination lock holding it shut." << std::endl;
          std::cout << "You feel that something is inside it when you pick it up. You also notice it is chained to the floor, rendering it immobile." << std::endl;
          std::cout << "1. Attempt to open the box." << std::endl;
          std::cout << "2. Put it back down." << std::endl;
          choice = int_validation_range(2);
          if (choice == 1)
          {
            open_lockbox(player);
          }
          else
          {
            std::cout << "You put the box back down." << std::endl;
          }
        }
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

void Starting_Room::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void Starting_Room::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void Starting_Room::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void Starting_Room::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: open_lockbox
** Description: Mini game for guessing the combination of the lockbox code. Not
** making this a while-loop so the player can retry tons of times because then
** they could just brute force the lock and guess it. They need to find it.
*******************************************************************************/

void Starting_Room::open_lockbox(Player *player)
{
  std::cout << "The 3-digit combination lock is currently set to 000. Which combination do you try?" << std::endl;
  int guess = int_validation_range(999);  // Get combination from 001 to 999.

  if (guess == lockbox_code)
  {
    std::cout << "The lock clicks and the box lid opens. Inside you see a rusty copper key. You pocket it." << std::endl;
    // Add key to the inventory.
    player->add_item_to_inventory(new Item("key"));
  }
  else
  {
    std::cout << "The lock doesn't budge." << std::endl;
  }
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int Starting_Room::get_room_num()
{
  return room_num;
}
