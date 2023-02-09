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

    std::multimap<double, std::string> mmap;
    while (fin >> id >> value)
    {
        hmap[id] =  value;
        mmap.insert({value, id});
    }
    std::string qin;

    while(1)
    {
        std::cout << "query> ";
        std::cin >> qin;

        if (qin == "END") break;
        if (qin[0] == '+') {
            double v = std::stod(qin);
            auto lower_bound = mmap.lower_bound(v-0.01*v);
            auto upper_bound = mmap.upper_bound(v+0.01*v);
            if (lower_bound==upper_bound)
                std::cout << "No ID for the given value" << std::endl;
            else {
                for (auto it = lower_bound; it != upper_bound; it++)
                    std::cout << "value[" << it->second << "]= " << it->first << std::endl;
                }
        }
        else {
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
    }
    std::cout << "Bye..." << std::endl;
}