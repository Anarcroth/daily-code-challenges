#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class robot
{
private:
     void move(char p);

     bool is_started();
public:
     void move_n();
     void move_s();
     void move_e();
     void move_w();

     short int position;
     bool started;
};

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
     robot r;
     return 0;
}
