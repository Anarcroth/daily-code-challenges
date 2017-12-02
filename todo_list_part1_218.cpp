// Description
//
// Todays challenge will be something slightly different! Atleast I think the challenge is meant to be for today? Wait, am I meant to even be submitting today?
//   Okay maybe I need some help on organising my thoughts before I submit my challenge. A to-do list would be fine, just something so that I can organise my thoughts!
//   It should have the following basic functionality
//   Add an item to the to-do list
//   Delete a selected item from the to-do list
//   And obviously, print out the list so I can see what to do!
//                                           Formal Inputs & Outputs
//
//                                                              Output description
//
//                                                              Any output that is created should be user-friendly. When I'm viewing my to-do list, I should be able to easily discern one list item from another.
// Examples
//
// Input:
// addItem('Take a shower');
// addItem('Go to work');
// viewList();
// Output:
// Take a shower
// Go to work
// Further Input:
// addItem('Buy a new phone');
// deleteItem('Go to work');
// viewList();
// Outputs:
// Take a shower
// Buy a new phone

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ToDoList
{
private:
  std::vector<std::string> todo_list;

public:
  ToDoList();
  ToDoList(std::vector<std::string> list);
  ~ToDoList();

  void addItem(std::string item);
  void deleteItem(std::string item);
  void viewList();
};

ToDoList::ToDoList()
{
}

ToDoList::ToDoList(std::vector<std::string> list) : todo_list(list)
{
}

void ToDoList::addItem(std::string item)
{
  todo_list.push_back(item);
}

void ToDoList::deleteItem(std::string item)
{
  if (todo_list.empty())
    {
      std::cout << "ToDo list is empty" << std::endl;
    }
  else
    {
      todo_list.erase(std::remove(todo_list.begin(), todo_list.end(), item), todo_list.end());
    }
}

void ToDoList::viewList()
{
  if (todo_list.empty())
    {
      std::cout << "ToDo list is empty" << std::endl;
    }
  else
    {
      std::for_each(todo_list.begin(), todo_list.end(), [&](std::string item){std::cout << item << std::endl;});
    }

}

ToDoList::~ToDoList()
{
  todo_list.clear();
}

int main()
{
  ToDoList list;

  list.addItem("clean room");
  list.addItem("code");

  std::cout << "TODO list before" << std::endl;

  list.viewList();

  list.deleteItem("code");

  std::cout << "TODO list after" << std::endl;

  list.viewList();

  list.deleteItem("clean room");
  list.deleteItem("stuff");

  list.viewList();

  return 0;
}
