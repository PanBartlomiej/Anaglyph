bin:
	mkdir bin

bin/Linux: bin
	mkdir bin/Linux

bin/Linux/GUI.o: bin/Linux
	g++ -std=c++17 -c -O3 "src/GUI.cpp" -o "bin/Linux/GUI.o" `wx-config --cxxflags --libs` 

bin/Linux/GUIMyFrame1.o: bin/Linux
	g++ -std=c++17 -c -O3 "src/GUIMyFrame1.cpp" -o "bin/Linux/GUIMyFrame1.o" `wx-config --cxxflags --libs` 

bin/Linux/wec.o: bin/Linux
	g++ -std=c++17 -c -O3 "src/wec.cpp" -o "bin/Linux/wec.o" 

bin/Linux/ViewWindow.o: bin/Linux
	g++ -std=c++17 -c -O3 "src/ViewWindow.cpp" -o "bin/Linux/ViewWindow.o"

bin/Linux/MatrixParallelMultiplier.o: bin/Linux
	g++ -std=c++17 -c -O3 "src/MatrixParallelMultiplier.cpp" -o "bin/Linux/MatrixParallelMultiplier.o"

bin/Linux/StructureMakers.o:
	g++ -std=c++17 -c -O3 "src/StructureMakers.cpp" -o "bin/Linux/StructureMakers.o" 

bin/Linux/main: bin/Linux bin/Linux/wec.o bin/Linux/GUIMyFrame1.o bin/Linux/GUI.o bin/Linux/ViewWindow.o bin/Linux/MatrixParallelMultiplier.o bin/Linux/StructureMakers.o
	g++ -std=c++17 -O3 "bin/Linux/wec.o" "bin/Linux/GUIMyFrame1.o" "bin/Linux/GUI.o" "bin/Linux/ViewWindow.o" "bin/Linux/MatrixParallelMultiplier.o" "bin/Linux/StructureMakers.o" "src/main.cpp" -o "bin/Linux/main" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lm	

clear:
	rm -rf bin/Linux

all: clear bin/Linux/main

run: bin/Linux/main
	./bin/Linux/main

install_packets:
	sudo apt update
	sudo apt install make gcc g++ 
	sudo apt install libwxgtk3.0-dev || sudo apt install libwxgtk3.0-gtk3-dev	
	sudo apt install libsfml-dev libsfml-window2.5 libsfml-system2.5 libsfml-graphics2.5	

.PHONY: install_packets run all clear
