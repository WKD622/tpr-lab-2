p: 
	mpicc -o parallel_c parallel.c 	
	mpiexec -machinefile ./allnodes	-np 12 ./parallel_c 100000

s:
	gcc -o sequential_c sequential.c -lm
	./sequential_c 100000000 1

