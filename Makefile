CC:= gcc
CFLAGS:= -std=gnu99
TARGETS:= Q1 Q2 Q4 Q6 temps
EXE:= exe
ARM:= /home/software/arm/cross-compiler/gcc-4.1.1-glibc-2.3.2/arm-unknown-linux-gnu/bin/arm-unknown-linux-gnu-gcc
ARMFLAGS:= -static
SIM:= /escnfs/courses/sp22-cse-30321.01/public/arm/simplesim-arm/sim-outorder


all: $(TARGETS)

temps: no_blocking blocking

Q1: table

Q2: 200_64K_q2 400_64K_q2 200_128K_q2 400_128K_q2

Q4: 200_64K_q4 400_64K_q4 200_128K_q4 400_128K_q4

Q6: sa1core

# Templates
blocking: templates/blocking.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

no_blocking: tesmplates/no_blocking.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<


# Q1
table: ./question1/no_blocking_table.c
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


# Q4
200_64K_q4: ./question4/block_200_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_64K_q4: ./question4/block_400_64K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

200_128K_q4: ./question4/block_200_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

400_128K_q4: ./question4/block_400_128K.c
	$(CC) $(CFLAGS) -o ./$(EXE)/$@ $<

# Q6
blocking_q6: ./question6/blocking.c
	$(ARM) $(ARMFLAGS) -o ./$(EXE)/$@ $<

sa1core: ./question6/sa1core.cfg blocking_q6
	$(SIM) -config $< ./$(EXE)/blocking_q6


# Clean
clean:
	rm ./exe/*
