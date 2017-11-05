#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>

int main()
{
  std::map<std::pair<int, int>, std::string> message;
  std::fstream instream("../example.txt", std::ios_base::in);

  int message_id, packet_id, num_packets;
  std::string text;
  std::string msg;

  while (std::getline(instream, text))
    {
      std::istringstream ss(text);

      ss >> message_id >> packet_id >> num_packets;

      ss >> msg;

      message.insert(std::make_pair(std::make_pair(message_id, packet_id), msg));
    }

  for (auto it = message.begin(); it != message.end(); ++it)
    {
      std::cout << it->first.first << " - " << it->first.second <<  " - " << it->second << std::endl;
    }
}
