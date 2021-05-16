bin:
	mkdir bin

bin/GUI.o: bin
	g++ -std=c++11 -c -lm "PROJEKT_SEM4/GUI.cpp" -o "bin/GUI.o" `wx-config --cxxflags --libs` -lfreeimage -lfreeimageplus -lX11 -lsfml-graphics -lsfml-window -lsfml-system 
	
bin/GUIMyFrame1.o: bin
	g++ -std=c++11 -c -lm "PROJEKT_SEM4/GUIMyFrame1.cpp" -o "bin/GUIMyFrame1.o" `wx-config --cxxflags --libs` -lfreeimage -lfreeimageplus -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/wec.o: bin
	g++ -std=c++11 -c -lm "PROJEKT_SEM4/wec.cpp" -o "bin/wec.o" `wx-config --cxxflags --libs` -lfreeimage -lfreeimageplus -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

bin/RenderWindow.o: bin
	g++ -std=c++11 -c -lm "PROJEKT_SEM4/RenderWindow.cpp" -o "bin/RenderWindow.o" `wx-config --cxxflags --libs` -lfreeimage -lfreeimageplus -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	
	
bin/main: bin bin/wec.o bin/GUIMyFrame1.o bin/GUI.o bin/RenderWindow.o
	g++ -std=c++11 -lm "bin/wec.o" "bin/GUIMyFrame1.o" "bin/GUI.o" "bin/RenderWindow.o" "PROJEKT_SEM4/main.cpp" -o "bin/main" `wx-config --cxxflags --libs` -lfreeimage -lfreeimageplus -lX11 -lsfml-graphics -lsfml-window -lsfml-system 	

clear:
	rm -rf bin
	
all: clear bin/main

run: bin/main
	./bin/main

.PHONY: all clear run
