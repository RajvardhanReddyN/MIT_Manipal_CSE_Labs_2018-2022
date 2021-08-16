#include <mpi.h>  
#include<stdio.h>
int main (int argc, char *argv[]) {
	int rank, size, send_number;
	MPI_Status status;
 
	MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  

	if(rank == 0){  
        	send_number = 888;
          	MPI_Send(&send_number, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);
	}	 
	if(rank==1){
		MPI_Recv(&send_number, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,  &status); 
            	printf("Process %d received number %d from process %d in message %d \n", rank, send_number,  
            	            status.MPI_SOURCE, status.MPI_TAG); 
	}
				
	MPI_Finalize(); 
	return 0;
}
