#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int val;
    int val_t = std::thread::hardware_concurrency();

    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> val;

    if (val > 0 && val_t > 0) {
        auto start = std::chrono::steady_clock::now();

        unsigned long long final = 1;
        int range = (val + val_t - 1) / val_t;
        std::thread threads[val_t];

        for (int i = 0; i < val_t; ++i) {
            int start_v = i * range + 1;
            int end_v = (i + 1) * range;
            if (end_v > val) {
                end_v = val;
            }
            threads[i] = std::thread([start_v, end_v, &final](){
                unsigned long long result = 1;
                for (int j = start_v; j <= end_v; ++j) {
                    result *= j;
                }
                final *= result;
            });
        }

        for (int i = 0; i < val_t; ++i) {
            threads[i].join();
        }

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        std::cout << "Факториал числа " << val << " равен " << final << std::endl;
        std::cout << "Время выполнения: " << duration << " nc" << std::endl;
    } else {
        std::cout << "Неправильный ввод" << std::endl;
    }

    return 0;
}


