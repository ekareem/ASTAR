#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Rect.cpp Grid.cpp Node.cpp Astar.cpp Draw.cpp Client.cpp


#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = astar

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -IC:\MinGW\include -LC:\MinGW\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf  -o $(OBJ_NAME)

#runs the exectuable
run :
	astar.exe