# Terminal Battleship 🚢💥

A classic Battleship board game playable entirely within your terminal, built with [Your Programming Language, e.g., Python/C++/Java].

This project is a terminal-based implementation of the classic strategy game, Battleship. Players face off against a computer opponent, strategically placing their fleet of ships on a grid. The objective is simple: hunt down and sink the enemy's entire fleet before they sink yours.

## 🚀 Screenshot / GIF

_Displaying a visual of your project is highly recommended. It helps others quickly understand what you've built._

![Example of the game in action](your-link-to-screenshot.png)

## ✨ Key Features

* **Classic Gameplay:** Experience the traditional Battleship game in a retro terminal interface.
* **Flexible Ship Placement Modes:**
    * **Manual Mode:** Strategically place and rotate each ship using `WASD` for movement, `R` for rotation, and `Enter` to confirm. Made a mistake? `Backspace` lets you reset the previous ship.
    * **Randomizer Mode:** Get into the action quickly by letting the program automatically randomize your fleet's positions.
* **Computer Opponent (AI):** Test your strategy against a computer opponent that will fire at your grid.
* **Play Again Option:** Once a game concludes, you can choose to start a new match or exit the program.

## 💻 Tech Stack

* **Language:** C++
* **Libraries:** iosteam, thread, string, chrono, vector, and random

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
4.  **Fire at the Enemy:** Enter coordinates (e.g., `A5`, `C10`) to target a position on the enemy's grid.
    * `O` indicates a miss.
    * `X` indicates a hit.
5.  **Win or Lose:** The game continues in turns until one player has sunk all of the opponent's ships.
6.  **Play Again?** After the game ends, press `Enter` to exit the program, or press any other key to start a new game.
