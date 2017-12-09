#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

template<typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  PriorityQueue(std::map< T, std::pair<double, double> > queue);
  ~PriorityQueue();
  void enqueue(T item, double a, double b);
  T dequeueFirst();
  T dequeueA();
  T dequeueB();
  int count() const;
  void clear();
private:
  std::map< T, std::pair<double, double> > p_queue;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{ }

template<typename T>
PriorityQueue<T>::PriorityQueue(std::map< T, std::pair<double, double> > queue)
{
  p_queue = queue;
}

template<typename T>
void PriorityQueue<T>::enqueue(T item, double a, double b)
{
  p_queue.insert(std::make_pair(item, std::make_pair(a, b)));
}

template<typename T>
T PriorityQueue<T>::dequeueA()
{
  if (p_queue.empty())
    {
      return "The priority queue is empty";
    }
  int max = 0;
  std::string temp;
  for (auto & s : p_queue)
    {
      if (s.second.first > max)
        {
          max = s.second.first;
          temp = s.first;
        }
    }

  return p_queue.find(temp)->first;
}

template<typename T>
T PriorityQueue<T>::dequeueB()
{
  if (p_queue.empty())
    {
      return "The priority queue is empty";
    }
  int max = 0;
  std::string temp;
  for (auto & s : p_queue)
    {
      if (s.second.second > max)
        {
          max = s.second.second;
          temp = s.first;
        }
    }
  return p_queue.find(temp)->first;
}

template<typename T>
T PriorityQueue<T>::dequeueFirst()
{
  return p_queue.begin()->first;
}

template<typename T>
int PriorityQueue<T>::count() const
{
  return p_queue.size();
}

template<typename T>
void PriorityQueue<T>::clear()
{
  p_queue.clear();
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
  p_queue.clear();
}

int main()
{
  PriorityQueue<std::string> qu;

  qu.enqueue("needle", 1.8, 20.2);
  qu.enqueue("scalpel", 3.2, 30.9);
  qu.enqueue("bandage", 0.9, 6.2);
  qu.enqueue("cheap needle", 0.2, 10.1);
  qu.enqueue("gloves", 5.5, 25.4);
  std::cout << qu.dequeueA() << std::endl;
  std::cout << qu.dequeueB() << std::endl;
  std::cout << qu.count() << std::endl;
  std::cout << qu.dequeueFirst() << std::endl;
  qu.clear();
  std::cout << qu.dequeueB() << std::endl;
  return 0;
}
