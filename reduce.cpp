#include <execution>
#include <iostream>
#include <numeric>
#include <vector>


int main() {

    std::cout << '\n';

    std::vector<int> v = {1, 2, 3};
    auto res = std::reduce(std::execution::par, v.begin(), v.end());

    std::cout << "res: "  << res << '\n';

    std::cout << '\n';
    
}