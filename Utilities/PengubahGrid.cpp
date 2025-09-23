#include <iostream>
#include <string>
#include "../PlayerGrid.hpp"
#include "PlayerInput.hpp"
using namespace std;

const int beda_kolom_pada_grid = 26;
const int beda_per_baris = 260;
const int beda_baris_pada_grid = 3380;

void UbahGridSesuaiKursor(std::string& grid, int sumbu_x, int sumbu_y, char karakter_pengganti){
    const int beda_letak_antarhashtag = 2;
    const int konstanta_kursor_awal = 1416;
    int posisi_yang_akan_diganti = konstanta_kursor_awal + sumbu_x*beda_kolom_pada_grid + sumbu_y*beda_baris_pada_grid;
    int banyaknya_hashtag = 2;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= banyaknya_hashtag; j++){
            grid[posisi_yang_akan_diganti] =  karakter_pengganti;
            posisi_yang_akan_diganti += beda_letak_antarhashtag;
        }
        int pemindah_ke_awal_baris_selanjutnya = 20;
        if(i < 5) {
            banyaknya_hashtag += beda_letak_antarhashtag;
            pemindah_ke_awal_baris_selanjutnya = 6 + (i-1)*4;
        }
        else if(i >= 6){
            banyaknya_hashtag -= beda_letak_antarhashtag;
            pemindah_ke_awal_baris_selanjutnya = 18 - (i-6)*4;
        }
        posisi_yang_akan_diganti = posisi_yang_akan_diganti + beda_per_baris - pemindah_ke_awal_baris_selanjutnya;
        
    }

}

 void KosongkanGrid(Player& player, int sumbu_x, int sumbu_y){
    const int konstanta_yang_dikosongkan_awal = 1146;
    int posisi_baris_yang_diganti = konstanta_yang_dikosongkan_awal + sumbu_x*beda_kolom_pada_grid + sumbu_y*beda_baris_pada_grid;
    for(int i = 1; i <= 12; i++){
        int posisi_kolom_yang_diganti = 0;
        for(int j = 1; j <= 12; j++){
            player.GridBattleShip[posisi_baris_yang_diganti + posisi_kolom_yang_diganti] = ' ';
            posisi_kolom_yang_diganti += 2;
        }
        posisi_baris_yang_diganti += beda_per_baris;
    }
}

void KembalikanGrid(Player& player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y){
    const int posisi_awal = 1144;
    int posisi_baris_yang_diganti = posisi_awal + posisi_awal_sumbu_x*beda_kolom_pada_grid + posisi_awal_sumbu_y*beda_baris_pada_grid;
    for(int baris = 1; baris <= 13; baris++){
        int posisi_kolom_yang_diganti = 0;
        for(int kolom = 1; kolom <= 13; kolom++){
            int posisi_yang_diganti = posisi_baris_yang_diganti + posisi_kolom_yang_diganti;
            player.GridBattleShip[posisi_yang_diganti] = player.GridAsli[posisi_yang_diganti];
            posisi_kolom_yang_diganti += 2;
        }
        posisi_baris_yang_diganti += beda_per_baris;
    }
}


void BuatTandaBulatPadaKapal(Player &player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y){
    const int spasi_pendek = 2;
    const int konstanta_O_awal = 1674;
    int posisi_awal_baris_yang_diganti = konstanta_O_awal + posisi_awal_sumbu_x*beda_kolom_pada_grid + posisi_awal_sumbu_y*beda_baris_pada_grid;
    for(int baris = 1; baris <= 8; baris++){
        int spasi_panjang = 12;
        if(baris == 1 || baris == 8) spasi_panjang = 2;
        else if(baris == 2 || baris == 7) spasi_panjang = 6;
        else if(baris == 3 || baris == 6) spasi_panjang = 10;
        player.GridBattleShip[posisi_awal_baris_yang_diganti] = 'O';
        player.GridBattleShip[posisi_awal_baris_yang_diganti + spasi_pendek + spasi_panjang] = 'O';
        if(baris <= 3 || baris >= 6){
            player.GridBattleShip[posisi_awal_baris_yang_diganti + spasi_pendek] = 'O';
            player.GridBattleShip[posisi_awal_baris_yang_diganti + 2*spasi_pendek + spasi_panjang] = 'O';
        } 

        posisi_awal_baris_yang_diganti += 260;
        if(baris < 3) posisi_awal_baris_yang_diganti -= 2;
        else if(baris > 5) posisi_awal_baris_yang_diganti += 2;
    }
}
void BuatKapalVertikalUkuran2 (Player &player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y){
    BuatTandaBulatPadaKapal(player, posisi_awal_sumbu_x, posisi_awal_sumbu_y);
    BuatTandaBulatPadaKapal(player, posisi_awal_sumbu_x, posisi_awal_sumbu_y + 1);

    const int posisi_awal = 1154;
    int posisi_awal_baris_yang_diganti = posisi_awal + posisi_awal_sumbu_x*beda_kolom_pada_grid + posisi_awal_sumbu_y*beda_baris_pada_grid;
    for(int baris = 1; baris <= 25; baris++){
        int batasKolom = 4;
        int posisi_kolom_yang_diganti = 0;
        bool adaSpasiPanjang = true;
        int spasiPanjang = 16;
        switch (baris)
        {
        case 1:
            adaSpasiPanjang = false;
            break;
        case 2:
            adaSpasiPanjang = false;
            batasKolom = 8;
            break;
        case 3: 
            batasKolom = 6;
            spasiPanjang = 8;
            break;
        case 4:
            spasiPanjang = 12;
            break;
        case 13:
            adaSpasiPanjang = false;
            batasKolom = 12;
            break;
        case 24:
            adaSpasiPanjang = false;
            batasKolom = 10;
            break;
        case 25:
            adaSpasiPanjang = false;
            batasKolom = 8;
            break;
        default:
            break;
        }
        int posisiYangDiganti = posisi_awal_baris_yang_diganti + posisi_kolom_yang_diganti;
        if(adaSpasiPanjang){
            if(baris == 3){
                for(int kolom = 1; kolom <= batasKolom; kolom++){
                    player.GridBattleShip[posisiYangDiganti] = '#';
                    if(kolom == 3){
                        posisiYangDiganti += spasiPanjang;
                    }
                    posisiYangDiganti += 2;
                }
            }
            else{
                for(int kolom = 1; kolom <= batasKolom; kolom++){
                    player.GridBattleShip[posisiYangDiganti] = '#';
                    if(kolom == 2){
                        posisiYangDiganti += spasiPanjang;
                    }
                    posisiYangDiganti += 2;
                    
                }
            }
        }
        else{
            for(int kolom = 1; kolom <= batasKolom; kolom++){
                player.GridBattleShip[posisiYangDiganti] = '#';
                posisiYangDiganti += 2;
            }
        }
        posisi_awal_baris_yang_diganti = posisi_awal_baris_yang_diganti + beda_per_baris;
        switch (baris)
        {
        case 1:
            posisi_awal_baris_yang_diganti -= 4;
            break;
        case 2:
            posisi_awal_baris_yang_diganti -= 2;
            break;
        case 4:
            posisi_awal_baris_yang_diganti -= 2;
            break;
        case 23:
            posisi_awal_baris_yang_diganti += 2;
            break;
        case 24:
            posisi_awal_baris_yang_diganti += 2;
            break;
        default:
            break;
        }    
    }
}

void BuatKapalHorizontalUkuran2 (Player &player, int posisi_awal_sumbu_x, int posisi_awal_sumbu_y){
    BuatTandaBulatPadaKapal(player, posisi_awal_sumbu_x, posisi_awal_sumbu_y);
    BuatTandaBulatPadaKapal(player, posisi_awal_sumbu_x + 1, posisi_awal_sumbu_y);
    const int konstanta_awal_kapal_horizontal = 1150;
    int posisi_awal_baris = konstanta_awal_kapal_horizontal + posisi_awal_sumbu_x*beda_kolom_pada_grid + posisi_awal_sumbu_y*beda_baris_pada_grid;
    for(int baris = 1; baris <= 12; baris++){
        int posisi_kolom = 0;
        int banyaknya_kolom = 5;
        int spasi_panjang_kedua = 18;
        bool ada_spasi_panjang = true;
        switch(baris){
            case 1: ada_spasi_panjang = false; banyaknya_kolom = 19; break;
            case 2: ada_spasi_panjang = false; banyaknya_kolom = 22; break;
            case 3:                            banyaknya_kolom = 6;  break;
            // Ini bakalan beda dikit urutan case nya
            case 9:
            case 4: spasi_panjang_kedua += 2; break;
            case 8:  
            case 7:  
            case 6:  
            case 5: spasi_panjang_kedua += 4;  break;
            //
            case 10:                           banyaknya_kolom = 6;  break;
            case 11: ada_spasi_panjang = false;banyaknya_kolom = 22; break;
            case 12: ada_spasi_panjang = false;banyaknya_kolom = 19; break;
        }
        if(ada_spasi_panjang){
            const int spasi_panjang_pertama = 20;
            for(int kolom = 1; kolom <= banyaknya_kolom; kolom++){
                if(kolom == 3){
                    player.GridBattleShip[posisi_awal_baris + posisi_kolom + spasi_panjang_pertama] = '#';
                }
                else if(kolom >= 4){
                    player.GridBattleShip[posisi_awal_baris + posisi_kolom + spasi_panjang_pertama + spasi_panjang_kedua] = '#';
                    posisi_kolom += 2;
                }
                else{
                    player.GridBattleShip[posisi_awal_baris + posisi_kolom] = '#';
                    posisi_kolom += 2;
                }
            }
        }
        else{
            for(int kolom = 1; kolom <= banyaknya_kolom; kolom++){
                player.GridBattleShip[posisi_awal_baris + posisi_kolom] = '#';
                posisi_kolom += 2;
            }
        }
        posisi_awal_baris = posisi_awal_baris + beda_per_baris;
        switch(baris){
            case 1: posisi_awal_baris -= 2; break;
            case 2: posisi_awal_baris -= 2; break;
            case 10: posisi_awal_baris += 2; break;
            case 11: posisi_awal_baris += 2; break;
        }
    }
}

void UpdateGridKarenaHit(Player& playerAsal){
    const int spasi_pendek = 2;
    const int konstanta_O_awal = 1674;
    int posisi_awal_baris_yang_diganti = konstanta_O_awal + playerAsal.kursor[sumbu_x]*beda_kolom_pada_grid + playerAsal.kursor[sumbu_y]*beda_baris_pada_grid;
    for(int baris = 1; baris <= 8; baris++){
        int spasi_panjang = 12;
        if(baris == 1 || baris == 8) spasi_panjang = 2;
        else if(baris == 2 || baris == 7) spasi_panjang = 6;
        else if(baris == 3 || baris == 6) spasi_panjang = 10;
        playerAsal.GridAsli[posisi_awal_baris_yang_diganti] = 'O';
        playerAsal.GridAsli[posisi_awal_baris_yang_diganti + spasi_pendek + spasi_panjang] = 'O';
        if(baris <= 3 || baris >= 6){
            playerAsal.GridAsli[posisi_awal_baris_yang_diganti + spasi_pendek] = 'O';
            playerAsal.GridAsli[posisi_awal_baris_yang_diganti + 2*spasi_pendek + spasi_panjang] = 'O';
        } 

        posisi_awal_baris_yang_diganti += 260;
        if(baris < 3) posisi_awal_baris_yang_diganti -= 2;
        else if(baris > 5) posisi_awal_baris_yang_diganti += 2;
    }
    playerAsal.GridYangSedangDipakaiKursor = playerAsal.GridAsli;
}



void UpdateGridKarenaMiss(Player &playerAsal){
    const int konstanta_samadengan_awal = 1932 + playerAsal.kursor[sumbu_x]*beda_kolom_pada_grid + playerAsal.kursor[sumbu_y]*beda_baris_pada_grid;
    const int jeda_pendek_antartanda = 2;
    int posisi_yang_diganti = konstanta_samadengan_awal;
    for(int i = 0; i < 6; i++){
        int jeda_panjang_antartanda = 0;
        if(i == 0 || i == 5) jeda_panjang_antartanda = 6;
        else if(i == 1 || i == 4) jeda_panjang_antartanda = 2;
        playerAsal.GridAsli[posisi_yang_diganti] = '=';
        playerAsal.GridAsli[posisi_yang_diganti + jeda_pendek_antartanda] = '=';
        playerAsal.GridAsli[posisi_yang_diganti + jeda_panjang_antartanda + jeda_pendek_antartanda] = '=';
        if(i != 3 && i != 2) playerAsal.GridAsli[posisi_yang_diganti + jeda_panjang_antartanda + jeda_pendek_antartanda + jeda_pendek_antartanda]= '=';
        posisi_yang_diganti += 260;
        if(i < 2){
            posisi_yang_diganti += 2;
        }
        else if(i >= 3){
            posisi_yang_diganti -= 2;
        }
    }
    playerAsal.GridYangSedangDipakaiKursor = playerAsal.GridAsli;
}

void UpdateGridKurangiHP(Player &player, int HPsetelahDikurangi){
    const int posisi_awal_HP = 5774;
    const int beda_karakter_per_HP = 8;
    const int banyaknya_baris_yang_diganti = 7;
    const int beda_per_karakter = 2;
    const int banyaknya_kolom = (HPsetelahDikurangi >= 3 ? 4 : 2);
    int posisi_awal_baris = posisi_awal_HP + HPsetelahDikurangi*beda_karakter_per_HP;
    for(int baris = 1; baris <= banyaknya_baris_yang_diganti; baris++){
        for(int kolom_yang_diganti = 0; kolom_yang_diganti <= banyaknya_kolom; kolom_yang_diganti+=2){
            player.GridAsli[posisi_awal_baris + kolom_yang_diganti] = '@';
            player.GridYangSedangDipakaiKursor[posisi_awal_baris + kolom_yang_diganti] = '@';
        }
        posisi_awal_baris += beda_per_baris;
    }
}

void UpdateGrid(Player &playerAsal, Player &playerTujuan, std::atomic<bool>&apakah_hit){
    UpdateGridJikaAdaKapalHancur(playerAsal, std::ref(playerTujuan));
    vector<int> posisi_yang_ditembak;
    posisi_yang_ditembak.reserve(2);
    posisi_yang_ditembak[sumbu_x] = playerAsal.kursor[sumbu_x];
    posisi_yang_ditembak[sumbu_y] = playerAsal.kursor[sumbu_y];
    playerAsal.PosisiYangUdahDitembak.push_back(std::move(posisi_yang_ditembak));
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    if(playerAsal.apakahAdaYangKena(playerTujuan)){
        playerAsal.PosisiYangKena.push_back({playerAsal.kursor[sumbu_x], playerAsal.kursor[sumbu_y]});
        UpdateGridKarenaHit(playerAsal);
        apakah_hit = true;
    }
    else{
        UpdateGridKarenaMiss(playerAsal);
        apakah_hit = false;
    } 
    playerAsal.resetCursor();
    UbahGridSesuaiKursor(playerAsal.GridYangSedangDipakaiKursor, playerAsal.kursor[sumbu_x], playerAsal.kursor[sumbu_y], '#');
}

void UpdateGridJikaAdaKapalHancur(Player playerAsal, Player &playerTujuan){
    if(playerAsal.apakahAdaYangKenaKapal(playerTujuan)){
        playerTujuan.HP -= 1;
        UpdateGridKurangiHP(std::ref(playerTujuan), playerTujuan.HP);
    }
}