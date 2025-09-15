#pragma once
#include <iostream>
#include <string>
#include <atomic>
#include <vector>
#include <chrono>
#include <thread>

void Main_Menu(std::atomic<bool>& apakah_sedang_di_main_menu);
void Erase_Screen();
void Enter_to_Begin_Game(std::atomic<bool>& apakah_enter_belum_dipencet);