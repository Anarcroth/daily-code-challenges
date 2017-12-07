// Description
//
// Thanks for that list you made me, my thoughts are way more organised!
// I've got a few problems though that I thought you might be able to help with? Sometimes I put the wrong information in a list item. Maybe to prevent this I'd be able to modify/update the list item? That's not the only problem though, when there are 50+ items it gets kind of hard to work my way through. Do you think you could maybe add the ability to categorise my items? Obviously, if I have that, I'd also like to be able to view by category!
// Oh and finally, a few of you were really great and did this last time but is there a way you can somehow make my list retain state so that I don't have to re-type it everytime I turn my computer on again?
// The newest To-do list should be capable of the following functionality:
// Modifying an existing list item
// Be able to give a list item a category. The list item should be able to take an arbitrary amount of categorys
// View by category - All list items should be able to be sorted and output by category to make it easier to wade through submissions
// Retain state
// Thanks!
// Formal Inputs & Outputs
//
// Output description
//
// Any output that is created should be user-friendly. When I'm viewing my to-do list, I should be able to easily discern one list item from another.
// Examples
//
// (don't take this too literally, do it how you would like to do it)
// Categorisation
//
// Input:
// addItem('Go to work','Programming'); //Item belongs to the Programming Category
// addItem('Create Sine Waves in C', 'Music', 'Programming); //Belongs to 2 categories, 'Programming' and 'Music');
// Category Output
//
// Input:
// viewList('programming');
// viewList('music');
// viewList('music', 'programming');
// Output:
// ----PROGRAMMING----
// - A pixel is not a pixel is not a pixel
// - The Scheme Programming Language
// - Memory in C
// - Haskell's School of Music
// - Algorithmic Symphonies from one line of code
//
// ----MUSIC----
// - Modes in Folk Music
// - The use of the Melodic Minor Scale
// - Haskell's School of Music
// - Algorithmic Symphonies from one line of code
//
// ----MUSIC & PROGRAMMING----
// - Haskell's School of Music
// - Algorithmic Symphonies from one line of code
// Modifying an item
//
// updateItem('Create Sine Waves in C', 'Create Sine Waves in Python');
// //The item has now changed from 'Create Sine Waves in C' to 'Create Sine Waves in Python'. This should be reflected in the viewList function/method you have created.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
#include <iterator>
#include <sstream>

template<class T>
class ToDoList
{
private:
  std::map<T, std::vector<T> > todo_list;

public:
  ToDoList();
  ToDoList(std::vector<T> list);
  ~ToDoList();

  void addItem(T item, std::vector<T>& categories);
  void updateItem(T old_item, T new_item);
  void deleteItem(T item);
  void saveList();
  void viewList();
};

template<class T>
ToDoList<T>::ToDoList()
{
}

template<class T>
ToDoList<T>::ToDoList(std::vector<T> list) : todo_list(list)
{
}

template<class T>
void ToDoList<T>::addItem(T item, std::vector<T>& categories)
{
  for (auto & s : categories)
    {
      todo_list[s].push_back(item);
    }
}

template<class T>
void ToDoList<T>::deleteItem(T item)
{
  if (todo_list.empty())
    {
      std::cout << "ToDo list is empty" << std::endl;
    }
  else
    {
      for (auto& s : todo_list)
        {
          s.second.erase(std::remove(s.second.begin(), s.second.end(), item), s.second.end());
          if (s.second.empty())
            {
              todo_list.erase(s.first);
            }
        }
    }
}

template<class T>
void ToDoList<T>::updateItem(T old_item, T new_item)
{
  for (auto& s : todo_list)
    {
       std::for_each(s.second.begin(), s.second.end(), [&](T& it) { if (old_item == it) it = new_item; });
    }
}

template<class T>
void ToDoList<T>::viewList()
{
  if (todo_list.empty())
    {
      std::cout << "ToDo list is empty" << std::endl;
    }
  else
    {
      for (auto s : todo_list)
        {
          std::cout << "--- " << s.first << " ---" << std::endl;
          std::for_each(s.second.begin(), s.second.end(), [&](T& item){std::cout << item << std::endl;});
        }
    }
}

template<class T>
void ToDoList<T>::saveList()
{
  std::ofstream in("todo-list.txt");
  if (in.is_open())
    {
      for (auto & s : todo_list)
        {
          in << "--- " + s.first + " ---\n";
          for (auto & z : s.second)
            {
              in << z + "\n";
            }
        }
      in.close();
    }
  else
    {
      std::cout << "Unable to open file" << std::endl;
    }
}

template<class T>
ToDoList<T>::~ToDoList()
{
  todo_list.clear();
}

std::vector<std::string> get_categories();

int main()
{
  ToDoList<std::string> list;

  std::string input1 = "", input2 = "", answr;

  std::cout << "Welcome to your ToDo List" << std::endl;
  std::cout << "1. Add an item and category." << std::endl;
  std::cout << "2. Delete an item." << std::endl;
  std::cout << "3. Update and item." << std::endl;
  std::cout << "4. View your list." << std::endl;
  std::cout << "5. Save and quit." << std::endl;

  do
    {
      std::cout << "Enter action: ";
      std::getline(std::cin, answr);

      switch (std::stoi(answr))
        {
        case 1:
          {
            std::cout << "Enter an item: ";
            std::getline(std::cin, input1);
            std::vector<std::string> categories = get_categories();
            list.addItem(input1, categories); break;
          }
        case 2:
          std::cout << "Enter an item: ";
          std::getline(std::cin, input1);
          list.deleteItem(input1); break;
        case 3:
          std::cout << "Enter old item: ";
          std::getline(std::cin, input1);
          std::cout << "Enter new item: ";
          std::getline(std::cin, input2);
          list.updateItem(input1, input2); break;
        case 4:
          list.viewList(); break;
        case 5:
          list.saveList();
          std::cout << "Bye!" << std::endl;
          exit(0);
        default:
          continue;
        }
    } while (std::stoi(answr));

  return 0;
}

std::vector<std::string> get_categories()
{
  std::cout << "Enter category(ies), separated by a space: ";
  std::string input;
  std::getline(std::cin, input);
  std::istringstream buf(input);
  std::istream_iterator<std::string> beg(buf), end;
  std::vector<std::string> tokens(beg, end);

  return tokens;
}
