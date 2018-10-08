#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>

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
    else
    {
        std::cout << "Could not open file " << path << std::endl;
        exit(1);
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

std::vector<int> find(std::vector<std::string> &maze, char element)
{
    std::vector<int> xy;
    for(std::vector<int>::size_type y = 0; y != maze.size(); y++) {
        if (maze[y].find(element) != std::string::npos)
        {
            xy.push_back(maze[y].find(element));
            xy.push_back(y);
            break;
        }
    }
    return xy;
}

std::string decideWhereToMove(std::vector<std::string> &maze, robot &r)
{
    if (r.previous == "south")
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
    else if (r.previous == "west")
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
    else if (r.previous == "east")
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
    else if (r.previous == "north")
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
    return r.previous;
}

void solve(std::vector<std::string> &maze, robot &r, int end_y, int end_x)
{
    bool solved = false;
    while (!solved)
    {
        display(maze);

        std::string go_to = decideWhereToMove(maze, r);

        if (go_to == "south")
        {
            maze[r.get_y() + 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curry = r.get_y();
            r.set_y(curry + 1);
            r.previous = "north";
        }
        else if (go_to == "west")
        {
            maze[r.get_y()][r.get_x() - 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t currx = r.get_x();
            r.set_x(currx - 1);
            r.previous = "east";
        }
        else if (go_to == "north")
        {
            maze[r.get_y() - 1][r.get_x()] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t curry = r.get_y();
            r.set_y(curry - 1);
            r.previous = "south";
        }
        else if (go_to == "east")
        {
            maze[r.get_y()][r.get_x() + 1] = 'R';
            maze[r.get_y()][r.get_x()] = ' ';
            size_t currx = r.get_x();
            r.set_x(currx + 1);
            r.previous = "west";
        }

        if (r.get_y() == end_y && r.get_x() == end_x)
        {
            std::cout << "Solved" << std::endl;
            solved = true;
            break;
        }

        // Control how fast the "animation goes"
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        printf("\033c");
    }
}

int main()
{
    // Load a txt map that is a maze in ascii characters.
    // The robot should be denoted by a character - R, the exit by - E
    std::vector<std::string> maze = load_maze("maze.txt");
    std::vector<int> pos = find(maze, 'R');
    std::vector<int> end = find(maze, 'E');

    robot r(pos[0], pos[1]);

    solve(maze, r, end[0], end[1]);

    std::cout << "Solved!" << std::endl;

    return 0;
}
