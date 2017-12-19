#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class robot
{
private:
     bool is_started() const;

     void change_state(bool s);
     void find_robot();
     void move_n();
     void move_s();
     void move_e();
     void move_w();

     size_t get_pos_x() const;
     size_t get_pos_y() const;

     std::vector<std::string> map;
     size_t x, y;
     bool started;

public:
     robot();
     robot(const std::vector<std::string> &m, bool s);

     void set_map(const std::vector<std::string> &map);
     void move(const char command);
     void display() const;
};

robot::robot() : x(0), y(0), started(false)
{}

robot::robot(const std::vector<std::string> &m, bool s) : map(m), x(0), y(0), started(s)
{}

void robot::set_map(const std::vector<std::string> &map)
{
     this->map = map;
}

void robot::find_robot()
{
     for (int str = 0; str < map.size(); str++)
     {
          for (int m = 0; m < map[str].size(); m++)
          {
               if (map[str][m] == 'M')
               {
                    x = str;
                    y = m;
                    break;
               }
          }
     }
}

inline size_t robot::get_pos_x() const
{
     return x;
}

inline size_t robot::get_pos_y() const
{
     return y;
}

void robot::change_state(bool s)
{
     started = s;
}

void robot::move(const char command)
{
     find_robot();
     while (!is_started())
     {
          // Exit the move function if the robot is not started and skip the specific move actions
          if (std::tolower(command) == 'i')
          {
               change_state(!is_started());
               std::cout << "Robot started!" << std::endl;
               return;
          }
     }
     switch(std::tolower(command))
     {
     case 'n': std::cout << "Moving north!" << std::endl; move_n(); break;
     case 's': std::cout << "Moving south!" << std::endl; move_s(); break;
     case 'e': std::cout << "Moving east!" << std::endl; move_e(); break;
     case 'w': std::cout << "Moving west!" << std::endl; move_w(); break;
     default : std::cout << "Invalid command!" << std::endl; break;
     }
}

inline bool robot::is_started() const
{
     return started;
}

void robot::move_s()
{
     switch (map[x + 1][y])
     {
     case '*':
          std::cout << "You landed on a mine! You died!" << std::endl; break;//exit(0);
     case '0':
          map[x][y] = '0';
          x = x + 1;
          map[x][y] = 'M';
          break;
     case '+':
     default: break;
     }
}

void robot::move_n()
{
     switch (map[x - 1][y])
     {
     case '*':
          std::cout << "You landed on a mine! You died!" << std::endl; break;//exit(0);
     case '0':
          map[x][y] = '0';
          x = x - 1;
          map[x][y] = 'M';
          break;
     case '+':
     default: break;
     }
}

void robot::move_w()
{
     std::cout << map[x][y - 1] << std::endl;
     switch (map[x][y - 1])
     {
     case '*':
          std::cout << "You landed on a mine! You died!" << std::endl; break;//exit(0);
     case '0':
          map[x][y] = '0';
          y = y - 1;
          map[x][y] = 'M';
          break;
     case '+':
     default: break;
     }
}

void robot::move_e()
{
     switch (map[x][y + 1])
     {
     case '*':
          std::cout << "You landed on a mine! You died!" << std::endl; break;//exit(0);
     case '0':
          map[x][y] = '0';
          y = y + 1;
          map[x][y] = 'M';
          break;
     case '+':
     default: break;
     }
}

void robot::display() const
{
     for (auto &line : map)
     {
          std::cout << line << std::endl;
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

     for (auto command : commands)
     {
          r.move(command);
          r.display();
     }

     return 0;
}
