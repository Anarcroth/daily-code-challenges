// Description
// No more hiding from your alarm clock! You've decided you want your computer to keep you updated on the time so you're never late again. A talking clock takes a 24-hour time and translates it into words.
// Input Description
// An hour (0-23) followed by a colon followed by the minute (0-59).
//   Output Description
//   The time in words, using 12-hour format followed by am or pm.
//   Sample Input data
//   00:00
//      01:30
//      12:05
//      14:01
//      20:29
//      21:00
//      Sample Output data
//   It's twelve am
// It's one thirty am
//   It's twelve oh five pm
// It's two oh one pm
//   It's eight twenty nine pm
// It's nine pm

#include <iostream>
#include <string>

int main ()
{
  std::string time;

  std::cin >> time;

  int hours = std::stoi(time.substr(0, 2));
  int minutes = std::stoi(time.substr(3));

  std::string one_to_twelve[12] = {"one", "two", "three", "four", "five", "six",
                             "seven", "eight", "nine", "ten", "eleven", "twelve"};

  std::string tens[6] = {"ten", "twenty", "thirty", "forty", "fifty", "twelve"};

  std::string h = (hours == 0) ? one_to_twelve[11] : one_to_twelve[hours % 12 - 1] + " ";
  std::string m;
  std::string a_or_p_m;

  a_or_p_m = (hours > 11) ? "pm" : "am";

  if (minutes == 0)
    {
      m = " ";
    }
  else if (minutes < 10)
    {
      m = "oh " + one_to_twelve[minutes - 1] + " ";
    }
  else
    {
      m = tens[minutes / 10 - 1] + " " + ((minutes % 10 == 0) ? "" : one_to_twelve[minutes % 10 - 1] + " ");
    }

  std::cout << "It's " << h << m << a_or_p_m << std::endl;

  return 0;
}
