OBJS = command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o

exe: $(OBJS)
	gcc -o exe $(OBJS)
	
command.o: command.c command.h
	gcc -c command.c
	
game.o: game.c game.h
	gcc -c game.c
	
game_loop.o: game_loop.c graphic_engine.h
	gcc -c game_loop.c
	
graphic_engine.o: graphic_engine.c command.h screen.h graphic_engine.h
	gcc -c graphic_engine.c

screen.o: screen.c screen.h
	gcc -c screen.c
	
space.o: space.c types.h space.h
	gcc -c space.c
	
game_reader.o: game_reader.c game_reader.h
	gcc -c game_reader.c
	
object.o: object.c object.h types.h
	gcc -c object.c
	
.PHONY: clean
clean:
	rm -rf exe *.o
