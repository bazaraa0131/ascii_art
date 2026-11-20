P2ASCII_SRC = p2ascii.cpp
P2ASCII_OUT = p2ascii

LOADER_SRC = loader.cpp
LOADER_OUT = loader

loader: clean_loader
	g++ $(LOADER_SRC) -O2 -o $(LOADER_OUT) -lm -lpthread -lX11

p2ascii:
	g++ $(P2ASCII_SRC) -O2 -o $(P2ASCII_OUT) -lm -lpthread -lX11

clean_loader:
	rm -f $(LOADER_OUT)

clean_p2ascii:
	rm -f $(P2ASCII_OUT)

clean: clean_loader clean_p2ascii
