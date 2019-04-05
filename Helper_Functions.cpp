/*******************************************************************************
** Author: John Williams
** Date: 11.21.17
** Description: Helper Functions for lab 9 - source.
*******************************************************************************/
#include "Helper_Functions.hpp"

/*******************************************************************************
** Function Name: int_validation_range
** Description: Function for validating user input when presented with a
** menu of options. It takes a const int parameter which represents how many
** options there are on the menu.
*******************************************************************************/

int int_validation_range(const int num_choices)
{
  int input;
  do
  {
    std::cout << "Please enter your choice: \n";
    std::cin >> input;
    
    if (std::cin.fail())
    {
      std::cout << "Invalid input. Please try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }while(std::cin.fail() || input < 1 || input > num_choices);
  
  return input;
}















