#include <iostream> 
#include <thread> 
#include <utility>

int main(){ 

  std::thread t([]{std::cout << std::this_thread::get_id();}); 
  std::thread t2([]{std::cout << std::this_thread::get_id();}); 
  
  t.join(); 
  t = std::move(t2); 
  t.join(); 

}
