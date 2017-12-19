#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class robot
{
private:
     bool is_started() const;
     
     void set_state(bool s);
     void move_n();
     void move_s();
     void move_e();
     void move_w();
     void display();

public:
     robot();
     robot(const std::vector<std::string> &m, bool s);

     void set_map(const std::vector<std::string> &map);
     void move(const std::string &commands);

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

void robot::move(const std::string &commands)
{
     for (auto &command : commands)
     {
          switch(std::tolower(command))
          {
          case 'i': set_state(!is_started());
          case 'n': move_n();
          case 's': move_s();
          case 'e': move_e();
          case 'w': move_w();
          default : break;
          }
     }
}

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

     std::cout << "Enter command for the robot to move: ";
     std::string commands;
     std::getline(std::cin, commands);

     r.move(commands);

     return 0;
}
