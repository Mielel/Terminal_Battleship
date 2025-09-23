#include <iostream>
#include <thread>
#include <string>
#include "PlayerInput.hpp"

void TampilkanGrid(std::string grid){
    std::cout << "\033[H" <<grid;
}
void TransisiAwalTampilkanGrid(std::string grid){
    std::cout << "\033[H";
    int indeks_awal = 0;
    int panjang_per_baris = 260;
    for(int baris = 1; baris <= 73; baris++){
        std::string baris_yang_dicetak = grid.substr(indeks_awal, panjang_per_baris);
        std::cout << baris_yang_dicetak <<std::flush;
        indeks_awal += panjang_per_baris;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}