/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Outside class.
*******************************************************************************/
#include "Outside.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Outside::Outside()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  
  room_num = 6;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn. 
*******************************************************************************/

void Outside::description()
{
  std::cout << "You clim through the window and find yourself outside of the house. It is early morning and you feel a slight breeze." << std::endl;
  std::cout << "You see a dirt road leading off to the north that looks overgrown with grass. To the east is nothing but trees." << std::endl;
  std::cout << "You turn to the south and see a small footpath leading into the forest. To the west is the house you just escaped from." << std::endl;
  std::cout << "You hear a a door slam open somewhere inside the house and angry, muffled yelling. It appears your escape has been discovered." << std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * Outside::room_options(Player * player)
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
        std::cout << "You start running down the dirt road as fast as you can. About 30 seconds later you hear an engine start upbehind you and the crunch of gravel." << std::endl;
        std::cout << "A car appears around a bend in the road behind you and barrels into you before you can even think of dodging it." << std::endl;
        std::cout << "You hear a loud crunch and the world fades to black." << std::endl;
        std::cout << "Game Over" << std::endl;
        std::exit(0);
        break;
      case 2:
        // Down.
        std::cout << "You dash for the trail into the woods. You trip over several large branches on the ground in your haste. You think you have gotten far enough away when you hear the barking of a dog behind you." << std::endl;
        std::cout << "You turn to look behind you and blunder into a bear trap on the trail. It clenches your leg tight in its grip and you are unable to move. The barking of the dog gets louder and louder and you can make out human footsteps as well." << std::endl;
        std::cout << "You have been caught!" << std::endl;
        std::cout << "Game Over" << std::endl;
        std::exit(0);
        break;
      case 3:
        // Left.
        std::cout << "Go back inside? That\'s crazy!" << std::endl;
        break;
      case 4:
        // Right.
        std::cout << "You immediately start sprinting into the thick woods. The going is slow as you run into thick brush with no discernable path." << std::endl;
        std::cout << "Luckily, the brush is too dense for you to be followed and you make it to a clearing on the other side of the woods, and find a road." << std::endl;
        std::cout << "You stop a passing car and are able to hitch a ride back to civilization." << std::endl;
        std::cout << "You have successfully escaped the dungeon!" << std::endl;
        std::exit(0);
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

void Outside::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void Outside::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void Outside::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void Outside::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int Outside::get_room_num()
{
  return room_num;
}






