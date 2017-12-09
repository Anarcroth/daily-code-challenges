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
private:
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
