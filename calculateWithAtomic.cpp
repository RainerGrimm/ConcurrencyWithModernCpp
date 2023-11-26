#include <atomic>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

constexpr long long size = 100'000'000;

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
  
  std::atomic<unsigned long long> sum = {};
  std::cout << std::boolalpha << "sum.is_lock_free(): " 
            << sum.is_lock_free() << '\n';
  std::cout << '\n';
 
  auto sta = std::chrono::steady_clock::now();
  
  for (auto i: randValues) sum += i;
 
  std::chrono::duration<double> dur= std::chrono::steady_clock::now() - sta;
  std::cout << "Time for addition " << dur.count() 
            << " seconds" << '\n';
  std::cout << "Result: " << sum << '\n';
    
  std::cout << '\n';
  
  sum=0;
  sta = std::chrono::steady_clock::now();
  
  for (auto i: randValues) sum.fetch_add(i);
  
  dur = std::chrono::steady_clock::now() - sta;
  std::cout << "Time for addition " << dur.count() 
            << " seconds" << '\n';
  std::cout << "Result: " << sum << '\n';
    
  std::cout << '\n';

}
