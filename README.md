# 🔢 2048 in C (Terminal Version)

This is a console-based recreation of the classic puzzle game **2048**, fully built in the **C programming language**. The project includes multiple game modes with different grid sizes and win conditions, and it runs directly in your terminal window using simple keyboard controls.

---

## 🧩 Game Modes

The game runs three modes sequentially, each with its own board size and target win tile:

- **Game 1**: 3x3 board — win by reaching tile **16**
- **Game 2**: 2x2 board — win by reaching tile **32**
- **Game 3**: 4x4 board — win by reaching tile **2048**

---

## 🕹️ Controls

You control the game using the following keys:

N / n – New Game
R / r – Move Right
L / l – Move Left
U / u – Move Up
D / d – Move Down
E / e – Exit the game

Each move slides the tiles in the selected direction. If two matching numbers collide, they merge into one and increase your score. After each valid move, a new tile (2 or 4) appears in a random empty cell.

---

## 📦 Features

- ✅ Multiple board sizes: 2x2, 3x3, and 4x4
- ✅ Random tile generation after every move
- ✅ Merging and scoring logic identical to original 2048
- ✅ Win condition detection per mode
- ✅ Game over detection when no valid moves are left
- ✅ Score and best score tracking during each game

---

## ⚙️ How to Compile and Run

1. Make sure you have a C compiler like **GCC** installed.
2. Open a terminal and navigate to the project folder.
3. Compile the game using:

   ```bash
   gcc -o game2048 main.c game.c board.c menu.c
Run the compiled program:
./game2048

✅ This game is entirely terminal-based. No graphical interface is required.

🧠 Educational Purpose

This game was built as a course project to practice:

C fundamentals (arrays, pointers, memory layout)

Terminal I/O

Game state and logic management

Modular C programming (multiple source/header files)

It demonstrates how a popular puzzle game can be recreated using only text and logic.

👨‍💻 File Structure
.
├── main.c       # Entry point of the program, runs the 3 game modes
├── game.c       # Core game loop, input handling, score and logic
├── board.c      # Functions to initialize, update, and print the board
├── menu.c       # Menu and user input
├── game.h
├── board.h
├── menu.h

🙌 Author
Created by Sheera as part of a C programming course.
Inspired by the original 2048 game by Gabriele Cirulli.

🎯 Good luck and try to reach 2048!
