#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main(){

  std::cout << '\n';

  std::vector<int> randValues;
  randValues.reserve(size);

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(1, 10);
  for (long long i = 0 ; i < size ; ++i) 
      randValues.push_back(uniformDist(engine));
 
  const auto sta = std::chrono::steady_clock::now();
  
  const unsigned long long sum= std::accumulate(randValues.begin(), 
                                                randValues.end(), 0);
 
  std::chrono::duration<double> dur= std::chrono::steady_clock::now() - sta;
  std::cout << "Time for addition " << dur.count() 
            << " seconds" << '\n';
  std::cout << "Result: " << sum << '\n';

  std::cout << '\n';

}
