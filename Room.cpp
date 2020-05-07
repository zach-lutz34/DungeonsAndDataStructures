#include "Room.hpp"
#include <iostream>
#include "Door.hpp"

using namespace std;

Room::Room(string title)
{
    this->title = title;
    this->currentNumberOfDoors = 0;
    this->items = (Item**)malloc(20 * sizeof(Item*));
}

void Room::addDoor(Door* aDoor)
{
    this->collectionOfDoors[this->currentNumberOfDoors] = aDoor;
    this->currentNumberOfDoors++;
    this->theStudents = new LinkedListOfStudents();
}

void Room::addStudent(Student* aStudent)
{
    if(this->theStudents->indexOf(aStudent) == -1)
    {
        this->theStudents->addFront(aStudent);
        aStudent->setCurrentRoom(this);
    } 
}

void Room::removeStudent(Student* aStudent)
{
    int indexOfStudent = this->theStudents->indexOf(aStudent);
    if(indexOfStudent != -1)
    {
        this->theStudents->removeAtIndex(indexOfStudent);
        aStudent->setCurrentRoom(0); //the student is in limbo
    }
}

void Room::takeDoor(Student* aStudent, string direction)
{
    Door* tempDoor;
    Room* currentRoom = this;
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        if(tempDoor->getDirectionToOtherRoom(currentRoom) == direction)
        {
            Room* theOtherRoom = tempDoor->getTheOtherRoom(currentRoom);
            
            //remove the student from the current room
            this->removeStudent(aStudent);

            //put the student in the new room
            theOtherRoom->addStudent(aStudent);
        }
    }
}

void Room::display()
{
    cout << this->title << "\n";

    //show the potential doors
    cout << "Obvious Exits: ";
    Door* tempDoor = 0;
    
    for(int i = 0; i < this->currentNumberOfDoors; i++)
    {
        tempDoor = this->collectionOfDoors[i];
        cout << tempDoor->getDirectionToOtherRoom(this) << " ";
    }
    cout << "\n Also Here: ";
    Student* tempStudent;

    for(int i = 0; i < this->theStudents->getCount(); i++)
    {
        tempStudent = this->theStudents->getAtIndex(i);
        cout << tempStudent->getName() << " ";
    }
    cout << "\n";
}

bool Room::additem(Item* item)
{
    if(this->itemCount == 20)
    {
        return false;
    }
    else
    {
        this->items[this->itemCount] = item;
        this->itemCount++;
        return true;
    } 
}

Item* Room::removeItem(string name)
{
    
    for(int i = 0; i <= 20; i++)
    {
        if(name == this->items[i]->getName())
        {
            Item* itemToReturn = this->items[i];
            this->items[i] = 0;
            this->itemCount--;
            return itemToReturn;
        }    
    }
}

void Room::displayItems()
{
    for(int i = 0; i < 20; i++)
    {
        if(this->items[i])
        {
            cout << this->items[i]->getName() << "\n";
        }
    }
}