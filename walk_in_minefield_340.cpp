#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class robot
{
private:
     void move(const std::string &commands);
     void set_map(const std::vector<std::string> &map);
     bool is_started() const;

public:
     robot();
     robot(const std::vector<std::string> &m, bool s);

     void move_n();
     void move_s();
     void move_e();
     void move_w();
     void display();

     std::vector<std::string> map;
     short int position;
     bool started;
};

robot::robot()
{
     started = false;
}

robot::robot(const std::vector<std::string> &m, bool s) : map(m), started(s)
{}

std::vector<std::string> get_map_by_line_from_file(std::string path)
{
     std::ifstream map(path.c_str());
     std::string line;
     std::vector<std::string> fl_map;
     if (map.is_open())
     {
          while (std::getline(map, line))
          {
               fl_map.push_back(line);
          }
          map.close();
     }
     return fl_map;
}

std::vector<std::string> get_map_by_input()
{
     int rows;
     std::vector<std::string> fl_map;
     std::cout << "Enter map row size: ";
     std::cin >> rows;
     std::cout << "Enter the map" << std::endl;
     for (int i = 0; i < rows; i++)
     {
          std::string line;
          std::getline(std::cin, line);
          fl_map.push_back(line);
     }
     return fl_map;
}

int main()
{
     std::vector<std::string> map = get_map_by_line_from_file("map.txt");
     robot r(map, false);

     return 0;
}
