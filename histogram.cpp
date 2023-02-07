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

  // vector to store the count of numbers that fit in a given bucket
  std::vector<int> buckets;
  for (int i = 0; i < buf[buf.size()-1]; i+=100)
  {
    int count = 0;
    while (1)
    {
      // not part of the bucket anymore, so break out
      if (buf.size() == 0 || buf[0] >= i+100)
      {
        buckets.push_back(count);
        break;
      }
      else
      {
        // add element to bucket by increasing count and remove it from buffer
        count++;
        buf.erase(buf.begin());
      }
    }
  }
  int j = 0;
  std::vector<int>::iterator largestBucket;
  largestBucket = std::max_element(buckets.begin(), buckets.end());

  for (int i = 0; i < buckets.size(); i++)
  {
    // number of stars is proportional to the largest number having 60 stars
    int starsCount = ((float)buckets[i] / (float)*largestBucket)*60;

    // getWhiteSpaces() to right align the numbers that have less digits than the maximum numbers 
    std::cout << std::string(getWhiteSpaces(i*100, buckets.size()*100), ' ') << i*100 << "\t" << std::string(getWhiteSpaces(buckets[i], *largestBucket), ' ') << buckets[i] << " " << std::string(starsCount, '*') << std::endl;
  }
}
