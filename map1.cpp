#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
// #include <algorithm>
#include <map>
// #include <cmath>

int main(int argc, char **argv)
{
    std::string file_name = argv[1];

    std::ifstream fin(file_name, std::ios::in);

    std::string line;

    std::map<std::string, double> hMap;

    while (std::getline(fin, line))
    {
        std::string id;
        double value;
        std::istringstream stream(line);
        stream >> id >> value;
        hMap[id] = value;
    }

    // for (auto it = hMap.begin(); it != hMap.end(); it++)
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    // }
    std::string qin;

    while(1)
    {
        std::cout << "query> ";
        std::cin >> qin;


        if (qin == "END") break;

        if (hMap.find(qin) != hMap.end()) {
        // found
            std::cout << "value[" << qin << "]= " << hMap[qin] << std::endl; 
        }
        else 
        {
        // not found
            std::cout << "This ID does not exist" << std::endl;
        }
    }
    std::cout << "Bye..." << std::endl;
}