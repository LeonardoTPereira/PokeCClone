UTIL=Moves.c PokeBox.c PokeDex.c Pokemon.c PokeType.c SaveManager.c SpriteManager.c Util.c
MAIN=Main.c
BINARY=pokemon

all:
	gcc -Wall $(MAIN) $(UTIL) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

plot:
	gnuplot "plotdata" -p

clean:
	@rm *.o
