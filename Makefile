all: 	    main.o tile.o hero.o zombie.o
	g++ main.o tile.o hero.o zombie.o -o WAM -lsfml-graphics -lsfml-window -lsfml-system

tile.o: tile.cpp tile.hpp
	g++ -c tile.cpp -Werror -Wall -ansi -pedantic 

hero.o: hero.cpp hero.hpp
	g++ -c hero.cpp -Werror -Wall -ansi -pedantic 

main.o: main.cpp
	g++ -c main.cpp -Werror -Wall -ansi -pedantic

zombie.o: zombie.cpp zombie.hpp
	g++ -c zombie.cpp -Werror -Wall -ansi -pedantic
clean:
	rm *.o WAM
