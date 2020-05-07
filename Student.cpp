#include "Student.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
    this->maxItemCount = 10;
    this->currentItemCount = 0;
    this->backpack = (Item**)malloc(this->maxItemCount * sizeof(Item*));
}

void Student::displayBackpackContents()
{
    for(int i = 0; i < this->currentItemCount; i++)
    {
        cout << this->backpack[i]->getName() << "\n";
    }
}

bool Student::addItem(Item* anItem)
{
    if(this->currentItemCount == this->maxItemCount)
    {
        return false;
    }
    else
    {
        this->backpack[this->currentItemCount] = anItem;
        this->currentItemCount++;
        return true;
    } 
}

Item* Student::dropItem(string name)
{
    for(int i = 0; i < currentItemCount; i++)
    {
        if(name == this->backpack[i]->getName())
        {
            Item* itemToReturn = this->backpack[i];
            this->backpack[i] = 0;
            this->currentItemCount--;
            return itemToReturn;
        }
    }
}

string Student::getName()
{
    return this->name;
}

void Student::setCurrentRoom(Room* aRoom)
{
    this->currentRoom = aRoom;
}

Room* Student::getCurrentRoom()
{
    return this->currentRoom;
}