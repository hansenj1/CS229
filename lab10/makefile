objects = Lab10Part1.o DenseGraph.o Graph.o 

%.o:	%.cpp
	g++ -c $<

main:	main.o $(objects)
	g++ -g main.o $(objects) -o graph_main

clean:
	rm *.o