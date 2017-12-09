#include <iostream>
#include <vector>
#include <string>
#include <map>

template<typename T>
class PriorityQueue
{
public:
  void enqueue(T item, double a, double b);
  T& dequeueFirst();
  T& dequeueA();
  T& dequeueB();
  int count() const;
  void clear() const;
private:
  std::map< T, std::vector<double> > p_queue;
};

int main()
{
  return 0;
}
