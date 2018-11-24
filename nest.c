#include<stdio.h>
#include<omp.h>

// DOESN'T WORK!!

int main(int argc, char *argv[]){

	int nThreads = 4;
	omp_set_num_threads(nThreads);
	omp_set_nested(1);

	int n = 0;
	scanf("%d", &n);

	#pragma omp parallel
	{
		#pragma omp for
		for(int i = 0; i < n; i++){
			#pragma omp for
			for(int j = 0; j < n; j++){
				printf("Hello from thread #%d iteration i#%d j#%d\n", omp_get_thread_num(), i, j);
			}
		}
	}
	return 0;
}
