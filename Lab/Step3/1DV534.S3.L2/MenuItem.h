#ifndef MENU_ITEM_H
#define MENU_ITEM_H

/**
* @brief    POD Class for storing item for a Menu.
*/
class MenuItem
{
   char itemId;             // Value representing the id of the menu item.
   const char *description; // Description of menu item.
public:
   MenuItem() {}
   ~MenuItem() {}
   void setItem(char itemId_, const char *description_) { itemId = itemId_; description = description_; }
   const char * getDesciption() { return description; }
   char getItemId() { return itemId; }
};

#endif /* MENU_ITEM_H */