CPP  = g++
RES  =
OBJ  = song.o UtPod.o main.o $(RES)
LINKOBJ  = song.o UtPod.o main.o $(RES)
BIN  = UtPod
CXXFLAGS = $(CXXINCS)
CFLAGS = $(INCS)
RM = rm -f


all: UtPod

clean:
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o UtPod $(LIBS)

song.o: song.cpp
	$(CPP) -c song.cpp -o song.o $(CXXFLAGS)

UtPod.o: UtPod.cpp
	$(CPP) -c UtPod.cpp -o UtPod.o $(CXXFLAGS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)


