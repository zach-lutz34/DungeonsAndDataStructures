#ifndef Student_hpp
#define Student_hpp

#include <string>
#include "Item.hpp"
using namespace std;

class Room;
class Student
{
    private:
        string name;
        Room* currentRoom;
        int maxItemCount;
        int currentItemCount;
        Item** backpack;

    public:
        Student(string name);
        void displayBackpackContents();
        bool addItem(Item* anItem);
        Item* dropItem(string name);
        string getName();
        Room* getCurrentRoom();
        void setCurrentRoom(Room* aRoom);
};

#endif