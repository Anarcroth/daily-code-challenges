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
  PriorityQueue(std::map< T, std::pair<double, double> >& queue);
  ~PriorityQueue();
  void enqueue(T& item, double a, double b);
  T& dequeueFirst();
  T& dequeueA();
  T& dequeueB();
  int count() const;
  void clear();
private:
  std::map< T, std::pair<double, double> > p_queue;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{ }

template<typename T>
PriorityQueue<T>::PriorityQueue(std::map< T, std::pair<double, double> >& queue)
{
  p_queue = queue;
}

template<typename T>
void PriorityQueue<T>::enqueue(T& item, double a, double b)
{
  p_queue.insert(std::pair<T, std::pair<double, double> >(item, (a, b)));
  //p_queue[item].push_back(a);
  //p_queue[item].push_back(b);
}

template<typename T>
T& PriorityQueue<T>::dequeueA()
{
  int max = 0;
  std::string temp;
  for (auto & s : p_queue)
    {
      if (s->second->first > max)
        {
          max = s->second->first;
          temp = s->first;
        }
    }
  return p_queue.find(temp)->first;
}

template<typename T>
T& PriorityQueue<T>::dequeueB()
{
  int max = 0;
  std::string temp;
  for (auto & s : p_queue)
    {
      if (s->second->second > max)
        {
          max = s->second->second;
          temp = s->first;
        }
    }
  return p_queue.find(temp)->first;
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
  return 0;
}
