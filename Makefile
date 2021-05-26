CC = g++
OBJ = Data.cpp Line2D.cpp Line3D.cpp main.cpp Menu.cpp Point2D.cpp Point3D.cpp


EXE = messy

all:
	$(CC) $(OBJ) -o $(EXE)
 
clean:
	rm -f $(EXE)