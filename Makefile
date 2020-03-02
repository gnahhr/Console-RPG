DIR = ./headers

game.exe: main.o $(DIR)/characters.o $(DIR)/overworld.o $(DIR)/battle-system.o
	g++ main.o $(DIR)/characters.o $(DIR)/overworld.o $(DIR)/battle-system.o -o game.exe

main.o: main.cpp $(DIR)/characters.cpp $(DIR)/overworld.cpp $(DIR)/battle-system.o
	g++ -c main.cpp

overworld.o: $(DIR)/characters.cpp $(DIR)/overworld.cpp $(DIR)/overworld.h
	g++ -c overworld.cpp

characters.o: $(DIR)/characters.cpp $(DIR)/characters.h
	g++ -c characters.cpp

battle-system.o: $(DIR)/battle-system.cpp $(DIR)/battle-system.h $(DIR)/characters.cpp
	g++ -c battle-system.cpp

clean:
	rm *.o $(DIR)/*.o