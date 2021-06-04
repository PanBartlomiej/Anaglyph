bin:
	mkdir bin
	
bin/Linux: bin
	mkdir bin/Linux

bin/Linux/GUI.o: bin/Linux
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/GUI.cpp" -o "bin/Linux/GUI.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 
	
bin/Linux/GUIMyFrame1.o: bin/Linux
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/GUIMyFrame1.cpp" -o "bin/Linux/GUIMyFrame1.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/Linux/wec.o: bin/Linux
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/wec.cpp" -o "bin/Linux/wec.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/Linux/ViewWindow.o: bin/Linux
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/ViewWindow.cpp" -o "bin/Linux/ViewWindow.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	
	
bin/Linux/MatrixParallelMultiplier.o: bin/Linux
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/MatrixParallelMultiplier.cpp" -o "bin/Linux/MatrixParallelMultiplier.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/Linux/main: bin/Linux bin/Linux/wec.o bin/Linux/GUIMyFrame1.o bin/Linux/GUI.o bin/Linux/ViewWindow.o bin/Linux/MatrixParallelMultiplier.o
	g++ -std=c++17 -O3 -lm "bin/Linux/wec.o" "bin/Linux/GUIMyFrame1.o" "bin/Linux/GUI.o" "bin/Linux/ViewWindow.o" "bin/Linux/MatrixParallelMultiplier.o" "PROJEKT_SEM4/main.cpp" -o "bin/Linux/main" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

clear:
	rm -rf bin/Linux
	
all: clear bin/Linux/main

run: bin/main
	./bin/Linux/main
	
install_packets:
	sudo apt install make gcc g++ 
	sudo apt install libwxgtk3.0-dev || sudo apt install libwxgtk3.0-gtk3-dev
	sudo apt install libsfml-dev libsfml-window2.5 libsfml-system2.5 libsfml-graphics2.5

.PHONY: all clear run install_packets
