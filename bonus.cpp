#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Call executable with amount of numbers as first parameter and file name as second parameter" << std::endl;
        return 0;
    }
    int n;
    try
    {
        n = std::stoi(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Specify an integer as the first argument for the file length" << '\n';
        return 0;
    }

    std::string file_name = argv[2];

    std::random_device rd;
    std::mt19937 generator(rd());
    std::lognormal_distribution<> distribution(7.445, 0.58);

    std::fstream file;
    file.open(file_name, std::ios_base::out);

    for (int i(0); i < n; ++i)
    {
        file << distribution(generator) << std::endl;
    }
    file.close();
}