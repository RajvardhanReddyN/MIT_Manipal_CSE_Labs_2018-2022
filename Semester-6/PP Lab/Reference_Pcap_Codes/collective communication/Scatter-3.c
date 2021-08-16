#include <mpi.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
    int root_rank = 0, size, my_rank, i;
    char *send_buf="HELLO WORLD";    
    int len = strlen(send_buf);
    char *recv_buf = (char *)malloc(len*sizeof(char));
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 6)
    {
        printf("This application is meant to be run with 6 MPI processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
   // Root process will scatter the data to other processes including itself
    MPI_Scatter(send_buf, 2, MPI_CHAR, recv_buf, 2, MPI_CHAR, root_rank, MPI_COMM_WORLD);
    
    printf("Data in process [%d] is: %s  \n", my_rank, recv_buf);
       	
    MPI_Finalize();
    return 0;
}
