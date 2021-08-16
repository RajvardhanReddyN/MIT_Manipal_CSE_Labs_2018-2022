#include <mpi.h>  
#include<stdio.h>
int main (int argc, char *argv[]) {
	int rank, size, send_number;
 
	MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  

	if(rank == 1){  
        	send_number = 888;
          	MPI_Send(&send_number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
          	printf("Exit from sender......\n");
	}	 
	else if(rank==2){
		MPI_Recv(&send_number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
            	printf("Process 2 received number %d from process 1 \n", send_number); 
       }
	else
		printf("Hello from process %d \n", rank);
			
	MPI_Finalize(); 
	return 0;
}
