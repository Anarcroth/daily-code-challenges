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
  node<T>* get_queue();

private:
  void delete_node_at(node<T>*& nd);

  node<T> *front;
  node<T> *end;
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : front(nullptr), end(nullptr)
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
          break;
        }
      temp = temp->next;
    }
}

template<typename T>
int PriorityQueue<T>::count() const
{
  return 0;
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
node<T>* PriorityQueue<T>::get_queue()
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

  std::cout << qu.dequeueA() << std::endl;

  qu.viewQueue();

  std::cout << qu.dequeueFirst() << std::endl;

  qu.viewQueue();

  return 0;
}
