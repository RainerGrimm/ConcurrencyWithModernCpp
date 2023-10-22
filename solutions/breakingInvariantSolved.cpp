#include <atomic>
#include <functional>
#include <iostream>
#include <thread>

struct Account{
  int balance{100};                               
};

std::mutex mutAccount;

void transferMoney(int amount, Account& from, Account& to){
  using namespace std::chrono_literals;
  {
    std::lock_guard<std::mutex> lock(mutAccount); 
    if (from.balance >= amount){
      from.balance -= amount;  
      std::this_thread::sleep_for(10ns);                          
      to.balance += amount;
    }
  }
}

void printSum(Account& a1, Account& a2){  
  {  
    std::lock_guard<std::mutex> lock(mutAccount);
    std::cout << (a1.balance + a2.balance) << '\n';         
  }
}

int main(){
  
  std::cout << '\n';

  Account acc1;
  Account acc2;
  
  std::cout << "Initial sum: ";                          
  printSum(acc1, acc2);                                        
  
  std::thread thr1(transferMoney, 5, std::ref(acc1), std::ref(acc2));
  std::thread thr2(transferMoney, 13, std::ref(acc2), std::ref(acc1));
  std::cout << "Intermediate sum: ";                
  std::thread thr3(printSum, std::ref(acc1), std::ref(acc2)); 
  
  thr1.join();
  thr2.join();
  thr3.join();
                                                            
  std::cout << "     acc1.balance: " << acc1.balance << '\n';
  std::cout << "     acc2.balance: " << acc2.balance << '\n';
  
  std::cout << "Final sum: ";
  printSum(acc1, acc2);                                       
  
  std::cout << '\n';

}
