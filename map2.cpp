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

        // auto findResult = std::find_if(std::begin(hMap), std::end(hMap), [qin](const std::pair<std::string, double> pair)
        // {
        //     // return pair
        //     // std::cout << pair.first << std::endl;
        //     // sanity check before 
        //     // double input;
        //     // if (qin == pair.first)
        //     // {
        //     //     std::cout << "value[" << pair.first << "]= " << pair.second << std::endl;
        //     //     return true;
        //     // }
        //     // else {
        //         try
        //         {
        //             // return pair.second == std::stod(qin);
        //             // if (pair.second+pair.second*0.01 == (int)std::stod(qin)/10){
        //             double v = std::stod(qin);
        //             if (pair.second > v-0.01*v && pair.second < v+0.01*v){
        //                 std::cout << "value[" << pair.first << "]= " << pair.second << std::endl; 
        //                 // std::cout << pair.second << std::endl;
        //                 // std::cout << pair.first << std::endl;
        //             }
        //         }
        //         catch(std::exception &err)
        //         {
        //             // std::cout << "This ID does not exist" << std::endl;
        //             return false;
        //         }
        //     // }
            
        //     return false;
        // });
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
                // std::cout << "This ID does not exist" << std::endl;

            }
        }
        else {
        if (hMap.find(qin) != hMap.end())
        {
            // found
            // std::cout << "Found" << std::endl;
            std::cout << "value[" << qin << "]= " << hMap[qin] << std::endl; 
        }
        // else if (findResult != std::end(hMap)) {/*std::cout << "found value: " << findResult->first << std::endl;*/}
        else
        {
            // not found
            std::cout << "This ID does not exist" << std::endl;
        }
        }
        // if (findResult != hMap.end())
        
    }
    std::cout << "Bye..." << std::endl;
}