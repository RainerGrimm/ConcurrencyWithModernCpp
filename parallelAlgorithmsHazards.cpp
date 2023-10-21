#include <algorithm>
#include <execution>
#include <mutex>
#include <vector>


int main() {

    std::vector<int> v = {1, 2, 3};

    int sum = 0;
    std::for_each(std::execution::par, v.begin(), v.end(), [&sum](int i){
        sum += i + i;
    });

    int sum2 = 0;
    std::mutex m2;
    std::for_each(std::execution::par, v.begin(), v.end(), [&sum2, &m2](int i){
        std::lock_guard<std::mutex> lock(m2);
        sum2 += i + i;
    });

    int sum3 = 0;
    std::mutex m3;
    std::for_each(std::execution::unseq, v.begin(), v.end(), [&sum3, &m3](int i){
        std::lock_guard<std::mutex> lock(m3);
        sum3 += i + i;
    });

    int sum4 = 0;
    std::mutex m4;
    std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&sum4, &m4](int i){
        std::lock_guard<std::mutex> lock(m4);
        sum4 += i + i;
    });

}