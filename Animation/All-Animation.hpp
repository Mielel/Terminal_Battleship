#pragma once
#include <iostream>
#include <string>
#include <atomic>
#include <vector>
#include <chrono>
#include <thread>
#include "../PlayerGrid.hpp"

void Main_Menu(std::atomic<bool>& apakah_sedang_di_main_menu);
void Erase_Screen();
void Enter_to_Begin_Game(std::atomic<bool>& apakah_enter_belum_dipencet);
void tampilkanHitOrMiss(Player playerAsal, Player playerTujuan);
void tampilkan(std::string teks);
void tampilkanTanpaErase(std::string teks);
void tampilkanCepat(std::string teks);
void tampilkanStart();
void tampilkanRandomizerLoading();
void tampilkanMetodeYangDipilihSaatIni(pilihCara metode);
void tampilkanPemenang(int player);
void tampilkanTutorial(std::atomic<bool>& masih_belum_pencet_apa_pun, pilihCara cara_yang_dipilih);