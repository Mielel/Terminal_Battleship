#include <iostream>
#include <string>
#include <atomic>
#include <conio.h>
#include "../Animation/All-Animation.hpp"
#include "../PlayerGrid.hpp"
#include "PlayerInput.hpp"

void Enter_to_Begin_Game(std::atomic<bool>& apakah_enter_belum_dipencet){
    std::string buffer;
    std::getline(std::cin, buffer);
    apakah_enter_belum_dipencet = false;

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    Erase_Screen();
}

void ShowCursorMovement(std::atomic<bool>& apakah_sudah_mulai, Player &player){
    TransisiAwalTampilkanGrid(player.GridYangSedangDipakaiKursor);
    while(apakah_sudah_mulai){
        TampilkanGrid(player.GridYangSedangDipakaiKursor);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    while(_kbhit()){
        _getch();
    }
    Erase_Screen();
}

void TungguSampaiKlikSuatuKey(std::atomic<bool>& masih_belum_pencet_apa_pun){
    while(!_kbhit()){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    while(_kbhit()){
        _getch();
    }
    masih_belum_pencet_apa_pun = false;
}

void InputMetode(pilihCara& metode){
    tampilkanMetodeYangDipilihSaatIni(metode);
    while(true)
    {
        if(_kbhit){
            char input = _getch();
            if(input == '1'){
                metode = random;
                tampilkanMetodeYangDipilihSaatIni(metode);
            }
            else if(input == '2'){
                metode = manual;
                tampilkanMetodeYangDipilihSaatIni(metode);
            }
            else if(input == '\r' && metode != null){
                break;
            }

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    while (_kbhit()) {
        _getch(); // Ambil karakter dan buang (jangan lakukan apa-apa dengannya)
    }
    Erase_Screen();
}

void GettingCursorMovement(std::atomic<bool>& bisa_gerakin_kursor, Player& playerAsal, Player playerTujuan){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    while(bisa_gerakin_kursor){
        if(_kbhit()){
            char input = _getch();
            if(input == 'w' || input =='W') playerAsal.moveUp();
            else if(input == 'a' || input == 'A') playerAsal.moveLeft();
            else if(input == 's' || input == 'S') playerAsal.moveDown();
            else if(input == 'd' || input == 'D') playerAsal.moveRight();
            else if(input == '\r') {
                bisa_gerakin_kursor = false;
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    while (_kbhit()) {
        _getch(); // Ambil karakter dan buang (jangan lakukan apa-apa dengannya)
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void GettingBattleshipCursorMovement(std::atomic<bool>& bisa_gerakin_kursor, Player &player){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int posisiBattleshipYangDiedit = 0;
    const int JUMLAH_KAPAL = 4;
    while (bisa_gerakin_kursor){
        if(_kbhit){
            char input = _getch();
            if(input == 'w' || input =='W') player.Kapal[posisiBattleshipYangDiedit].moveUp();
            else if(input == 'a' || input == 'A') player.Kapal[posisiBattleshipYangDiedit].moveLeft();
            else if(input == 's' || input == 'S') player.Kapal[posisiBattleshipYangDiedit].moveDown();
            else if(input == 'd' || input == 'D') player.Kapal[posisiBattleshipYangDiedit].moveRight();
            else if(input == 'r' || input == 'R') player.Kapal[posisiBattleshipYangDiedit].rotateShip();
            else if(input == '\b' && posisiBattleshipYangDiedit > 0) {
                player.Kapal[posisiBattleshipYangDiedit].kembaliKeAturKapalSebelumnya();
                posisiBattleshipYangDiedit -= 1;
            }
            else if(input == '\r') {
                player.Kapal[posisiBattleshipYangDiedit].UpdateFixBattleshipPosition();
                posisiBattleshipYangDiedit++;
                if(posisiBattleshipYangDiedit < JUMLAH_KAPAL){
                    player.Kapal[posisiBattleshipYangDiedit].resetBattleshipCursor();
                }
                else{
                    bisa_gerakin_kursor = false;
                    break;
                }
        }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    while (_kbhit()) {
        _getch();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void ShowBattleshipCursor(std::atomic<bool>& apakah_sudah_mulai, Player &player){
    TransisiAwalTampilkanGrid(player.GridBattleShip);
    while(apakah_sudah_mulai){
        TampilkanGrid(player.GridBattleShip);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    Erase_Screen();
}