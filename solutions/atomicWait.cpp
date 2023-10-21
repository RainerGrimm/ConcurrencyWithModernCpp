#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> atomicBool{};

void doTheWork(){
    std::cout << "Processing shared data." << '\n';
}

void waitingForWork(){
    std::cout << "Worker: Waiting for work." << '\n';
    atomicBool.wait(false);
    doTheWork();
    std::cout << "Work done." << '\n';
}

void setDataReady(){
    atomicBool.store(true);
    std::cout << "Sender: Data is ready."  << '\n';
    atomicBool.notify_one();
}

int main(){

    std::cout << '\n';

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();

    std::cout << '\n';
  
}