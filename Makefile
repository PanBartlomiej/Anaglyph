bin:
	mkdir bin

bin/GUI.o: bin
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/GUI.cpp" -o "bin/GUI.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 
	
bin/GUIMyFrame1.o: bin
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/GUIMyFrame1.cpp" -o "bin/GUIMyFrame1.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/wec.o: bin
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/wec.cpp" -o "bin/wec.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	
# # 
bin/ViewWindow.o: bin
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/ViewWindow.cpp" -o "bin/ViewWindow.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	
	
bin/MatrixParallelMultiplier.o: bin
	g++ -std=c++17 -c -O3 -lm "PROJEKT_SEM4/MatrixParallelMultiplier.cpp" -o "bin/MatrixParallelMultiplier.o" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	
	
bin/main: bin bin/wec.o bin/GUIMyFrame1.o bin/GUI.o bin/ViewWindow.o bin/MatrixParallelMultiplier.o
	g++ -std=c++17 -O3 -lm "bin/wec.o" "bin/GUIMyFrame1.o" "bin/GUI.o" "bin/ViewWindow.o" "bin/MatrixParallelMultiplier.o" "PROJEKT_SEM4/main.cpp" -o "bin/main" `wx-config --cxxflags --libs`  -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

clear:
	rm -rf bin
	
all: clear bin/main

run: bin/main
	./bin/main
	
install_packets:
	sudo apt install make gcc g++ 
	sudo apt install libwxgtk3.0-dev || sudo apt install libwxgtk3.0-gtk3-dev
	sudo apt install libsfml-dev libsfml-window2.5 libsfml-system2.5 libsfml-graphics2.5

.PHONY: all clear run install_packets
