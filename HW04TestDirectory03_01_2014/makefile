GPP = g++ -O3 -Wall

UTILS = ../../Utilities

M = Main.o
T = TallyVotes.o
C = Candidate.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(T) $(C) $(S) $(U)
	$(GPP) -o Aprog $(M) $(T) $(C) $(S) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c -DEBUG Main.cpp

TallyVotes.o: TallyVotes.h TallyVotes.cpp
	$(GPP) -o TallyVotes.o -c -DEBUGTALLY TallyVotes.cpp

Candidate.o: Candidate.h Candidate.cpp
	$(GPP) -o Candidate.o -c -DEBUGCANDIDATE Candidate.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean

