#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
enum koordinat{
    sumbu_x = 0,
    sumbu_y = 1
};
enum rotasi{
    vertikal = 0,
    horizontal = 1
};
enum bagianKapal{
    atas = 0,
    bawah = 1,
    kiri = 0,
    kanan = 1
};
enum class CellState {
    kosong,
    terisi
};
enum pilihCara{
    null = 0,
    manual = 1,
    random = 2
};

const int batas_bawah_sumbu_y_grid = 5;
const int batas_kanan_sumbu_x_grid = 5;
const int batas_atas_sumbu_y_grid = 0;
const int batas_kiri_sumbu_x_grid = 0;

class Player;
class Battleship;

class Battleship{
    private:
    public:
        Player &owner;
        std::vector<std::vector<int>> BattleshipCursorPosition;
        rotasi RotasiBattleship = vertikal;
        void UpdateFixBattleshipPosition();
        void moveUpKapalVertikal();
        void moveLeftKapalVertikal();
        void moveDownKapalVertikal();
        void moveRightKapalVertikal();
        void moveUpKapalHorizontal();
        void moveLeftKapalHorizontal();
        void moveDownKapalHorizontal();
        void moveRightKapalHorizontal();
        void moveUp();
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotateShip();
        void kembaliKeAturKapalSebelumnya();
        void resetBattleshipCursor();
        void rotateVertikalToHorizontal(bool &apakah_bisa_rotasi);
        void rotateHorizontalToVertikal(bool &apakah_bisa_rotasi);
        void CetakBattleshipVertikal(int posisi_awal_x[], int posisi_awal_y[]);
        void CetakBattleshipHorizontal(int posisi_awal_x[], int posisi_awal_y[]);
        bool apakahUdahDitempati(std::vector<int>posisi);
        Battleship(Player& pemilik) : owner(pemilik){}
};
    
class Player{
    private:
    int playerKeBerapa;
    public:
    int HP = 4;
    int kursor[2] = {0,0};
    std::vector<Battleship> Kapal;
    std::vector<std::vector<int>> PosisiBattleship;
    std::vector<std::vector<int>> PosisiYangUdahDitembak;
    std::vector<std::vector<int>> PosisiYangKena;
    std::string GridAsli;
    std::string GridBattleShip;
    std::string GridYangSedangDipakaiKursor;     
    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void tampilkanHit();
    void resetCursor();
    void placeShips();
    bool apakahAdaYangKena(Player playerTujuan);
    bool apakahAdaYangKenaKapal(Player playerTujuan);
    bool isPosisiSudahDitembak(int posisi_x, int posisi_y);
    Player(int playerKe_X);
};