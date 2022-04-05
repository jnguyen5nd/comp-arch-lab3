CC:= gcc
CFLAGS:= -std=gnu99
TARGETS:= Q3
EXE:= exe

all: $(TARGETS)

Q1: table no_blocking

Q2: 200_64K_q2 400_64K_q2 200_128K_q2 400_128K_q2

Q3: 200_64K_q3 400_64K_q3 200_128K_q3 400_128K_q3


blocking: blocking.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<


# Q1
table: ./question1/no_blocking_table.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

no_blocking: no_blocking.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<


# Q2
200_64K_q2: ./question2/no_block_200_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_64K_q2: ./question2/no_block_400_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

200_128K_q2: ./question2/no_block_200_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_128K_q2: ./question2/no_block_400_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<


# Q3
200_64K_q3: ./question3/block_200_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_64K_q3: ./question3/block_400_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

200_128K_q3: ./question3/block_200_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_128K_q3: ./question3/block_400_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

# Clean
clean:
	rm ./exe/*
