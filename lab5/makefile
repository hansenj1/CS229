objects =  Courses.o 

%.o:	%.cpp
	g++ -c $<

main:	main.o $(objects)
	g++ main.o $(objects) -o l5

clean:
	rm *.o