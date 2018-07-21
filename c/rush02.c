// Example commands to test
// g++ rush02.c && echo "o--o\n|  |\n|  |\no--o" | ./a.out # SQUARE
// g++ rush02.c && echo "o---o\n|  |\n|  |\no---o" | ./a.out # RECTANGLE
// g++ rush02.c && echo "   o   \n  / \ \n /   \ \no-----o" | ./a.out # TRIANGLE
// g++ rush02.c && echo "   o---o\n  /   / \n /   / \no---o" | ./a.out # DIAMOND

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

void print_geo_figure();
void check_geo_shape(char* reading);
void increment_figure_chars(char figure);

int edges = 0;
int slope_lines = 0;
int vertical_lines = 0;
int horizontal_lines = 0;

int main()
{
    char reading[MAX_BUF];

    int fdin = 0, r_control;

    if (dup2(STDIN_FILENO, fdin) < 0)
    {
        perror("dup2(  )");
        exit(1);
    }

    memset(reading, '\0', MAX_BUF);

    while ((r_control = read( fdin, reading, MAX_BUF)) > 0)
    {
        check_geo_shape(reading);
        memset( reading, '\0', MAX_BUF);
    }

    if (r_control < 0)
    {
        perror("read(  )");
    }

    close(fdin);

    return 0;
}

void check_geo_shape(char* reading)
{
    char* figure;

    for (figure = reading; *figure != '\0'; figure++)
    {
        increment_figure_chars(*figure);
    }

    print_geo_figure();
}

void increment_figure_chars(char figure)
{
    if (figure == 'o') edges += 1;

    if (figure == '\\' || figure == '/') slope_lines += 1;

    if (figure == '|') vertical_lines += 1;

    if (figure == '-') horizontal_lines += 1;
}

void print_geo_figure()
{
    if (vertical_lines == horizontal_lines) printf("SQUARE");

    else if (slope_lines == 0) printf("RECTANGLE");

    else if (edges == 3 && slope_lines > 0) printf("TRIANGLE");

    else if (edges == 4 && slope_lines > 0) printf("DIAMOND");
}
