#include <iostream>
#include <string>
#include <atomic>
#include "Animation\All-Animation.hpp"

void Enter_to_Begin_Game(std::atomic<bool>& apakah_enter_belum_dipencet){
    std::string buffer;
    std::getline(std::cin, buffer);
    apakah_enter_belum_dipencet = false;

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    Erase_Screen();
}