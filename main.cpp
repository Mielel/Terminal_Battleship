#include <iostream>
#include <thread>
#include <atomic>
#include "Animation/All-Animation.hpp"
#include "PlayerGrid.hpp"
#include "Utilities/PlayerInput.hpp"



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::atomic<bool> flagAnimasiMainMenu = true;
    std::thread mengOutputAnimasi(Main_Menu, std::ref(flagAnimasiMainMenu));
    std::thread menerimaInput(Enter_to_Begin_Game, std::ref(flagAnimasiMainMenu));

    mengOutputAnimasi.join();
    menerimaInput.join();
    Player Player_1(1), Player_2(2);
    pilihCara placement_mode = null;
    // Pilih Mode
    std::thread pilihMode(InputMetode, std::ref(placement_mode));
    pilihMode.join();

    // Tutorial
    std::atomic<bool> masih_di_screen_tutorial = true;
    std::thread merenderTutorial(tampilkanTutorial, std::ref(masih_di_screen_tutorial), placement_mode);
    std::thread tungguSampaiKlik(TungguSampaiKlikSuatuKey,  std::ref(masih_di_screen_tutorial));
    tungguSampaiKlik.join();
    merenderTutorial.join();
    
    if(placement_mode == manual){
        std::atomic<bool> giliranPlayer1MeletakkanKapal = true;
        std::thread firstPlayerShipPlacement(GettingBattleshipCursorMovement, std::ref(giliranPlayer1MeletakkanKapal), std::ref(Player_1));
        std::thread firstPlayerShipScreen(ShowBattleshipCursor, std::ref(giliranPlayer1MeletakkanKapal), std::ref(Player_1));
        firstPlayerShipPlacement.join();
        firstPlayerShipScreen.join();
    
        std::atomic<bool> giliranPlayer2MeletakkanKapal = true;
        std::thread secondPlayerShipPlacement(GettingBattleshipCursorMovement, std::ref(giliranPlayer2MeletakkanKapal), std::ref(Player_2));
        std::thread secondPlayerShipScreen(ShowBattleshipCursor, std::ref(giliranPlayer2MeletakkanKapal), std::ref(Player_2));
        secondPlayerShipPlacement.join();
        secondPlayerShipScreen.join();
    }
    else{
        std::thread loading(tampilkanRandomizerLoading);
        Player_1.placeShips();
        Player_2.placeShips();
        loading.join();
    }
    std::atomic<bool> masih_belum_ada_yang_kalah = true;
    tampilkanStart();
    while(masih_belum_ada_yang_kalah){
        // First Player Movement
        std::atomic<bool> GiliranP1 = true;
        while(GiliranP1){
            std::atomic<bool> BisaGerakkanKursorP1 = true;
            std::thread getFirstPlayerCursorMoves(GettingCursorMovement, std::ref(BisaGerakkanKursorP1), std::ref(Player_1), Player_2);
            std::thread firstPlayerScreen(ShowCursorMovement, std::ref(BisaGerakkanKursorP1), std::ref(Player_1));
            getFirstPlayerCursorMoves.join();
            firstPlayerScreen.join();
            tampilkanHitOrMiss(Player_1, Player_2);
            UpdateGrid(std::ref(Player_1), std::ref(Player_2), std::ref(GiliranP1));
            if(Player_2.HP == 0){
                masih_belum_ada_yang_kalah = false;
                break;
            }
        }
        if(!masih_belum_ada_yang_kalah){
            break;
        }
        // Second Player Movement
        std::atomic<bool> GiliranP2 = true;
        while(GiliranP2){
            std::atomic<bool> BisaGerakkanKursorP2 = true;
            std::thread getSecondPlayerCursorMoves(GettingCursorMovement, std::ref(BisaGerakkanKursorP2), std::ref(Player_2), Player_1);
            std::thread secondPlayerScreen(ShowCursorMovement, std::ref(BisaGerakkanKursorP2), std::ref(Player_2));
            getSecondPlayerCursorMoves.join();
            secondPlayerScreen.join();
            tampilkanHitOrMiss(Player_2, Player_1);
            UpdateGrid(std::ref(Player_2), std::ref(Player_1), std::ref(GiliranP2));
            if(Player_1.HP == 0){
                masih_belum_ada_yang_kalah = false;
                break;
            }
        }
        if(!masih_belum_ada_yang_kalah){
            break;
        }
    }
    if(Player_1.HP == 0){
        tampilkanPemenang(2);
    }
    else{
        tampilkanPemenang(1);
    }
    return 0;
}

