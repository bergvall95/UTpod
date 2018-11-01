CPP  = g++
RES  =
OBJ  = song.o UtPod.o UtPodDriver.o $(RES)
LINKOBJ  = song.o UtPod.o UtPodDriver.o $(RES)
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

main.o: UtPodDriver.cpp
	$(CPP) -c UtPodDriver.cpp -o UtPodDriver.o $(CXXFLAGS)


