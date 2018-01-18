// (Practical Exercise): Get Your Priorities Right!
//
// A priority queue is a data structure similar to a standard queue, except that entries in the queue have a priority associated with them - such that, when removing items from the queue, the entry with the highest priority will be removed before ones with lower priority. This is similar to a hospital triage system: patients with more severe wounds get treated quicker, even if they arrived later than a patient with a smaller injury. Let's say I have a priority queue containing strings, where the priority value is a real number. I add these 3 objects to my priority queue, in no particular order:
// Patient 	Priority
// "David Whatsit" 	3.06
// "Joan Smith" 	4.33
// "Bob Testing" 	0.39
// "Samuel Sample" 	1.63
//
// Here, if I was to dequeue four strings from the priority queue, the strings "Joan Smith", "David Whatsit", "Samuel Sample" and "Bob Testing" would come out, in that order.
//
// But what if we could assign two priorities to each object? Imagine a hospital (to keep with the theme), that needs to keep a list of equipment supplies and their costs. It also needs to keep track of how long it will take to receive that item.
// Item 	Cost 	Shipping Time
// Hyperion Hypodermic Needle 	£1.99 	3 days
// SuperSaver Syringe 	£0.89 	7 days
// InjectXpress Platinum Plated Needle 	£2.49 	2 days
//
// Here, when the hospital is at normal running conditions with good supply stock, it would want to buy the cheapest product possible - shipping time is of little concern. Thus, dequeueing by the Lowest Cost priority would give us the SuperSaver syringe. However, in a crisis (where supply may be strained) we want supplies as fast as possible, and thus dequeueing an item with the Lowest Shipping Time priority would give us the InjectXpress needle. This example isn't the best, but it gives an example of a priority queue that utilizes two priority values for each entry.
//
// Your task today for the (non-extension) challenge will be to implement a two-priority priority queue for strings, where the priority is represented by a real number (eg. a floating-point value). The priority queue must be able to hold an unbounded number of strings (ie. no software limit). If your language of choice already supports priority queues with 1 priority, it might not be applicable to this challenge - read the specification carefully.
// Specification
// Core
//
// Your priority queue must implement at least these methods:
//
//     Enqueue. This method accepts three parameters - a string, priority value A, and priority value B, where the priority values are real numbers (see above). The string is inserted into the priority queue with the given priority values A and B (how you store the queue in memory is up to you!)
//
//     DequeueA. This method removes and returns the string from the priority queue with the highest priority A value. If two entries have the same A priority, return whichever was enqueued first.
//
//     DequeueB. This method removes and returns the string from the priority queue with the highest priority B value. If two entries have the same B priority, return whichever was enqueued first.
//
//     Count. This method returns the number of strings in the queue.
//
//     Clear. This removes all entries from the priority queue.
//
// Additional
//
// If you can, implement this method, too:
//
//     DequeueFirst. This removes and returns the string from the priority queue that was enqueued first, ignoring priority.
//
// Depending on how you implemented your priority queue, this may not be feasible, so don't get too hung up on this one.
// Extension
//
// Rather than making your priority queue only accept strings, make a generic priority queue, instead. A generic object is compatible with many types. In C++, this will involve the use of templates. More reading resources here. For example, in C#, your class name might look like DualPriorityQueue<TEntry>. Some dynamic languages such as Ruby or Python do not have static typing, so this will not be necessary.
// Notes
// Making Use of your Language
//
// The main challenge of this exercise is knowing your language and its features, and adapting your solution to them. For example, in .NET-based languages, Count would be a property rather than a method, as that is more idiomatic in those languages. Similarly, in some languages such as Ruby, F# or other functional language, overloading operators may be more idiomatic than the usage of verbose Enqueue and Dequeue functions. How you do the specifics is up to you.
//
// You should also be writing clean, legible code. Follow the style guide for your language, and use the correct naming/capitalisation conventions, which differ from language to language. Consider writing unit tests for your code, as an exercise in good practice!
// Tips and Reading Material
//
// If you are planning on using something like a heap for the priority queue, consider interleaving each item into two heaps to store both priorities. How you will handle the dequeueing is part of the fun! If the concept of a priority queue is new to you, here is some reading material.
//
//     University of Wisconsin-Madison: priority queue
//     Queues and Priority Queues
//
// Here's some more stuff on unit testing.
//
//     Unit testing on WikiBooks
//     MSDN: .NET unit tests
//     Writing good unit tests
//
// Finally...
//
// I wonder what this data structure would be called? A double priority queue?

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

template<typename T>
struct node
{
  T item;
  double priorityA;
  double priorityB;
  node<T> *next;
};

template<typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  PriorityQueue(node<T>& root);
  ~PriorityQueue();
  void enqueue(T item, double a, double b);
  T dequeueFirst();
  T dequeueA();
  T dequeueB();
  int count() const;
  void viewQueue() const;
  void clear();
  void set_queue(const node<T>& root);
  node<T>* get_queue() const;

private:
  void delete_node_at(node<T>*& nd);

  node<T> *front;
  node<T> *end;

  int size;
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : front(nullptr), end(nullptr), size(0)
{ }

template<typename T>
PriorityQueue<T>::PriorityQueue(node<T>& root)
{
  this->root = root;
}

template<typename T>
void PriorityQueue<T>::enqueue(T item, double a, double b)
{
  node<T> *temp = new node<T>;

  temp->item = item;
  temp->priorityA = a;
  temp->priorityB = b;
  temp->next = nullptr;

  if (front == nullptr)
    {
      front = temp;
    }
  else
    {
      end->next = temp;
    }
  end = temp;
  size += 1;
}

template<typename T>
T PriorityQueue<T>::dequeueA()
{
  if (front == nullptr)
    {
      std::cout << "The priority queue is empty." << std::endl;
    }
  else
    {
      node<T> *temp = front, *hit;

      double maxA = 0;
      std::string strA = "";

      while (temp != nullptr)
        {
          if (temp->priorityA > maxA)
            {
              maxA = temp->priorityA;
              strA = temp->item;
              hit = temp;
            }
          temp = temp->next;
        }
      delete_node_at(*&hit);
      return strA;
    }
}

template<typename T>
T PriorityQueue<T>::dequeueB()
{
  node<T> *temp, *hit;

  if (front == nullptr)
    {
      std::cout << "The priority queue is empty." << std::endl;
    }
  else
    {
      double maxB = 0;
      std::string strB = "";
      temp = front;
      while (temp->next != nullptr)
        {
          if (temp->priorityB > maxB)
            {
              maxB = temp->priorityB;
              strB = temp->item;
              hit = temp;
            }
          temp = temp->next;
        }
      delete_node_at(*&hit);
      return strB;
    }
}

template<typename T>
T PriorityQueue<T>::dequeueFirst()
{
  if (front == nullptr)
    {
      std::cout << "The priority queue is empty." << std::endl;
    }
  else
    {
      node<T> *temp = front;
      std::string key = temp->item;
      front = front->next;
      delete temp;
      size -= 1;
      return key;
    }
}

template<typename T>
void PriorityQueue<T>::delete_node_at(node<T>*& nd)
{
  node<T> *temp = front;
  while (temp != nullptr)
    {
      if (temp->next->item == nd->item)
        {
          temp->next = nd->next;
          delete *&nd;
          size -= 1;
          break;
        }
      temp = temp->next;
    }
}

template<typename T>
int PriorityQueue<T>::count() const
{
  return size;
}

template<typename T>
void PriorityQueue<T>::viewQueue() const
{
  if (front == nullptr)
    {
      std::cout << "The priority queue is empty" << std::endl;
    }
  else
    {
      node<T> *temp = front;

      while (temp != nullptr)
        {
          std::cout << temp->item << " " << temp->priorityA << " "<< temp->priorityB << std::endl;
          temp = temp->next;
        }
    }
}

template<typename T>
void PriorityQueue<T>::set_queue(const node<T>& root)
{
  this->root = root;
}

template<typename T>
node<T>* PriorityQueue<T>::get_queue() const
{
  return this->root;
}

template<typename T>
void PriorityQueue<T>::clear()
{
  if (front == nullptr)
    {
      std::cout << "The priority queue is already cleared" << std::endl;
    }
  else
    {
      node<T> *temp;

      while (front != nullptr)
        {
          temp = front;
          front = front->next;
          delete temp;
        }
      delete front;
    }
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
  clear();
}

int main()
{
  PriorityQueue<std::string> qu;

  qu.enqueue("needle", 5.5, 7.3);
  qu.enqueue("gloves", 11.8, 1.9);
  qu.enqueue("cotton balls", 10.7, 2.6);

  qu.viewQueue();

  std::cout << qu.count() << std::endl;
  std::cout << qu.dequeueA() << std::endl;

  qu.viewQueue();

  std::cout << qu.dequeueFirst() << std::endl;

  qu.viewQueue();
  std::cout << qu.count() << std::endl;

  return 0;
}
