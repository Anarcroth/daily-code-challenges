#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class robot
{
private:
     bool is_started() const;

     void change_state(bool s);
     void move_n();
     void move_s();
     void move_e();
     void move_w();

public:
     robot();
     robot(const std::vector<std::string> &m, bool s);

     void set_map(const std::vector<std::string> &map);
     void move(const char &command);
     void set_pos(size_t pos);
     void display() const;

     size_t get_position() const;

     std::vector<std::string> map;
     size_t position;
     bool started;
};

robot::robot() : started(false)
{}

robot::robot(const std::vector<std::string> &m, bool s) : map(m), started(s)
{}

void robot::set_map(const std::vector<std::string> &map)
{
     this->map = map;
}

void robot::set_pos(size_t pos)
{
     position = pos;
}

size_t robot::get_position() const
{
     size_t curr_pos;
     for (auto &line : map)
     {
          curr_pos = line.find('M');
     }
     return curr_pos;
}

void robot::move(const char &command)
{
     while (!is_started())
     {
          // Exit the move function if the robot is not started and skip the specific move actions
          if (std::tolower(command) == 'i')
          {
               change_state(!is_started());
          }
     }
     switch(std::tolower(command))
     {
     case 'n': move_n(); break;
     case 's': move_s(); break;
     case 'e': move_e(); break;
     case 'w': move_w(); break;
     default : std::cout << "Invalid command!" << std::endl; break;
     }
}

inline bool robot::is_started() const
{
     return started;
}

void robot::move_n()
{
     for (auto &line : map)
     {
          std::cout << line.at(get_position());
     }
}

void robot::move_s()
{

}

void robot::move_e()
{

}

void robot::move_w()
{

}

void robot::display() const
{

}

std::vector<std::string> get_map_by_line_from_file(std::string path)
{
     std::cout << "Hello";
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
     std::vector<std::string> map;
     map = get_map_by_line_from_file("map.txt");
     robot r(map, false);

     std::cout << "Enter command for the robot to move: ";
     std::string commands;
     std::getline(std::cin, commands);

     for (auto &command : commands)
     {
          r.move(command);
          r.display();
     }

     return 0;
}
