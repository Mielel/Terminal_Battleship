#pragma once
#include <iostream>
#include <atomic>
#include <string>
#include "../PlayerGrid.hpp"

void UbahGridSesuaiKursor(std::string& grid, int sumbu_x, int sumbu_y, char karakter_pengganti);
void GettingCursorMovement(std::atomic<bool>& bisa_gerakin_kursor, Player& playerAsal, Player playerTujuan);
void TampilkanGrid(std::string grid);
void ShowCursorMovement(std::atomic<bool>& apakah_sudah_mulai, Player &player);
void UpdateGrid(Player &playerAsal, Player& playerTujuan, std::atomic<bool>&apakah_hit);
void TransisiAwalTampilkanGrid(std::string grid);
void GettingBattleshipCursorMovement(std::atomic<bool>& bisa_gerakin_kursor, Player &player);
void BuatKapalVertikalUkuran2 (Player &player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y);
void BuatKapalHorizontalUkuran2 (Player &player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y);
void KembalikanGrid(Player& player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y);
void KosongkanGrid(Player& player, int sumbu_x, int sumbu_y);
void ShowBattleshipCursor(std::atomic<bool>& apakah_sudah_mulai, Player &player);
void UpdateGridJikaAdaKapalHancur(Player playerAsal, Player &playerTujuan);
void TungguSampaiKlikSuatuKey(std::atomic<bool>& masih_belum_pencet_apa_pun);
void InputMetode(pilihCara& metode);