// lifetimeIssues.cpp

#include <iostream>
#include <string>
#include <thread>

int main(){
    
  std::cout << "Begin:" << '\n';               

  std::string mess{"Child thread"};

  std::thread t([&mess]{ std::cout << mess << '\n';});
  t.detach();                                   
  
  std::cout << "End:" << '\n';             

}
