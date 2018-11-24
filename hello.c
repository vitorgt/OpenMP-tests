#include<stdio.h>
#include<omp.h>

int main(){
	#pragma omp parallel
	{
		printf("Hello, World from thread #%0X.\n", omp_get_thread_num());
	}
	return 0;
}
