all: hanoi

hanoi: hanoi.cpp
	g++ $< -o $@

clean:
	rm hanoi
