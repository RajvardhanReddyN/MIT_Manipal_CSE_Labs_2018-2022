#include <mpi.h>  
#include<stdio.h>
int main (int argc, char *argv[]) {
	int i, root_rank = 0, my_rank, size, recv_buffer;
	 
	MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);  

	if(my_rank == 0){  
	        int send_buffer=777;
	        for(i=1; i<size; i++)
        		MPI_Send(&send_buffer, 1, MPI_INT, i, 2, MPI_COMM_WORLD);
	}	 
	else{
		MPI_Recv(&recv_buffer, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  
		printf("Process %d received number %d from process 0 \n", my_rank, recv_buffer); 
        }    					
	MPI_Finalize(); 
	return 0;
}
