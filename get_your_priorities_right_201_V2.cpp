#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

template<typename N>
struct node
{
  N itme;
  double priorityA;
  double priorityB;
  node *next;
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
  void delete_node_at(double val);

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
  node<T> *temp;

  if (front == nullptr)
    {
      std::cout << "The priority queue is empty." << std::endl;
    }
  else
    {
      double maxA = 0;
      std::string strA;
      temp = front;
      while (temp->next != nullptr)
        {
          if (temp->priorityA > maxA)
            {
              maxA = temp->priorityA;
              strA = temp->item;
            }
        }
      delete_node_at(maxA);
      return strA;
    }
}

template<typename T>
T PriorityQueue<T>::dequeueB()
{
  return "";
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
void PriorityQueue<T>::delete_node_at(double val)
{
  node<T> *temp = front;
  while (temp->next != nullptr)
    {
      if (temp->priorityA == val || temp->priorityB == val)
        {
          //TODO set prev node to the next one and delete the current one
        }
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
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
}

int main()
{

  return 0;
}
