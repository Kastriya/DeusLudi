CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

DeusLudi: main.cpp
	g++ $(CFLAGS) -o DeusLudi main.cpp $(LDFLAGS)

.PHONY: test clean

test: DeusLudi
	./DeusLudi

clean:
	rm -f DeusLudi
