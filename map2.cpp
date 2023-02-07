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

    std::map<std::string, double> hMap;
    std::string id;
    double value;
    
    while (fin >> id >> value)
        hMap[id] =  value;

    std::string qin;

    while(1)
    {
        std::cout << "query> ";
        std::cin >> qin;

        if (qin == "END") break;
        if (qin[0] == '+')
        {
            double v;
            try
            {
                v = std::stod(qin);
                bool foundValue = false;
                for (const auto& pair : hMap)
                {
                    if (pair.second > v-0.01*v && pair.second < v+0.01*v)
                    {
                        std::cout << "value[" << pair.first << "]= " << pair.second << std::endl;
                        foundValue = true;
                    }
                }
                if (!foundValue)
                {
                    std::cout << "This ID does not exist" << std::endl;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << "Invalid Value" << '\n';
            }
        }
        else {
        if (hMap.find(qin) != hMap.end())
        {
            // found
            std::cout << "value[" << qin << "]= " << hMap[qin] << std::endl; 
        }
        else
        {
            // not found
            std::cout << "This ID does not exist" << std::endl;
        }
        }
        
    }
    std::cout << "Bye..." << std::endl;
}