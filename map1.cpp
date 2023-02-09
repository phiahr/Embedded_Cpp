#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>

int main(int argc, char **argv)
{
    std::string file_name = argv[1];
    std::ifstream fin(file_name, std::ios::in);

    std::unordered_map<std::string, double> hmap;
    std::string id;
    double value;
    
    while (fin >> id >> value)
    {
        hmap[id] =  value;
    }
    std::string qin;

    while(1)
    {
        std::cout << "query> ";
        std::cin >> qin;

        if (qin == "END") break;
        if (hmap.find(qin) != hmap.end())
        {
            // found
            std::cout << "value[" << qin << "]= " << hmap[qin] << std::endl; 
        }
        else 
        {
            // not found
            std::cout << "This ID does not exist" << std::endl;
        }
    }
    std::cout << "Bye..." << std::endl;
}