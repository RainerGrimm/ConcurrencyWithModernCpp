#include <algorithm>
#include <execution>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main(){
	
    std::cout << '\n';

    std::vector<int> myVec{1, 2, 3, 4, 5};

    try{
        std::for_each(myVec.begin(), myVec.end(),
            [](int){ throw std::runtime_error("Without execution policy"); }
        );
    }
    catch(const std::runtime_error& e){
        std::cout << e.what() << '\n';
    }
    
    try{
        std::for_each(std::execution::seq, myVec.begin(), myVec.end(),
            [](int){ throw std::runtime_error("With execution policy"); }
        );
    }
    catch(const std::runtime_error& e){
        std::cout << e.what() << '\n';
    }
    catch(...){
        std::cout << "Catch-all exceptions" << '\n';
    }
    
}
    
