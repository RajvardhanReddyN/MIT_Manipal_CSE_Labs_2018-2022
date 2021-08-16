#include  <mpi.h>  
#include  <stdio.h>
#include  <string.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
	int rank, size;
	char* send_buffer="Hello";
	int len=strlen(send_buffer);
	int buffer_attached_size = MPI_BSEND_OVERHEAD + len*sizeof(char);
        char* buffer_attached = (char*)malloc(buffer_attached_size);
        char* recv_buffer= (char*)malloc(buffer_attached_size);
       
        MPI_Init (&argc, &argv);	     
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  
	
        if(rank == 0){
                MPI_Buffer_attach(buffer_attached, buffer_attached_size);
                printf("Sender %d  sent message: %s \n", rank, send_buffer);
                MPI_Bsend(&send_buffer, len, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
                MPI_Buffer_detach(&buffer_attached, &buffer_attached_size);
                printf("returned from Bsend... \n");
                free(buffer_attached);
         }       
	else { 
          	MPI_Recv(&recv_buffer, buffer_attached_size, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                printf(" Receiver %d received value: %s \n", rank, recv_buffer);
	} 
	MPI_Finalize(); 
	return 0;
}
