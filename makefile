OBJS	= main.o Player.o Scene.o Sprite.o
SOURCE	= main.cpp Player.cpp Scene.cpp Sprite.cpp
HEADER	= Player.h Scene.h Sprite.h
OUT	= Game
CC	 = g++
FLAGS	 = -g -c -lsfml-graphics -lsfml-window -lsfml-system
LFLAGS	 = -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Player.o: Player.cpp
	$(CC) $(FLAGS) Player.cpp 

Scene.o: Scene.cpp
	$(CC) $(FLAGS) Scene.cpp 

Sprite.o: Sprite.cpp
	$(CC) $(FLAGS) Sprite.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
