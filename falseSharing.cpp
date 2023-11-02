#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

constexpr long long size{100'000'000};   

struct Sum{
    long long a{0};
    long long b{0};
};

int main(){
    
    std::cout << '\n';
    
    Sum sum;
    
    std::cout << &sum.a << '\n';
    std::cout << &sum.b << '\n';
    
    std::cout << '\n';

    std::vector<int> randValues, randValues2;
    randValues.reserve(size);
    randValues2.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1,10);

    int randValue;
    for (long long i = 0; i < size; ++i){ 
        randValue = uniformDist(engine);
        randValues.push_back(randValue);
        randValues2.push_back(randValue);
    }
    
    auto sta = std::chrono::steady_clock::now();
    
    std::thread t1([&sum, &randValues]{ for (auto val: randValues) sum.a += val; });
    std::thread t2([&sum, &randValues2]{ for (auto val: randValues2) sum.b += val; });
    
    t1.join(), t2.join();
    
    std::chrono::duration<double> dur= std::chrono::steady_clock::now() - sta;
    std::cout << "Time for addition " << dur.count() 
            << " seconds" << '\n';
    
    std::cout << "sum.a: " << sum.a << '\n';
    std::cout << "sum.b: " << sum.b << '\n';
    
    std::cout << '\n';
    
}
