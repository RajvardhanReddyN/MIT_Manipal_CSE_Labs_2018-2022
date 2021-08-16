#include <mpi.h>  
#include<stdio.h>
int main (int argc, char *argv[]) {
	int rank, size, send_number;
 
	MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  

	if(rank == 0){  
        	send_number = 555;
          	MPI_Ssend(&send_number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
          	printf("OUT of process 0 (sender).... \n");
	}	 
	else if (rank == 1) { 
          	MPI_Recv(&send_number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
            	printf("Process 1 received number %d from process 0 \n", send_number); 
		printf("OUT of process 1 (receiver).... \n");
	}
	 else
		printf("\n Hello from %d \n", rank);
	MPI_Finalize(); 
	return 0;
}
