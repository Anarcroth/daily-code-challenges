#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

class robot
{
private:
    void go_up();
    void go_left();
    void go_down();
    void go_right();

    size_t x, y;

public:
    robot();
    robot(int x, int y, std::string previous = "south");

    size_t get_x() const;
    size_t get_y() const;
    void set_x(size_t x);
    void set_y(size_t y);

    std::string previous;
};

robot::robot() : x(0), y(0), previous("south")
{}

robot::robot(int x, int y, std::string previous) : x(x), y(y), previous(previous)
{}

inline size_t robot::get_x() const
{
    return x;
}

inline size_t robot::get_y() const
{
    return y;
}

inline void robot::set_x(size_t x)
{
    this->x = x;
}

inline void robot::set_y(size_t y)
{
    this->y = y;
}

void robot::go_right()
{
}

void robot::go_left()
{
}

void robot::go_down()
{
}

void robot::go_up()
{
}

void display(std::vector<std::string> &maze)
{
    for (auto &line : maze)
    {
        std::cout << line << std::endl;
    }
}

/*
  Load an ascii maze into a string of vectors.
  This allows to access the map like a simple 2D array.
*/
std::vector<std::string> load_maze(std::string path)
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

/*
  Manually input an ascii maze.
*/
std::vector<std::string> input_map()
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

std::vector<int> find_robot(std::vector<std::string> &maze)
{
    std::vector<int> xy;
    for(std::vector<int>::size_type y = 0; y != maze.size(); y++) {
        if (maze[y].find('R') != std::string::npos)
        {
            // Finds the x value of the Robot
            xy.push_back(maze[y].find('R'));
            xy.push_back(y);
            break;
        }
    }
    return xy;
}

std::string decideWhereToMove(std::string prev, std::vector<std::string> &maze, robot &r)
{
    if (prev == "south")
    {
        if (maze[r.get_y()][r.get_x() - 1] != '#')
        {
            return "west";
        }
        else if (maze[r.get_y() - 1][r.get_x()] != '#')
        {
            return "north";
        }
        else if (maze[r.get_y()][r.get_x() + 1] != '#')
        {
            return "east";
        }
    }
    else if (prev == "west")
    {
        if (maze[r.get_y() - 1][r.get_x()] != '#')
        {
            return "north";
        }
        else if (maze[r.get_y()][r.get_x() + 1] != '#')
        {
            return "east";
        }
        else if (maze[r.get_y() + 1][r.get_x()] != '#')
        {
            return "south";
        }
    }
    else if (prev == "east")
    {
        if (maze[r.get_y() + 1][r.get_x()] != '#')
        {
            return "south";
        }
        else if (maze[r.get_y()][r.get_x() - 1] != '#')
        {
            return "west";
        }
        else if (maze[r.get_y() - 1][r.get_x()] != '#')
        {
            return "north";
        }
    }
    else if (prev == "north")
    {
        if (maze[r.get_y()][r.get_x() + 1] != '#')
        {
            return "east";
        }
        else if (maze[r.get_y() + 1][r.get_x()] != '#')
        {
            return "south";
        }
        else if (maze[r.get_y()][r.get_x() - 1] != '#')
        {
            return "west";
        }
    }
    return prev;
}

// up down left right previous
void solve(std::vector<std::string> &maze, robot &r)
{
    bool solved = false;
    while (!solved)
    {
        if (decideWhereToMove(r.previous, maze, r) == "south")
        {
            maze[r.get_y() + 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            r.set_y(r.get_y() + 1);
        }
        else if (decideWhereToMove(r.previous, maze, r) == "west")
        {
            maze[r.get_y()][r.get_x() - 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            r.set_y(r.get_x() - 1);
        }
        else if (decideWhereToMove(r.previous, maze, r) == "north")
        {
            maze[r.get_y() - 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            r.set_y(r.get_y() - 1);
        }
        else if (decideWhereToMove(r.previous, maze, r) == "east")
        {
            maze[r.get_y()][r.get_x() + 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            r.set_y(r.get_x() + 1);
        }

        // pause the output for 2 seconds
        sleep(1);
        // reset the terminal output
        printf("\033c");
        display(maze);
    }
}

int main()
{
    // Load a txt map that is a maze in ascii characters.
    // The robot should be denoted by a character - R
    // then it is found and the maze is solved
    std::vector<std::string> maze = load_maze("map.txt");
    std::vector<int> pos = find_robot(maze);
    robot r(pos[0], pos[1]);

    solve(maze, r);

    std::cout << "Solved!" << std::endl;

    return 0;
}
