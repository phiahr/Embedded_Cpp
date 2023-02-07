#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using std::string;
using std::vector;


void printResult(vector<double>& ans)
{
 
    // Traverse the vector ans
    for (auto& it : ans) {
 
        // Print elements
        std::cout << it << ' ';
    }
    std::cout << "\n";
}

int countElementsInSlice(vector<double>& arr,
                    int X, int Y)
{
 
    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
 
    // To store the sliced vector
    vector<double> result(Y - X + 1);
 
    // Copy vector using copy function()
    copy(start, end, result.begin());
 
    // Return the final sliced vector
    // return result;

    // return count
    printResult(result);
    return result.size();
}

int count_digit(int number) {
   return number == 0 ? 1 : int(log10(number) + 1);
}

int getWhiteSpaces(int number, int maxNumber)
{
  return (count_digit(maxNumber)-count_digit(number));
}


int main(int argc, char **argv) {
  string file_name = argv[1];
  vector<double> buf;
  std::ifstream fin(file_name, std::ios::in);

  string line;
  auto mean = 0.0;

  while (std::getline(fin, line)) {
    auto d = std::stod(line);
    if (d >= 0 && d < 8000)
    {
        buf.push_back(d);
    }
    mean = (buf.size() == 1) ? d : mean + (d - mean) / buf.size();
  }

  std::sort(buf.begin(), buf.end());

  auto mid = buf.size() / 2;
  double median = (buf.size() % 2) ? buf[mid] :
                                     (buf[mid - 1] + buf[mid]) / 2;

  std::cout << "number of elements = " << buf.size()
            << ", median = " << median
            << ", mean = " << mean << std::endl;


  // create hash map to store value inside
  std::map<int,int> histogram;
  int largestSlice = 0;
  int indexOfLargestSlice = 0;

  for (int i = 0; i < buf[buf.size()-1]; i+=100)
  {
    histogram[i] = 0;
    while (1)
    {
      if (buf.size() == 0) break;

      // not part of the bucket anymore, so break out
      if (buf.size() == 0 || buf[0] >= i+100)
      {
        largestSlice = (largestSlice < histogram[i]) ? histogram[i] : largestSlice;
        break;
      }
      else
      {
        histogram[i] += 1;
        buf.erase(buf.begin());
      }

    }
  }
  for (auto it = histogram.begin(); it != histogram.end(); it++)
  {
    // number of stars is proportional to the largest number having 60 stars
    int starsCount = ((float)it->second/(float)largestSlice)*60;

    // getWhiteSpaces() to right align the numbers that have less digits than the maximum numbers 
    std::cout << std::string(getWhiteSpaces(it->first,histogram.rbegin()->first), ' ') << it->first << "\t" << std::string(getWhiteSpaces(it->second,largestSlice), ' ') << it->second << " " << std::string(starsCount, '*') << std::endl;
  }

}
