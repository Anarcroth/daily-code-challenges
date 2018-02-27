// Description
// You must remotely send a sequence of orders to a robot to get it out of a minefield.
//
// You win the game when the order sequence allows the robot to get out of the minefield without touching any mine. Otherwise it returns the position of the mine that destroyed it.
//
// A mine field is a grid, consisting of ASCII characters like the following:
//
// +++++++++++++
// +000000000000
// +0000000*000+
// +00000000000+
// +00000000*00+
// +00000000000+
// M00000000000+
// +++++++++++++
// The mines are represented by * and the robot by M.
//
// The orders understandable by the robot are as follows:
//
// N moves the robot one square to the north
// S moves the robot one square to the south
// E moves the robot one square to the east
// O moves the robot one square to the west
// I start the the engine of the robot
// - cuts the engine of the robot
// If one tries to move it to a square occupied by a wall +, then the robot stays in place.
//
// If the robot is not started (I) then the commands are inoperative. It is possible to stop it or to start it as many times as desired (but once enough)
//
// When the robot has reached the exit, it is necessary to stop it to win the game.
//
// The challenge
// Write a program asking the user to enter a minefield and then asks to enter a sequence of commands to guide the robot through the field.
//
// It displays after won or lost depending on the input command string.
//
// Input
// The mine field in the form of a string of characters, newline separated.
//
// Output
// Displays the mine field on the screen
//
// +++++++++++
// +0000000000
// +000000*00+
// +000000000+
// +000*00*00+
// +000000000+
// M000*00000+
// +++++++++++
// Input
// Commands like:
//
// IENENNNNEEEEEEEE-
// Output
// Display the path the robot took and indicate if it was successful or not. Your program needs to evaluate if the route successfully avoided mines and both started and stopped at the right positions.
//
// Bonus
// Change your program to randomly generate a minefield of user-specified dimensions and ask the user for the number of mines. In the minefield, randomly generate the position of the mines. No more than one mine will be placed in areas of 3x3 cases. We will avoid placing mines in front of the entrance and exit.
//
// Then ask the user for the robot commands.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

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
     bool started, alive;

public:
     robot();
     robot(const std::vector<std::string> &m, bool s);

     bool is_alive() const;
     bool is_maze_solved() const;

     void set_map(const std::vector<std::string> &map);
     void move(const char command);
     void display() const;
};

robot::robot() : x(0), y(0), started(false), alive(true)
{}

robot::robot(const std::vector<std::string> &m, bool s) : map(m), x(0), y(0), started(s), alive(true)
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
     case '-': change_state(!is_started()); std::cout << "Robot stopped!" << std::endl; break;
     default : std::cout << "Invalid command!" << std::endl; break;
     }
}

inline bool robot::is_started() const
{
     return started;
}

bool robot::is_maze_solved() const
{
     if (get_pos_y() == map[0].size() - 1 && alive)
     {
          std::cout << "You solved the maze!" << std::endl;
          return true;
     }
     return false;
}

void robot::move_s()
{
     switch (map[x + 1][y])
     {
     case '*':
          std::cout << "You landed on a mine! You died!" << std::endl;
          alive = false;
          break;
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
          std::cout << "You landed on a mine! You died!" << std::endl;
          alive = false;
          break;
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
          std::cout << "You landed on a mine! You died!" << std::endl;
          alive = false;
          break;
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
          std::cout << "You landed on a mine! You died!" << std::endl;
          alive = false;
          break;
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

inline bool robot::is_alive() const
{
     return alive;
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


     while (r.is_alive())
     {
          for (auto command : commands)
          {
               r.move(command);
               // pause the output for 2 seconds
               sleep(1);
               // reset the terminal, i.e. the output
               printf("\033c");
               r.display();

               if (r.is_maze_solved())
               {
                    std::cout << "You Win!" << std::endl;
                    return 0;
               }
          }
     }

     return 0;
}
