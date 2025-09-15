#include <iostream>
#include <thread>
#include <atomic>
#include "Animation\All-Animation.hpp"

int main(){
    std::atomic<bool> flagAnimasiMain(true);
    std::thread mengOutputAnimasi(Main_Menu, std::ref(flagAnimasiMain));
    std::thread menerimaInput(Enter_to_Begin_Game, std::ref(flagAnimasiMain));

    mengOutputAnimasi.join();
    menerimaInput.join();
    return 0;
}