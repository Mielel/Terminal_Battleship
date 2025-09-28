#include "PlayerGrid.hpp"
#include "Utilities/PlayerInput.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

void Battleship::moveUpKapalHorizontal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kanan][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[kiri][sumbu_y], BattleshipCursorPosition[kanan][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[kiri][sumbu_x];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[kiri][sumbu_y]-1; i >= batas_atas_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i--){
        std::vector<int> BagianKiri = {BattleshipCursorPosition[kiri][sumbu_x], i};
        std::vector<int> BagianKanan = {BattleshipCursorPosition[kanan][sumbu_x], i};
        if(!apakahUdahDitempati(BagianKiri) && !apakahUdahDitempati(BagianKanan)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[kiri] = BagianKiri; 
            BattleshipCursorPosition[kanan] = BagianKanan;
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                BagianKiri[sumbu_x] = ke_kiri;
                BagianKanan[sumbu_x] = ke_kiri+1;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_kiri -= 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kiri = false;
            }
            if(ke_kanan+1 < batas_kanan_sumbu_x_grid){
                BagianKiri[sumbu_x] = ke_kanan;
                BagianKanan[sumbu_x] = ke_kanan+1;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_kanan += 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
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
        CetakBattleshipHorizontal(posisi_awal_x, posisi_awal_y);
    }
}
void Battleship::moveLeftKapalHorizontal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kanan][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[kiri][sumbu_y], BattleshipCursorPosition[kanan][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[kiri][sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[kiri][sumbu_x]-1; i >= batas_kiri_sumbu_x_grid && !sudah_menemukan_posisi_kosong; i--){
        std::vector<int> BagianKiri = {i, BattleshipCursorPosition[kiri][sumbu_y]};
        std::vector<int> BagianKanan = {i+1, BattleshipCursorPosition[kanan][sumbu_y]};
        if(!apakahUdahDitempati(BagianKiri) && !apakahUdahDitempati(BagianKanan)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[kiri] = BagianKiri; 
            BattleshipCursorPosition[kanan] = BagianKanan;
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_bawah+1 < batas_bawah_sumbu_y_grid){
                BagianKiri[sumbu_y] = ke_bawah;
                BagianKanan[sumbu_y] = ke_bawah;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[bawah] = BagianKanan;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_atas >= batas_atas_sumbu_y_grid){
                BagianKiri[sumbu_y] = ke_atas;
                BagianKanan[sumbu_y] = ke_atas;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
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
        CetakBattleshipHorizontal(posisi_awal_x, posisi_awal_y);
    }
}
void Battleship::moveDownKapalHorizontal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kanan][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[kiri][sumbu_y], BattleshipCursorPosition[kanan][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[kiri][sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[kiri][sumbu_y]+1; i < batas_bawah_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i++){
        std::vector<int> BagianKiri = {BattleshipCursorPosition[kiri][sumbu_x], i};
        std::vector<int> BagianKanan = {BattleshipCursorPosition[kanan][sumbu_x], i};
        if(!apakahUdahDitempati(BagianKiri) && !apakahUdahDitempati(BagianKanan)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[kiri] = BagianKiri; 
            BattleshipCursorPosition[kanan] = BagianKanan;
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kanan+1 < batas_kanan_sumbu_x_grid){
                BagianKiri[sumbu_x] = ke_kanan;
                BagianKanan[sumbu_x] = ke_kanan+1;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_kanan += 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[bawah] = BagianKanan;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kanan = false;
            }
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                BagianKiri[sumbu_x] = ke_kiri;
                BagianKanan[sumbu_x] = ke_kiri+1;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_kiri -= 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
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
        CetakBattleshipHorizontal(posisi_awal_x, posisi_awal_y);
    }
}
void Battleship::moveRightKapalHorizontal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kanan][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[kiri][sumbu_y], BattleshipCursorPosition[kanan][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[atas][sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[kiri][sumbu_x]+1; i+1 < batas_kanan_sumbu_x_grid && !sudah_menemukan_posisi_kosong; i++){
        std::vector<int> BagianKiri = {i, BattleshipCursorPosition[kiri][sumbu_y]};
        std::vector<int> BagianKanan = {i+1, BattleshipCursorPosition[kanan][sumbu_y]};
        if(!apakahUdahDitempati(BagianKiri) && !apakahUdahDitempati(BagianKanan)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[kiri] = BagianKiri; 
            BattleshipCursorPosition[kanan] = BagianKanan;
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_atas >= batas_atas_sumbu_y_grid){
                BagianKiri[sumbu_y] = ke_atas;
                BagianKanan[sumbu_y] = ke_atas;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_bawah+1 < batas_bawah_sumbu_y_grid){
                BagianKiri[sumbu_y] = ke_bawah;
                BagianKanan[sumbu_y] = ke_bawah;
                if(apakahUdahDitempati(BagianKiri)  || apakahUdahDitempati(BagianKanan)){
                    ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianKiri;
                    BattleshipCursorPosition[kanan] = BagianKanan;
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
        CetakBattleshipHorizontal(posisi_awal_x, posisi_awal_y);
    }
}

void Battleship::rotateHorizontalToVertikal(bool &apakah_bisa_rotasi){
    int posisi_awal_x[2] = {BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kanan][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[kiri][sumbu_y], BattleshipCursorPosition[kanan][sumbu_y]};
    int kolom_ke_kanan = BattleshipCursorPosition[kiri][sumbu_x];   
    int kolom_ke_kiri = BattleshipCursorPosition[kiri][sumbu_x] - 1;
    bool cekDiKanan = true;
    bool belum_sampai_kiri = true;   
    bool belum_sampai_kanan = true;   
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = 1; i <= 5 && (belum_sampai_kanan || belum_sampai_kiri) && !sudah_menemukan_posisi_kosong; i++){
        bool belum_sampai_atas = true;
        bool belum_sampai_bawah = true;
        int baris_ke_atas = BattleshipCursorPosition[kiri][sumbu_y];
        int baris_ke_bawah = BattleshipCursorPosition[kiri][sumbu_y]+1;
        for(int j = 1; j <= 5 && (belum_sampai_atas || belum_sampai_bawah); j++){
            // Cek Bagian atas
            if(baris_ke_atas - 1< batas_atas_sumbu_y_grid){
                // Jika sudah melebihi ke atas
                belum_sampai_atas = false;
            }
            else{
                std::vector<int> BagianAtas = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_atas - 1};
                std::vector<int> BagianBawah = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_atas};
                if(apakahUdahDitempati(BagianAtas) || apakahUdahDitempati(BagianBawah)){
                    baris_ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }

            }
            // Cek Bagian bawah
            if(baris_ke_bawah + 1> batas_bawah_sumbu_y_grid){
                // Jika sudah melebihi ke bawah
                belum_sampai_bawah = false;
            }
            else{
                std::vector<int> BagianAtas = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_bawah - 1};
                std::vector<int> BagianBawah = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_bawah};
                if(apakahUdahDitempati(BagianAtas) || apakahUdahDitempati(BagianBawah)){
                    baris_ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[kiri] = BagianAtas;
                    BattleshipCursorPosition[kanan] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
        }
        if(cekDiKanan) cekDiKanan = false;
        else if(kolom_ke_kanan + 1 < batas_kanan_sumbu_x_grid) cekDiKanan = true;
        kolom_ke_kanan += 1;
        kolom_ke_kiri -= 1;
        if(kolom_ke_kanan >= batas_kanan_sumbu_x_grid) belum_sampai_kanan = false;
        if(kolom_ke_kiri < batas_kiri_sumbu_x_grid) belum_sampai_kiri = false;
    }
    if(sudah_menemukan_posisi_kosong){
        apakah_bisa_rotasi = true;
        CetakBattleshipVertikal(posisi_awal_x, posisi_awal_y);
    }
}
