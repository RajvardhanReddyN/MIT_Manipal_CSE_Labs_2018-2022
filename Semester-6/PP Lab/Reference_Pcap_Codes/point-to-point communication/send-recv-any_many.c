#include <mpi.h>  
#include<stdio.h>
int main (int argc, char *argv[]) {
	int rank, size, send_number0, send_number1, recv_buffer;
	MPI_Status status;
 
	MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  

	if(rank == 0){  
        	send_number0 = 777;
          	MPI_Send(&send_number0, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
	}	
	if(rank == 1){  
        	send_number1 = 888;
          	MPI_Send(&send_number1, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);
	}
	if(rank== 2){
	     while(1){
		MPI_Recv(&recv_buffer, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,  &status); 
            	printf("Process %d received number %d from process %d in message %d \n", rank, recv_buffer, 
            	           status.MPI_SOURCE, status.MPI_TAG);
             }     }      
	MPI_Finalize(); 
	return 0;
}
