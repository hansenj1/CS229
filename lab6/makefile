objects = LLNode.o 
#LinkedList.o LinkedListPlus.o

%.o:	%.cpp
	g++ -c $<

main:	main.o $(objects)
	g++ main.o $(objects) -o l6

clean:
	rm *.o