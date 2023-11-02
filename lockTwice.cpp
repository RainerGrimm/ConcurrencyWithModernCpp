#include <iostream>
#include <mutex>

int main(){

    std::mutex mut;

    std::cout << '\n';
    
    std::cout << "first lock call" << '\n';

    mut.lock();

    std::cout << "second lock call" << '\n';

    mut.lock();

}
