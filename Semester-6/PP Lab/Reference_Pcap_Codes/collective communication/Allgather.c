#include <mpi.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]) {
    int size, my_rank;
    char send_buf[10] = "AA ";
    char *recv_buf;
              
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    int len = strlen(send_buf);
    send_buf[len-2] = send_buf[len-2] + my_rank;
    recv_buf = (char *)malloc(size*len*sizeof(char)); 
    
    // Each MPI process sends its send_buf to Root proess which collects the data in rank order
    printf("Sending data %s from from process %d \n", send_buf, my_rank);
    MPI_Allgather(send_buf, len, MPI_CHAR, recv_buf, len, MPI_CHAR, MPI_COMM_WORLD);
    
    // Display gathered result 
    printf("The gathered data at Process [%d] is : %s \n", my_rank, recv_buf);
 
    MPI_Finalize();
    return 0;
}
