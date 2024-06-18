main : front_propagation.c back_propagation.c neural_network.h 
	gcc main.c front_propagation.c back_propagation.c -Wall -Wextra -lm -o main

.PHONY : clean
clean :
	-rm $(objects) main
