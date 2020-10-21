UTIL=Moves.c PokeBox.c PokeDex.c Pokemon.c PokeType.c SaveManager.c SpriteManager.c Util.c
MAIN=Main.c
BINARY=pokemon

all:
	gcc -Wall $(MAIN) $(UTIL) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
