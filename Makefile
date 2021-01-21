
CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp01 # nome do executavel que sera gerado, nao troque
TMPOUT=tp01.testresult

$(EXEC): src/main.cpp graph.o
	$(CC) $(CFLAGS) src/main.cpp graph.o -o $(EXEC)
	rm -rf graph.o

graph.o: src/include/graph.cpp
	$(CC) $(CFLAGS) -c src/include/graph.cpp -o graph.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf graph.o