# Terminal Battleship 🚢💥

A classic Battleship board game playable entirely within your terminal, built fully with C++. The project is made with the purpose of completing a task.

This project is a terminal-based implementation of the classic strategy game, Battleship. Players face off against an opponent, strategically placing their fleet of ships on a grid. The objective is simple: hunt down and sink the enemy's entire fleet before they sink yours.

## 🚀 Screenshot


![Example of the game in action](https://github.com/Mielel/Terminal_Battleship/blob/main/Assets/Main-Menu.png)
![Example of the game in action](https://github.com/Mielel/Terminal_Battleship/blob/main/Assets/Battleship-Placement.png)
## ✨ Key Features

* **Classic Gameplay:**  Strategically place and rotate each ship using `WASD` for movement, `R` for rotation, and `Enter` to confirm. Made a mistake? `Backspace` lets you reset the previous ship.
    * **Randomizer Mode:** Get into the action quickly by letting the program automatically randomize your fleet's positions.


## ⚙️ Installation and Setup

Follow these steps to get the game running on your local machine.

### Prerequisites

Ensure you have the necessary compiler/interpreter installed on your system, which is g++.
### Running the Game

1.  **Clone the repository**
    ```bash
    git clone https://github.com/Mielel/Terminal_Battleship
    ```
2.  **Navigate to the project directory**
    ```bash
    cd Terminal_Battleship
    ```
3.  **Compile (if necessary) and run the program**
    ```bash
    g++ main.cpp Utilities/Accepting-input.cpp Animation/Utilities.cpp Animation/Main-Menu.cpp Utilities/PengubahGrid.cpp PlayerDefinition.cpp Animation/Tampilkan-Hit-or-Miss.cpp Utilities/Pencetak-Grid.cpp BattleshipDefinition.cpp BattleshipHorizontalMove.cpp BattleshipVerticalMove.cpp Animation/SelectMode.cpp Animation/Tutorial.cpp Animation/Winning.cpp -o hasil
    ./hasil
    ```

## 🎮 How to Play

1.  **Choose Placement Mode:** At the start, you will be prompted to choose between `manual` or `randomizer` mode for placing your ships.
2.  **Position Your Fleet (Manual Mode):**
    * Use `W`, `A`, `S`, `D` to move the current ship.
    * Press `R` to rotate the ship (toggling between horizontal and vertical).
    * Press `Backspace` to undo the placement of the previous ship.
    * Press `Enter` to confirm a ship's position.
3.  **Start the Battle:** Once all ships are placed, the game begins.
4.  **Fire at the Enemy:** Enter coordinates to target a position on the enemy's grid.
    * `O` indicates a hit.
    * `X` indicates a miss.
5.  **Win or Lose:** The game continues in turns until one player has sunk all of the opponent's ships.
6.  **Play Again?** After the game ends, press `Enter` to exit the program, or press any other key to start a new game.

## ‼️ Bugs
There are still some bugs in this project. I wouldn't fix those bugs since this project is mainly a private one for finishing a task from college. The bugs:
1. Since this uses ANSI escape codes, it is fully dependent on the terminal. It is mandatory to keep the terminal size until it can show the whole game.
2. Some logic bugs in moving the cursor when choosing a point to shoot. 
