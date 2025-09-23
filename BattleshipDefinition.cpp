#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include "PlayerGrid.hpp"
#include "Utilities/PlayerInput.hpp"

bool Battleship::apakahUdahDitempati(std::vector<int> posisi){
    if(this->owner.PosisiBattleship.empty()){
        return false;
    }
    else{
        for(size_t i = 0; i < this->owner.PosisiBattleship.size(); i++){
            if(owner.PosisiBattleship[i][sumbu_x] == posisi[sumbu_x] && owner.PosisiBattleship[i][sumbu_y] == posisi[sumbu_y]){
                return true;
            }
        }
    }
    return false;    
}

void Battleship::resetBattleshipCursor(){
    if(this->owner.PosisiBattleship.empty()){
        this->BattleshipCursorPosition.push_back({0, 0});
        this->BattleshipCursorPosition.push_back({0,1});
    }
    else{
        bool belum_ada_posisi_kosong = true;
        for(int baris = 0; baris < batas_bawah_sumbu_y_grid - 1 && belum_ada_posisi_kosong; baris++){    
            for(int kolom = 0; kolom < batas_kanan_sumbu_x_grid && belum_ada_posisi_kosong; kolom++){
                std::vector<int> bagianAtas = {kolom, baris};
                std::vector<int> bagianBawah = {kolom, baris + 1};
                if(!apakahUdahDitempati(bagianAtas) && !apakahUdahDitempati(bagianBawah)){
                    belum_ada_posisi_kosong = false;
                    this->BattleshipCursorPosition.push_back({kolom, baris});
                    this->BattleshipCursorPosition.push_back({kolom, baris+1});
                }
            }
        }
    }
    KosongkanGrid(owner, BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]);
    KosongkanGrid(owner, BattleshipCursorPosition[bawah][sumbu_x], BattleshipCursorPosition[bawah][sumbu_y]);
    BuatKapalVertikalUkuran2(owner, BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]);
}

void Battleship::moveDown(){
    if(RotasiBattleship == vertikal){
        moveDownKapalVertikal();
    }
    else{
        moveDownKapalHorizontal();
    }
}

void Battleship::moveUp(){
    if(RotasiBattleship == vertikal){
        moveUpKapalVertikal();
    }
    else{
        moveUpKapalHorizontal();
    }
}

void Battleship::moveRight(){
    if(RotasiBattleship == vertikal){
        moveRightKapalVertikal();
    }
    else{
        moveRightKapalHorizontal();
    }
}

void Battleship::moveLeft(){
    if(RotasiBattleship == vertikal){
        moveLeftKapalVertikal();
    }
    else{
        moveLeftKapalHorizontal();
    }
}


void Battleship::kembaliKeAturKapalSebelumnya(){
    KembalikanGrid(owner, BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]);
    KembalikanGrid(owner, BattleshipCursorPosition[bawah][sumbu_x], BattleshipCursorPosition[bawah][sumbu_y]);
    BattleshipCursorPosition.pop_back();
    BattleshipCursorPosition.pop_back();
    owner.PosisiBattleship.pop_back();
    owner.PosisiBattleship.pop_back();
}


void Battleship::UpdateFixBattleshipPosition(){
    owner.PosisiBattleship.push_back({BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]});
    owner.PosisiBattleship.push_back({BattleshipCursorPosition[bawah][sumbu_x], BattleshipCursorPosition[bawah][sumbu_y]});
}

void Battleship::rotateShip(){
    bool apakah_bisa_rotasi = false;
    if(RotasiBattleship == vertikal){
        rotateVertikalToHorizontal(apakah_bisa_rotasi);
        if(apakah_bisa_rotasi) RotasiBattleship = horizontal;
    }
    else{
        rotateHorizontalToVertikal(apakah_bisa_rotasi);
        if(apakah_bisa_rotasi) RotasiBattleship = vertikal;
    }
}

void Battleship::CetakBattleshipVertikal(int posisi_awal_x[], int posisi_awal_y[]){
    KembalikanGrid(owner, posisi_awal_x[atas], posisi_awal_y[atas]);
    KembalikanGrid(owner, posisi_awal_x[bawah], posisi_awal_y[bawah]);
    KosongkanGrid(owner, BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]);
    KosongkanGrid(owner, BattleshipCursorPosition[bawah][sumbu_x], BattleshipCursorPosition[bawah][sumbu_y]);
    BuatKapalVertikalUkuran2(owner, BattleshipCursorPosition[atas][sumbu_x], BattleshipCursorPosition[atas][sumbu_y]);
}

void Battleship::CetakBattleshipHorizontal(int posisi_awal_x[], int posisi_awal_y[]){
    KembalikanGrid(owner, posisi_awal_x[kiri], posisi_awal_y[kiri]);
    KembalikanGrid(owner, posisi_awal_x[kanan], posisi_awal_y[kanan]);
    KosongkanGrid(owner, BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kiri][sumbu_y]);
    KosongkanGrid(owner, BattleshipCursorPosition[kanan][sumbu_x], BattleshipCursorPosition[kanan][sumbu_y]);
    BuatKapalHorizontalUkuran2(owner, BattleshipCursorPosition[kiri][sumbu_x], BattleshipCursorPosition[kiri][sumbu_y]);
}