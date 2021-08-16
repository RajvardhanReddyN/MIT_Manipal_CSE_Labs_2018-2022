#include <mpi.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
    int size, my_rank,i;
    int send_buf[4] = {10,20,30,40};
    int recv_buf[4];
              
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(size != 4)
    {
        printf("This application is meant to be run with 4 MPI processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    
    for(i=0; i<4;i++)
    	send_buf[i] += my_rank;
    // Each MPI process sends/recives data to other processes in chunks
    printf("Sending [--%d--%d--%d--%d--] from process %d \n", send_buf[0],send_buf[1],send_buf[2],send_buf[3],my_rank);
    MPI_Alltoall(send_buf, 1, MPI_INT, recv_buf, 1, MPI_INT, MPI_COMM_WORLD);
    
    // Display gathered result 
     printf("\n Data gathered in process %d  is: [--%d--%d--%d--%d--] \n", my_rank, 
                    recv_buf[0],recv_buf[1],recv_buf[2],recv_buf[3]);
     //for( i=0; i<size; i++)
    	//printf("--%d--", recv_buf[i]);
 
    MPI_Finalize();
    return 0;
}
