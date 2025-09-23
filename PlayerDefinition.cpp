
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include "PlayerGrid.hpp"
#include "Utilities/PlayerInput.hpp"


void Player::moveDown(){
    int posisi_awal_x = kursor[sumbu_x]; int posisi_awal_y = kursor[sumbu_y];
    const int ke_tengah = kursor[sumbu_x];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = kursor[sumbu_y]+1; i < batas_bawah_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i++){
        if(!isPosisiSudahDitembak(ke_tengah, i)){
            sudah_menemukan_posisi_kosong = true;
            kursor[sumbu_y] = i; 
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kanan < batas_kanan_sumbu_x_grid){
                if(isPosisiSudahDitembak(ke_kanan,i)){
                    ke_kanan += 1;
                }
                else{
                    kursor[sumbu_x] = ke_kanan;
                    kursor[sumbu_y] = i;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kanan = false;
            }
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                if(isPosisiSudahDitembak(ke_kiri, i)){
                    ke_kiri -= 1;
                }
                else{
                    kursor[sumbu_x] = ke_kiri;
                    kursor[sumbu_y] = i;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kiri = false;
            }
        }
    }
    if(sudah_menemukan_posisi_kosong){
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, posisi_awal_x, posisi_awal_y, ' ');
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, kursor[sumbu_x], kursor[sumbu_y], '#');
    }
}
void Player::moveUp(){
    int posisi_awal_x = kursor[sumbu_x]; int posisi_awal_y = kursor[sumbu_y];
    const int ke_tengah = kursor[sumbu_x];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = kursor[sumbu_y]-1; i >= batas_atas_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i--){
        if(!isPosisiSudahDitembak(ke_tengah, i)){
            sudah_menemukan_posisi_kosong = true;
            kursor[sumbu_y] = i; 
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                if(isPosisiSudahDitembak(ke_kiri, i)){
                    ke_kiri -= 1;
                }
                else{
                    kursor[sumbu_x] = ke_kiri;
                    kursor[sumbu_y] = i;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kiri = false;
            }
            if(ke_kanan < batas_kanan_sumbu_x_grid){
                if(isPosisiSudahDitembak(ke_kanan,i)){
                    ke_kanan += 1;
                }
                else{
                    kursor[sumbu_x] = ke_kanan;
                    kursor[sumbu_y] = i;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kanan = false;
            }
        }
    }
    if(sudah_menemukan_posisi_kosong){
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, posisi_awal_x, posisi_awal_y, ' ');
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, kursor[sumbu_x], kursor[sumbu_y], '#');
    }
}
void Player::moveRight(){
    int posisi_awal_x = kursor[sumbu_x]; int posisi_awal_y = kursor[sumbu_y];
    const int ke_tengah = kursor[sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = kursor[sumbu_x]+1; i < batas_bawah_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i++){
        if(!isPosisiSudahDitembak(i, ke_tengah)){
            sudah_menemukan_posisi_kosong = true;
            kursor[sumbu_x] = i; 
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_atas >= batas_atas_sumbu_y_grid){
                if(isPosisiSudahDitembak(i, ke_atas)){
                    ke_atas -= 1;
                }
                else{
                    kursor[sumbu_x] = i;
                    kursor[sumbu_y] = ke_atas;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_bawah < batas_bawah_sumbu_y_grid){
                if(isPosisiSudahDitembak(i, ke_bawah)){
                    ke_bawah += 1;
                }
                else{
                    kursor[sumbu_x] = i;
                    kursor[sumbu_y] = ke_bawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_bawah = false;
            }
        }
    }
    if(sudah_menemukan_posisi_kosong){
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, posisi_awal_x, posisi_awal_y, ' ');
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, kursor[sumbu_x], kursor[sumbu_y], '#');
    }
}
void Player::moveLeft(){
    int posisi_awal_x = kursor[sumbu_x]; int posisi_awal_y = kursor[sumbu_y];
    const int ke_tengah = kursor[sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = kursor[sumbu_x]-1; i >= batas_kiri_sumbu_x_grid && !sudah_menemukan_posisi_kosong; i--){
        if(!isPosisiSudahDitembak(i, ke_tengah)){
            sudah_menemukan_posisi_kosong = true;
            kursor[sumbu_x] = i; 
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_atas >= batas_atas_sumbu_y_grid){
                if(isPosisiSudahDitembak(i, ke_atas)){
                    ke_atas -= 1;
                }
                else{
                    kursor[sumbu_x] = i;
                    kursor[sumbu_y] = ke_atas;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_bawah < batas_bawah_sumbu_y_grid){
                if(isPosisiSudahDitembak(i, ke_bawah)){
                    ke_bawah += 1;
                }
                else{
                    kursor[sumbu_x] = i;
                    kursor[sumbu_y] = ke_bawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_bawah = false;
            }
        }
    }
    if(sudah_menemukan_posisi_kosong){
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, posisi_awal_x, posisi_awal_y, ' ');
        UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, kursor[sumbu_x], kursor[sumbu_y], '#');
    }
}
bool Player::apakahAdaYangKena(Player playerTujuan){
    if(playerTujuan.PosisiBattleship.empty()){
        return false;
    }
    else{
        bool apakah_ada_yang_kena = false;
        for(size_t i = 0; i < playerTujuan.PosisiBattleship.size() && !apakah_ada_yang_kena; i++){
            if(kursor[sumbu_x] == playerTujuan.PosisiBattleship[i][sumbu_x] && kursor[sumbu_y] == playerTujuan.PosisiBattleship[i][sumbu_y]){
                apakah_ada_yang_kena = true;
            }
        }
        return apakah_ada_yang_kena;
    }
}

void Player::resetCursor(){
    bool masih_belum_ada_posisi_kosong = true;
    for(int i = 0; i < 5 && masih_belum_ada_posisi_kosong; i++){
        for(int j = 0; j < 5 && masih_belum_ada_posisi_kosong; j++){
            if(!isPosisiSudahDitembak(j,i)){
                kursor[sumbu_y] = i;
                kursor[sumbu_x] = j;
                masih_belum_ada_posisi_kosong = false;
            }
        }
    }
}

bool Player::isPosisiSudahDitembak(int posisi_x, int posisi_y){
    if (PosisiYangUdahDitembak.empty()){
        return false;
    }
    for (size_t i = 0; i < PosisiYangUdahDitembak.size(); i++) {
        if(PosisiYangUdahDitembak[i][sumbu_x] == posisi_x && PosisiYangUdahDitembak[i][sumbu_y] == posisi_y){
            return true;
        }
    }
    return false;
}

bool Player::apakahAdaYangKenaKapal(Player playerTujuan){
    if(playerTujuan.PosisiBattleship.empty()){
        return false;
    }
    else{
        bool apakah_ada_kapal_yang_kena = false;
        for(size_t i = 0; i < playerTujuan.PosisiBattleship.size()-1 && !apakah_ada_kapal_yang_kena; i+=2){
            for(size_t j = 0; j < PosisiYangKena.size(); j++){
                if(kursor[sumbu_x] == playerTujuan.PosisiBattleship[i][sumbu_x] 
                    && kursor[sumbu_y] == playerTujuan.PosisiBattleship[i][sumbu_y]
                    && PosisiYangKena[j][sumbu_x] == playerTujuan.PosisiBattleship[i+1][sumbu_x]
                    && PosisiYangKena[j][sumbu_y] == playerTujuan.PosisiBattleship[i+1][sumbu_y]){
                    apakah_ada_kapal_yang_kena = true;
                    break;
                }
                else if(kursor[sumbu_x] == playerTujuan.PosisiBattleship[i+1][sumbu_x] 
                    && kursor[sumbu_y] == playerTujuan.PosisiBattleship[i+1][sumbu_y]
                    && PosisiYangKena[j][sumbu_x] == playerTujuan.PosisiBattleship[i][sumbu_x]
                    && PosisiYangKena[j][sumbu_y] == playerTujuan.PosisiBattleship[i][sumbu_y]){
                    apakah_ada_kapal_yang_kena = true;
                    break;
                    }
            }
        }
        return apakah_ada_kapal_yang_kena;
    }
}

void Player::placeShips() {
    // Inisialisasi papan internal untuk mengecek tabrakan
    const int ukuran_papan = 5;
    const int jumlah_kapal = 4;
    const int panjang_kapal = 2;
    std::vector<std::vector<CellState>> papan_internal(ukuran_papan, std::vector<CellState>(ukuran_papan, CellState::kosong));
    
    // Vector untuk menyimpan hasil akhir koordinat kapal
    std::vector<std::vector<int>> posisi_kapal_ditempatkan;

    // Inisialisasi generator angka acak
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Distribusi untuk memilih koordinat baris dan kolom
    std::uniform_int_distribution<> dist(0, ukuran_papan - 1);

    for (int i = 0; i < jumlah_kapal; ++i) {
        bool taruh = false;
        do {
            // Pilih koordinat kepala kapal secara acak
            int baris_kepala_kapal = dist(gen);
            int kolom_kepala_kapal = dist(gen);
            
            // Cek apakah posisi kepala sudah terisi
            if (papan_internal[baris_kepala_kapal][kolom_kepala_kapal] == CellState::terisi) {
                continue; 
            }

            // Simpan posisi valid untuk buntut kapal
            std::vector<std::pair<int, int>> posisi_buntut_valid;

            // Cek grid atas
            if (baris_kepala_kapal > 0 && papan_internal[baris_kepala_kapal - 1][kolom_kepala_kapal] == CellState::kosong) {
                posisi_buntut_valid.push_back({baris_kepala_kapal - 1, kolom_kepala_kapal});
            }
            // Cek grid bawah
            if (baris_kepala_kapal < ukuran_papan - 1 && papan_internal[baris_kepala_kapal + 1][kolom_kepala_kapal] == CellState::kosong) {
                posisi_buntut_valid.push_back({baris_kepala_kapal + 1, kolom_kepala_kapal});
            }
            // Cek grid kiri
            if (kolom_kepala_kapal > 0 && papan_internal[baris_kepala_kapal][kolom_kepala_kapal - 1] == CellState::kosong) {
                posisi_buntut_valid.push_back({baris_kepala_kapal, kolom_kepala_kapal - 1});
            }
            // Cek grid kanan
            if (kolom_kepala_kapal < ukuran_papan - 1 && papan_internal[baris_kepala_kapal][kolom_kepala_kapal + 1] == CellState::kosong) {
                posisi_buntut_valid.push_back({baris_kepala_kapal, kolom_kepala_kapal + 1});
            }

            // Jika ada posisi buntut yang valid
            if (!posisi_buntut_valid.empty()) {
                int baris_buntut_kapal, kolom_buntut_kapal;
                if (posisi_buntut_valid.size() == 1) {
                    baris_buntut_kapal = posisi_buntut_valid[0].first;
                    kolom_buntut_kapal = posisi_buntut_valid[0].second;
                } else {
                    std::uniform_int_distribution<> buntut_dist(0, posisi_buntut_valid.size() - 1);
                    int pilihan_buntut = buntut_dist(gen);
                    baris_buntut_kapal = posisi_buntut_valid[pilihan_buntut].first;
                    kolom_buntut_kapal = posisi_buntut_valid[pilihan_buntut].second;
                }

                std::vector<int> kapal_baru;
                posisi_kapal_ditempatkan.push_back({baris_kepala_kapal, kolom_kepala_kapal});
                posisi_kapal_ditempatkan.push_back({baris_buntut_kapal, kolom_buntut_kapal});

                papan_internal[baris_kepala_kapal][kolom_kepala_kapal] = CellState::terisi;
                papan_internal[baris_buntut_kapal][kolom_buntut_kapal] = CellState::terisi;

                taruh = true; 
            }
        } while (!taruh);
    }
    for(size_t i = 0; i < posisi_kapal_ditempatkan.size(); i++){
        PosisiBattleship.push_back(posisi_kapal_ditempatkan[i]);
    }
    
}


Player::Player(int playerKe_X){
            Kapal.reserve(4);
            for(int i = 0; i < 4; i++){
                Kapal.emplace_back(*this);
            }
            if(playerKe_X == 1){
                GridAsli = R"(# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #
# # # # # # + - - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - + # # # # # #
# # # : : % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = @ @ @ @ @ @ @ % : : # # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ : # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ : # #
# # % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ % # #
# + @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ + #
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ - #
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ - #
- @ @ @ @ @ @ : : : : : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ -
@ @ @ @ @ @ @ = : : = : : @ = : @ @ @ @ @ @ @ @ @ @ @ @ @ % % @ @ % % % % @ @ % : % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : @ : : @ @ : @ @ : : : @ : : @ : : : = : : : * : : : = @ @ : : % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : : : : @ @ : @ @ : * : @ @ : @ : : @ : @ @ : @ : : @ = @ @ @ : % @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : : : @ @ @ : @ @ @ @ : : @ : @ : : @ : : : : @ : : @ @ @ @ @ : % @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : @ @ @ @ @ : @ @ : - : : @ - @ : - @ : @ @ @ @ : : @ @ @ @ @ : % @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ - : : = @ @ @ - : - @ : - : : @ @ : : @ @ @ : : @ * : : - @ @ @ - : - @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ : : @ @ @ @ @ @ @ @ @ @ @ @ @ : : : @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ : : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @         @ @ @ * * @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @     @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @           @ @   % @     @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @           @ @         @ @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   . : : @ @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @ @ @ @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @ @ @ @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
- @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ -
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ - #
# + @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ + #
# # % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ % # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ : # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ : # #
# # # : : % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = @ @ @ @ @ @ @ % : : # # #
# # # # # # + - - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - + # # # # # #
# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #
# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #)";
            }
            else{
                GridAsli = R"(# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #
# # # # # # + - - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - + # # # # # #
# # # : : % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = @ @ @ @ @ @ @ % : : # # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ : # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ : # #
# # % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ % # #
# + @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ + #
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ - #
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ - #
- @ @ @ @ @ @ : : : : : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ -
@ @ @ @ @ @ @ = : : = : : @ = : @ @ @ @ @ @ @ @ @ @ @ @ @ % % @ @ % % % % @ % : : : % @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : @ : : @ @ : @ @ : : : @ : : @ : : : = : : : * : : : = @ : : @ = : @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : : : : @ @ : @ @ : * : @ @ : @ : : @ : @ @ : @ : : @ = @ @ @ @ = : @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : : : @ @ @ : @ @ @ @ : : @ : @ : : @ : : : : @ : : @ @ @ @ @ @ : : @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ : : @ @ @ @ @ : @ @ : - : : @ - @ : - @ : @ @ @ @ : : @ @ @ @ @ : - @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ - : : = @ @ @ - : - @ : - : : @ @ : : @ @ @ : : @ * : : - @ @ - : : - - @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ : : @ @ @ @ @ @ @ @ @ @ @ @ : : : : : @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ : : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @               @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @         @ @ @ * * @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @     @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @           @ @   % @     @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @           @ @   .     @ @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   . : : @ @ @ @ @ @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @ @ @ @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @     @ %   @ @   % @ @ @ @ @     @ @ @ @     @ @     @ @     @ @     % @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
- @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ @
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @                     @ - @                     @ - @                     @ - @                     @ - @                     @ - - @ @ @ @ @ @ @ @ @ @ -
# - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - @ @                 @ @ - - @ @ @ @ @ @ @ @ @ - #
# + @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - @ @ @             @ @ @ - - @ @ @ @ @ @ @ @ @ + #
# # % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - @ @ @ @         @ @ @ @ - - @ @ @ @ @ @ @ @ % # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - @ @ @ @ @ @ @ @ @ @ @ @ - - @ @ @ @ @ @ @ @ : # #
# # : @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - @ @ @ @ @ @ @ @ @ @ : # #
# # # : : % @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = @ @ @ @ @ @ @ % : : # # #
# # # # # # + - - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - - + # # # # # #
# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #
# # # # # # # # # - @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ - # # # # # # # # #)";
            }
            GridBattleShip = GridAsli;
            Kapal[0].resetBattleshipCursor();
            
            
            GridYangSedangDipakaiKursor = GridAsli;
            UbahGridSesuaiKursor(GridYangSedangDipakaiKursor, kursor[sumbu_x], kursor[sumbu_y], '#');
        }