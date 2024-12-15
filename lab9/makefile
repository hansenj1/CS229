objects = BST.o Tree.o Lab9Part1.o 

%.o:	%.cpp
	g++ -c $<

main:	main.o $(objects)
	g++ -g main.o $(objects) -o bst_main

clean:
	rm *.o