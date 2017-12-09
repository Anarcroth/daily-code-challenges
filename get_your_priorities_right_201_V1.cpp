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
  void enqueue(T item, double a, double b);
  T dequeueFirst();
  T dequeueA();
  T dequeueB();
  int count();
  void viewQueue() const;
  void clear();
  void set_queue(std::map< T, std::pair<double, double> >& queue);
  std::map< T, std::pair<double, double> > get_queue();

private:
  std::map< T, std::pair<double, double> > p_queue;
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : p_queue()
{ }

template<typename T>
PriorityQueue<T>::PriorityQueue(std::map< T, std::pair<double, double> >& queue)
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
  p_queue.erase(p_queue.find(temp));
  return temp;
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
  p_queue.erase(p_queue.find(temp));
  return temp;
}

template<typename T>
T PriorityQueue<T>::dequeueFirst()
{
  std::string temp = p_queue.begin()->first;
  p_queue.erase(p_queue.find(temp));
  return temp;
}

template<typename T>
int PriorityQueue<T>::count()
{
  return p_queue.size();
}

template<typename T>
void PriorityQueue<T>::viewQueue() const
{
  for (auto & s : p_queue)
    {
      std::cout << s.first << " " << s.second.first << " " << s.second.second << std::endl;
    }
}

template<typename T>
void PriorityQueue<T>::set_queue(std::map<T, std::pair<double, double> > & queue)
{
  this->p_queue = queue;
}

template<typename T>
std::map< T, std::pair<double, double> > PriorityQueue<T>::get_queue()
{
  return this->p_queue;
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
  qu.viewQueue();
  std::cout << qu.dequeueA() << std::endl;
  std::cout << qu.dequeueB() << std::endl;
  std::cout << qu.count() << std::endl;
  std::cout << qu.dequeueFirst() << std::endl;
  qu.viewQueue();
  qu.clear();
  std::cout << qu.dequeueB() << std::endl;
  return 0;
}
