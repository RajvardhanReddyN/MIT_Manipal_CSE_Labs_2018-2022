#include "mpi.h"
#include <stdio.h>
void ErrorHandler(int error_code);

int main(int argc,char *argv[]){
	int  C=3;
   	int  size, my_rank, len, error_code; 
   	MPI_Init(&argc,&argv);
  	MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
	error_code = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	//error_code = MPI_Comm_size(MPI_COMM_WORLD,&size);
   	error_code = MPI_Comm_size(C,&size);
   	ErrorHandler(error_code);
   	printf ("Number of processes= %d My rank= %d \n", size,my_rank);
        MPI_Finalize();
   }
   
 void ErrorHandler(int error_code){
	  if (error_code != MPI_SUCCESS){
     		char error_string[BUFSIZ];
     		int length_of_error_string, error_class;
     		MPI_Error_class(error_code, &error_class);
     		MPI_Error_string(error_code, error_string, &length_of_error_string);
     		printf("%d %s\n",  error_class, error_string);
   }
}
   
