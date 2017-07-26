vier: spiel.o vierGewinnt.o
	gcc spiel.o vierGewinnt.o -o vier

spiel.o: spiel.c spiel.h
	gcc -c spiel.c

vierGewinnt.o: vierGewinnt.c spiel.h
	gcc -c vierGewinnt.c


# remove all object  and executable files
clean:
	rm *.o ;rm vier

# build
run:    vier
	./vier

