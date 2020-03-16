p: 
	mpicc -o parallel_c parallel.c 	
	mpiexec -machinefile ./allnodes	-np 2 ./parallel_c 3

s:
	gcc -o sequential_c sequential.c 	
	./sequential_c

