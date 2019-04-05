/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Source file for Game class.
*******************************************************************************/
#include "Game.hpp"

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/

Game::Game()
{
  player = new Player();
  
  starting_room = new Starting_Room();
  current_room = starting_room;
  
  jail_room = new Jail_Room();
  the_pit = new The_Pit();
  kitchen = new Kitchen();
  basement = new Basement();
  outside = new Outside();
  
  // Set all the room pointers ot their appropriate other rooms.
  //
  // starting_room.
  starting_room->set_left(jail_room);
  starting_room->set_right(the_pit);
  starting_room->set_up(kitchen);

  // jail_room.
  jail_room->set_right(starting_room);
  
  // the_pit
  the_pit->set_left(starting_room);
  
  // kitchen
  kitchen->set_down(starting_room);
  kitchen->set_up(basement);
  
  // basement.
  basement->set_down(kitchen);
  basement->set_right(outside);
  
  // outside
  outside->set_left(basement);

}

/*******************************************************************************
** Function Name: Default Destructor
*******************************************************************************/

Game::~Game()
{
  delete starting_room;
  delete jail_room;
  delete the_pit;
  delete kitchen;
  delete basement;
  delete outside;
  delete player;
}

/*******************************************************************************
** Function Name: print_map
** Description: Shows the current map and location of the player. Takes a Space
** pointer and gets the room number from that pointer with get_room_num.
*******************************************************************************/

void Game::print_map(Space * room)
{
  std::cout << "\t MAP" << std::endl;
  std::cout << "X marks your current location." << std::endl;
  std::cout << "\n \n";
  switch (room->get_room_num())
  {
    case 1:
      std::cout <<  "        _____   __|__    \n"
                    "       |     |_|     |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |     |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|    |_|  X  |_|    |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    case 2:
      std::cout <<  "        _____   __|__    \n"
                    "       |     |_|     |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |     |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|  X |_|     |_|    |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    case 3:
      std::cout <<  "        _____   __|__    \n"
                    "       |     |_|     |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |     |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|    |_|     |_|  X |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    case 4:
      std::cout <<  "        _____   __|__    \n"
                    "       |     |_|     |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |  X  |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|    |_|     |_|    |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    case 5:
      std::cout <<  "        _____   __|__    \n"
                    "       |  X  |_|     |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |     |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|    |_|     |_|    |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    case 6:
      std::cout <<  "        _____   __|__    \n"
                    "       |     |_|  X  |_  \n"
                    "       |_____| |_____|   \n"
                    "        __|__     |      \n"
                    "       |     |           \n"
                    "       |_____|           \n"
                    " ____   __|__   ____     \n"
                    "|    |_|     |_|    |    \n"
                    "|____| |_____| |____|    \n" << std::endl;
      break;
    default:
      std::cout << "Error in print_map" << std::endl;
      break;
  }
  std::cout << "----------------------------" << std::endl;
  std::cout << "\n";
}

/*******************************************************************************
** Function Name: main_menu
** Description: Starts the intro to the game that includes the description of
** the game and how to play. User will decide if they want to play or not.
*******************************************************************************/

void Game::main_menu()
{
  int num_turns = 1;
  
    std::cout << "==========================" << std::endl;
    std::cout << "== Welcome to Project 5 ==" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Description of the game goes here." << std::endl;
    std::cout << "==========================" << std::endl;
    
    std::cout << "Would you like to play?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int choice = int_validation_range(2);
    
    // If user wants to quit, then quit.
    if (choice == 2)
    {
      std::cout << "Quitting.." << std::endl;
      std::exit(0);
    }
    
    // Otherwise, proceed with the game.
    std::cout << "You wake up to find yourself laying on the tile floor of an old, run-down restroom." << std::endl;
    std::cout << "You have no memory of how you got here or how long you've been unconscious." << std::endl;
    std::cout << "You do notice a gash in your arm that is bleeding. Wait too long before getting medical attention and you may bleed out." << std::endl;
    std::cout << "The room is dimply lit from a flickering light on the ceiling. You\'ve got to get out of this place." << std::endl;

    //---------------------------------------------------------------------------
    // Begin in the starting room. This is the main game loop.
    while (player->get_health() > 0)
    {
      
      
      // Present player's current status. (Health and inventory items)
      std::cout << "==========================" << std::endl;
      std::cout << "==========================" << std::endl;
      std::cout << "Turn #" << num_turns << std::endl;
      std::cout << "----------------------------" << std::endl;
      std::cout << "Current health: " << player->get_health() << std::endl;
      
      // If player's health is low, they feel weak.
      if (player->get_health() < 30)
      {
        std::cout << "You feel weak and the gash in your arm is starting to hurt more." << std::endl;
        std::cout << "You need medical attention." << std::endl;
      }
      
      std::cout << "Inventory: ";
      player->get_inventory();
      std::cout << "\n";
      std::cout << "----------------------------" << std::endl;
      
      // Print the current map and the player's location in it.
      print_map(current_room);
      
      // Present the current room's description and options within it.
      current_room->description();
      
      
      // Set the current_room to the pointer returned above. But not just the pointer, 
      // the actual object it points to. That way we get the next room object.
      current_room = current_room->room_options(player);
      
      
      num_turns++;
      player->decrease_health(4);
    }
    // End of main game loop, which is when the player dies from lack of health.
    //---------------------------------------------------------------------------
    std::cout << "You have lost a lot of blood, and the world becomes blurry and quiet." << std::endl;
    std::cout << "You sit down just to rest for a moment, but end up passing out." << std::endl;
    std::cout << "Game Over" << std::endl;
    main_menu();
    
    
}

























