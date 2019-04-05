/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Kitchen class.
*******************************************************************************/
#include "Kitchen.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Kitchen::Kitchen()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  
  room_num = 4;
}

/*******************************************************************************
** Function Name: description
** Description: Describes the room at the beginning of the turn. 
*******************************************************************************/

void Kitchen::description()
{
  std::cout << "You enter the room and see several tables and counters lining the wall." << std::endl;
  std::cout << "Dirty dishes are strewn about and the smell is terrible." << std::endl;
}

/*******************************************************************************
** Function Name: room_options
** Description: Provides the player with the room-specific options and actions
** to take and returns to the main Game program a pointer to the next room
** that the player ultimately chooses.
*******************************************************************************/

Space * Kitchen::room_options(Player * player)
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
        std::cout << "You go through the door at the north end of the room." << std::endl;
        return up;
        break;
      case 2:
        // Down.
        std::cout << "You go through the door at the south end of the room." << std::endl;
        return down;
        break;
      case 3:
        // Left.
        std::cout << "The west end of the room has a long counter running alongside an old refrigerator." << std::endl;
        std::cout << "Old dishes lay in disarray and seem to be covered in a nasty grime. There is no sound coming from the refrigerator." << std::endl;
        std::cout << "Do you want to open it?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        choice = int_validation_range(2);
        
        if (choice == 1)
        {
          the_grog(player);
        }
        else
        {
          std::cout << "You get a bad feeling from the refrigerator and step away from it" << std::endl;
        }
        break;
      case 4:
        // Right.
        std::cout << "Two large sinks full of dirty pots make up the majority of the eastern wall. The pots appear to be grimy and marinating in their own filth." << std::endl;
        std::cout << "Strangely there is not a single fly to be seen or heard around this mess." << std::endl;
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

void Kitchen::set_up(Space * room)
{
  up = room;
}

/*******************************************************************************
** Function Name: set_down
** Description: Sets the 'down' pointer of this room to another room object.
*******************************************************************************/

void Kitchen::set_down(Space * room)
{
  down = room;
}

/*******************************************************************************
** Function Name: set_left
** Description: Sets the 'left' pointer of this room to another room object.
*******************************************************************************/

void Kitchen::set_left(Space * room)
{
  left = room;
}

/*******************************************************************************
** Function Name: set_right
** Description: Sets the 'right' pointer of this room to another room object.
*******************************************************************************/

void Kitchen::set_right(Space * room)
{
  right = room;
}

/*******************************************************************************
** Function Name: the_grog
** Description: Player gets the opportunity to drink a mystery drink.
*******************************************************************************/

void Kitchen::the_grog(Player * player)
{
  std::cout << "You pull open the refrigerator door and are immediately hit with a gut wrenching odor." << std::endl;
  std::cout << "Whatever was in here is now rotten beyond any doubt. You are about to close the door when something catches your eye." << std::endl;
  std::cout << "It is a case full of glass bottles with the words \'The Grog\' written on it. You examine it and determine it to be some sort of alcoholic beverage." << std::endl;
  std::cout << "Do you drink one of them?" << std::endl;
  std::cout << "1. Yes" << std::endl;
  std::cout << "2. No" << std::endl;
  
  int choice = int_validation_range(2);
  
  if (choice == 1)
  {
    // Drink the grog. If your health is above 50, it hurts you, otherwise it helps you.
    if (player->get_health() < 50)
    {
      std::cout << "It actually doesn\'t taste too bad. You quickly finish it and let out a manly belch. You feel slightly stronger and you feel the pain in your arm fade a bit." << std::endl;
      std::cout << "You have recuperated 10 HP!" << std::endl;
      player->increase_health(15);
    }
    else if (player->get_health() >= 50)
    {
      std::cout << "You get halfway through the grog before your gag reflex stops you and you vomit onto the counter. You feel a sharp pain in your abdomen as the bottle falls to the floor." << std::endl;
      std::cout << "You have lost 10 HP from drinking rotten grog!" << std::endl;
      player->decrease_health(5);
    }
  }
  else
  {
    std::cout << "Better not, it could be disgusting." << std::endl;
  }
}

/*******************************************************************************
** Function Name: get_room_num
** Description: Returns the room number.
*******************************************************************************/

int Kitchen::get_room_num()
{
  return room_num;
}





























