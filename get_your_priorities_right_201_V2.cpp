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
  void set_queue(node<T>& root);
  node<T>* get_queue();

private:
  void enqueue(node<T>* root, T item, double a, double b);
  node<T> *root;
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : root(nullptr)
{ }

template<typename T>
PriorityQueue<T>::PriorityQueue(node<T>& root)
{
  this->root = root;
}

template<typename T>
void PriorityQueue<T>::enqueue(T item, double a, double b)
{
  if (root == nullptr)
    {
      root = new node<T>;
      root->item = item;
      root->priorityA = a;
      root->priorityB = b;
      root->next = nullptr;
    }
  else
    {
      enqueue(root->next, item, a, b);
    }
}

template<typename T>
void PriorityQueue<T>::enqueue(node<T>* root, T item, double a, double b)
{
  if (root == nullptr)
    {
      root = new node<T>;
      root->item = item;
      root->priorityA = a;
      root->priorityB = b;
      root->next = nullptr;
    }
  else
    {
      enqueue(root->next, item, a, b);
    }
}

template<typename T>
T PriorityQueue<T>::dequeueA()
{
  return "";
}

template<typename T>
T PriorityQueue<T>::dequeueB()
{
  return "";
}

template<typename T>
T PriorityQueue<T>::dequeueFirst()
{
  return "";
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
void PriorityQueue<T>::set_queue(node<T>& root)
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
