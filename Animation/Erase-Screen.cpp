#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "All-Animation.hpp"
#include <atomic>
void Erase_Screen(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string temp ="@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @";
    std::cout << "\033[H" << std::flush;
    const int banyaknya_kolom = 73;
    for(int i = 0; i < banyaknya_kolom; i++){
        for(size_t j = 0; j < temp.size(); j++){
            std::cout <<" " << std::flush;
            std::this_thread::sleep_for(std::chrono::microseconds(200));
        }
        std::cout << std::endl;
        
    }
    std::cout << "\033[2J" << std::flush;
    std::cout << "\033[H" << std::flush;

}