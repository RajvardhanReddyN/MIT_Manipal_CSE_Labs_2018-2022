#include <mpi.h>  
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
    int root_rank = 0, size, my_rank;
    int send_buf = 111;
    int recv_buf[4];
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 4)
    {
        printf("This application is meant to be run with 4 MPI processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    // Get my rank
     MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     send_buf = send_buf + my_rank;
      
    // Each MPI process sends its send_buf to Root proess which collects the data in rank order
    printf("Sending data %d from from process %d \n", send_buf, my_rank);
    MPI_Gather(&send_buf, 1, MPI_INT, &recv_buf, 1, MPI_INT, root_rank, MPI_COMM_WORLD);
    
    // Display result in Root
     if(my_rank == root_rank)
    {
    	printf("The gathered data at Root is \n");
    	for(int i=0; i<4; i++)
        	printf("%d \n", recv_buf[i]);
    }
 
    MPI_Finalize();
    return 0;
}
