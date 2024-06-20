# Project Introduction

This is a game engine created using SFML and C++. It works like other game engines by using sprites, updating their locations, and then drawing them in different steps. The engine includes boundary detection, allowing cat sprites to bounce off the top, left, and right borders, and collision detection, which makes them bounce when touching the player-controlled platform sprite.

The sample game involves preventing the cat sprites from falling off the screen by bouncing them up with a player-controlled platform sprite, which can be moved left and right using the A and D keys. If a cat sprite falls off the screen or if you want to spawn another one, you can press any key.

The engine is designed to be easily customizable, supporting different sprites and their behaviors. For example, you can modify how sprites interact with borders or change their images, dimensions, and rotations.

# How to Compile

To compile the project, ensure you have SFML, g++, and make installed on your system.

### Debian-based Systems

1. Install SFML: `sudo apt-get install libsfml-dev`
2. Compile the project: `make`

# How to Run

Once compiled, you can run the program using the following command:

```sh
make run
```
# Input/Output (For Sample Game)

### Input
- **A Key: Move the platform sprite to the left.**
- **D Key: Move the platform sprite to the right.**
- **Any Key: Spawn a new cat sprite.**

### Output
**The game displays a player-controlled platform sprite and multiple cat sprites. The objective is to keep the cat sprites from falling off the screen by bouncing them with the platform sprite.**

# Team
This project was created as an assignment by a single developer for CS438.

