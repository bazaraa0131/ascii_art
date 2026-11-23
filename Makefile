MAIN_SRC = main.cpp
MAIN_OUT = out

LOADER_DIR = jpeg_loader
LOADER_SRC = loader.cpp

all:
	g++ $(MAIN_SRC) $(LOADER_DIR)/$(LOADER_SRC) -O2 -o $(MAIN_OUT) -lm -lpthread -lX11

clean:
	rm -f out