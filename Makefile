
CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp01 # nome do executavel que sera gerado, nao troque
TMPOUT=tp01.testresult

$(EXEC): src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o $(EXEC)

foo.o: include/foo.cpp
	$(CC) $(CFLAGS) -c include/foo.cpp -o foo.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf foo.o