# GameEngine

## How to run the Program:
Just run `make run`, and make sure you have sfml. Easy way to get it on debian is `sudo apt-get install libsfml-dev`

## Dependencies
SFML, g++, make

## Description
This project is a game engine that I made using SFML and C++. It works like other game engines by using sprites and updating their locations, and then drawing them, all in different steps. I have added boundary detection, as the cat sprites will bounce from the top, left, and right borders, and collision detection, as they will bounce when touching the player-controlled platform sprite.

The sample game is trying not to let the cat sprites fall off the screen by bouncing them up with your player-controlled platform sprite. You can move this sprite using A and D to go left and right. If the cat sprite does fall off the screen (or even if it doesn't), you can press any key to spawn in another one. 

As for the engine, it is easy to customize to needs, as sprites are supported, and how they act is also easily changed. For example, you can see that I stopped the cat sprites from bouncing off of the bottom border just by commenting out a part of the code in Scene.h. It is easy to change sprites' images, dimensions, and rotations.  It is even easy to change to wrapping instead of bouncing if it is more desired.