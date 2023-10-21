#include <atomic>
#include <iostream>
#include <thread>

std::atomic_flag atomicFlag{};

void doTheWork(){
    std::cout << "Processing shared data." << '\n';
}

void waitingForWork(){
    std::cout << "Worker: Waiting for work." << '\n';
    atomicFlag.wait(false);
    doTheWork();
    std::cout << "Work done." << '\n';
}

void setDataReady(){
    atomicFlag.test_and_set();
    std::cout << "Sender: Data is ready."  << '\n';
    atomicFlag.notify_one();
}

int main(){

    std::cout << '\n';

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << '\n';
  
}