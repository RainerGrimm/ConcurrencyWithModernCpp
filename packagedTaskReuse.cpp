#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <vector>

void calcProducts(std::packaged_task<int(int, int)>& task, const std::vector<std::pair<int, int>>& pairs){
    for (auto& pair: pairs){
        auto fut = task.get_future();
        task(pair.first, pair.second); 
        std::cout << pair.first << " * " << pair.second << " = " <<  fut.get() << '\n';
        task.reset();
    }
}
    
int main(){

    std::cout << '\n';

    std::vector<std::pair<int, int>> allPairs;
    allPairs.push_back(std::make_pair(1, 2));
    allPairs.push_back(std::make_pair(2, 3));
    allPairs.push_back(std::make_pair(3, 4));
    allPairs.push_back(std::make_pair(4, 5));
    
    std::packaged_task<int(int, int)> task{[](int fir, int sec){ return fir * sec; }}; 
    
    calcProducts(task, allPairs);
    
    std::cout << '\n';
    
    std::thread t(calcProducts, std::ref(task), allPairs);
    t.join();
    
    std::cout << '\n';
    
}
