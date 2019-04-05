/*******************************************************************************
** Author: John Williams
** Date: 11.25.17
** Description: Header file for Item class.
*******************************************************************************/
#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
  private:
    std::string name;
  public:
    Item(std::string);
    virtual ~Item();
    std::string get_name();
};

#endif