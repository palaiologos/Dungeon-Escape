output: main.o Space.o Game.o Helper_Functions.o Starting_Room.o Jail_Room.o The_Pit.o Kitchen.o Basement.o Outside.o Player.o Item.o
	g++ main.o Space.o Game.o Helper_Functions.o Starting_Room.o Jail_Room.o The_Pit.o Kitchen.o Basement.o Outside.o Player.o Item.o -o p5

main.o: main.cpp
	g++ -c main.cpp

Space.o: Space.cpp
	g++ -c Space.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Helper_Functions.o: Helper_Functions.cpp
	g++ -c Helper_Functions.cpp

Starting_Room.o: Starting_Room.cpp
	g++ -c Starting_Room.cpp

Jail_Room.o: Jail_Room.cpp
	g++ -c Jail_Room.cpp

The_Pit.o: The_Pit.cpp
	g++ -c The_Pit.cpp

Kitchen.o: Kitchen.cpp
	g++ -c Kitchen.cpp

Basement.o: Basement.cpp
	g++ -c Basement.cpp

Outside.o: Outside.cpp
	g++ -c Outside.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

clean: rm *.o p5
