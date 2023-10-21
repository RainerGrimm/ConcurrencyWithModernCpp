#include <iostream>
#include <memory>
#include <atomic>
#include <string>
#include <thread>

int main() {

    std::cout << '\n';

    std::atomic<std::shared_ptr<std::string>> sharString(std::make_shared<std::string>("Zero"));
    
    std::thread t1([&sharString]{ sharString.store(std::make_shared<std::string>(*sharString.load() + "One")); });
    std::thread t2([&sharString]{ sharString.store(std::make_shared<std::string>(*sharString.load() + "Two")); });
    std::thread t3([&sharString]{ sharString.store(std::make_shared<std::string>(*sharString.load() +"Three")); });
    std::thread t4([&sharString]{ sharString.store(std::make_shared<std::string>(*sharString.load() +"Four")); });
    std::thread t5([&sharString]{ sharString.store(std::make_shared<std::string>(*sharString.load() +"Five")); });
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << *sharString.load() << '\n';

}