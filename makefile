p: 
	mpicc -o parallel_c parallel.c 	
	mpiexec -machinefile ./allnodes	-np 2 ./parallel_c 100000

s:
	mpicc -o sequential_c sequential.c 		
	mpiexec -machinefile ./allnodes	-np 1 ./sequential_c 100000

