#include "PlayerGrid.hpp"
#include "Utilities/PlayerInput.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

void Battleship::moveDownKapalVertikal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[bawah][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[atas][sumbu_y], BattleshipCursorPosition[bawah][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[atas][sumbu_x];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[bawah][sumbu_y]+1; i < batas_bawah_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i++){
        std::vector<int> BagianAtas = {BattleshipCursorPosition[atas][sumbu_x], i-1};
        std::vector<int> BagianBawah = {BattleshipCursorPosition[bawah][sumbu_x], i};
        if(!apakahUdahDitempati(BagianAtas) && !apakahUdahDitempati(BagianBawah)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[atas] = BagianAtas; 
            BattleshipCursorPosition[bawah] = BagianBawah;
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kanan < batas_kanan_sumbu_x_grid){
                BagianAtas[sumbu_x] = ke_kanan;
                BagianBawah[sumbu_x] = ke_kanan;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_kanan += 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kanan = false;
            }
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                BagianAtas[sumbu_x] = ke_kiri;
                BagianBawah[sumbu_x] = ke_kiri;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_kiri -= 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
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
        CetakBattleshipVertikal(posisi_awal_x, posisi_awal_y);
    }
}

void Battleship::moveUpKapalVertikal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[bawah][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[atas][sumbu_y], BattleshipCursorPosition[bawah][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[atas][sumbu_x];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[atas][sumbu_y]-1; i >= batas_atas_sumbu_y_grid && !sudah_menemukan_posisi_kosong; i--){
        std::vector<int> BagianAtas = {BattleshipCursorPosition[atas][sumbu_x], i};
        std::vector<int> BagianBawah = {BattleshipCursorPosition[bawah][sumbu_x], i+1};
        if(!apakahUdahDitempati(BagianAtas) && !apakahUdahDitempati(BagianBawah)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[atas] = BagianAtas; 
            BattleshipCursorPosition[bawah] = BagianBawah;
            break;
        }
        int ke_kiri = ke_tengah-1;
        int ke_kanan = ke_tengah+1;
        bool sampai_kiri = true;
        bool sampai_kanan = true;
        for(int j = 1; j <= 4 && (sampai_kiri || sampai_kanan); j++){
            if(ke_kiri >= batas_kiri_sumbu_x_grid){
                BagianAtas[sumbu_x] = ke_kiri;
                BagianBawah[sumbu_x] = ke_kiri;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_kiri -= 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_kiri = false;
            }
            if(ke_kanan < batas_kanan_sumbu_x_grid){
                BagianAtas[sumbu_x] = ke_kanan;
                BagianBawah[sumbu_x] = ke_kanan;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_kanan += 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
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
        CetakBattleshipVertikal(posisi_awal_x, posisi_awal_y);
    }
}

void Battleship::moveRightKapalVertikal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[bawah][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[atas][sumbu_y], BattleshipCursorPosition[bawah][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[atas][sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[atas][sumbu_x]+1; i < batas_kanan_sumbu_x_grid && !sudah_menemukan_posisi_kosong; i++){
        std::vector<int> BagianAtas = {i, BattleshipCursorPosition[atas][sumbu_y]};
        std::vector<int> BagianBawah = {i, BattleshipCursorPosition[bawah][sumbu_y]};
        if(!apakahUdahDitempati(BagianAtas) && !apakahUdahDitempati(BagianBawah)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[atas] = BagianAtas; 
            BattleshipCursorPosition[bawah] = BagianBawah;
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_atas >= batas_atas_sumbu_y_grid){
                BagianAtas[sumbu_y] = ke_atas;
                BagianBawah[sumbu_y] = ke_atas+1;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_bawah+1 < batas_bawah_sumbu_y_grid){
                BagianAtas[sumbu_y] = ke_bawah;
                BagianBawah[sumbu_y] = ke_bawah+1;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
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
        CetakBattleshipVertikal(posisi_awal_x, posisi_awal_y);
    }
}

void Battleship::moveLeftKapalVertikal(){
    int posisi_awal_x[2] = {BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[bawah][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[atas][sumbu_y], BattleshipCursorPosition[bawah][sumbu_y]};
    const int ke_tengah = BattleshipCursorPosition[atas][sumbu_y];
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = BattleshipCursorPosition[atas][sumbu_x]-1; i >= batas_kiri_sumbu_x_grid && !sudah_menemukan_posisi_kosong; i--){
        std::vector<int> BagianAtas = {i, BattleshipCursorPosition[atas][sumbu_y]};
        std::vector<int> BagianBawah = {i, BattleshipCursorPosition[bawah][sumbu_y]};
        if(!apakahUdahDitempati(BagianAtas) && !apakahUdahDitempati(BagianBawah)){
            sudah_menemukan_posisi_kosong = true;
            BattleshipCursorPosition[atas] = BagianAtas; 
            BattleshipCursorPosition[bawah] = BagianBawah;
            break;
        }
        int ke_atas = ke_tengah-1;
        int ke_bawah = ke_tengah+1;
        bool sampai_atas = true;
        bool sampai_bawah = true;
        for(int j = 1; j <= 4 && (sampai_atas || sampai_bawah); j++){
            if(ke_bawah+1 < batas_bawah_sumbu_y_grid){
                BagianAtas[sumbu_y] = ke_bawah;
                BagianBawah[sumbu_y] = ke_bawah+1;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }
            }
            else{
                sampai_atas = false;
            }
            if(ke_atas >= batas_atas_sumbu_y_grid){
                BagianAtas[sumbu_y] = ke_atas;
                BagianBawah[sumbu_y] = ke_atas+1;
                if(apakahUdahDitempati(BagianAtas)  || apakahUdahDitempati(BagianBawah)){
                    ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianAtas;
                    BattleshipCursorPosition[bawah] = BagianBawah;
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
        CetakBattleshipVertikal(posisi_awal_x, posisi_awal_y);
    }
}

void Battleship::rotateVertikalToHorizontal(bool& apakah_bisa_rotasi){
    int posisi_awal_x[2] = {BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[bawah][sumbu_x]};
    int posisi_awal_y[2] = {BattleshipCursorPosition[atas][sumbu_y], BattleshipCursorPosition[bawah][sumbu_y]};
    int kolom_ke_kanan = BattleshipCursorPosition[atas][sumbu_x];   
    int kolom_ke_kiri = BattleshipCursorPosition[atas][sumbu_x] - 1;
    bool cekDiKanan = true;
    bool belum_sampai_kiri = true;   
    bool belum_sampai_kanan = true;   
    bool sudah_menemukan_posisi_kosong = false;
    for(int i = 1; i <= 5 && (belum_sampai_kanan || belum_sampai_kiri) && !sudah_menemukan_posisi_kosong; i++){
        bool belum_sampai_atas = true;
        bool belum_sampai_bawah = true;
        int baris_ke_atas = BattleshipCursorPosition[bawah][sumbu_y];
        int baris_ke_bawah = BattleshipCursorPosition[bawah][sumbu_y]-1;
        if(cekDiKanan && kolom_ke_kanan + 1 >= batas_kanan_sumbu_x_grid){
            cekDiKanan = false;
            continue;
        }
        for(int j = 1; j <= 5 && (belum_sampai_atas || belum_sampai_bawah); j++){
            // Cek Bagian atas
            if(baris_ke_atas < batas_atas_sumbu_y_grid){
                // Jika sudah melebihi ke atas
                belum_sampai_atas = false;
            }
            else{
                std::vector<int> BagianKanan = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri)+1, baris_ke_atas};
                std::vector<int> BagianKiri = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_atas};
                if(apakahUdahDitempati(BagianKanan) || apakahUdahDitempati(BagianKiri)){
                    baris_ke_atas -= 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianKiri;
                    BattleshipCursorPosition[bawah] = BagianKanan;
                    sudah_menemukan_posisi_kosong = true;
                    break;
                }

            }
            // Cek Bagian bawah
            if(baris_ke_bawah + 1 > batas_bawah_sumbu_y_grid){
                // Jika sudah melebihi ke bawah
                belum_sampai_bawah = false;
            }
            else{
                std::vector<int> BagianKanan = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri)+1, baris_ke_bawah};
                std::vector<int> BagianKiri = {(cekDiKanan ? kolom_ke_kanan : kolom_ke_kiri), baris_ke_bawah};
                if(apakahUdahDitempati(BagianKanan) || apakahUdahDitempati(BagianKiri)){
                    baris_ke_bawah += 1;
                }
                else{
                    BattleshipCursorPosition[atas] = BagianKiri;
                    BattleshipCursorPosition[bawah] = BagianKanan;
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
        CetakBattleshipHorizontal(posisi_awal_x, posisi_awal_y);
    }
}