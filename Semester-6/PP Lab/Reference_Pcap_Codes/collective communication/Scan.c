#include <mpi.h>  
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
    int root_rank = 0, size, my_rank, result=0;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
 
    // Each MPI process sends its rank to the SCAN method
    MPI_Scan(&my_rank, &result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    
    printf("The Scanned result in Process %d is %d.\n", my_rank, result);
    MPI_Finalize();
    return 0;
}
