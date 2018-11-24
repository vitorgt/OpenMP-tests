#include<stdio.h>
#include<omp.h>

int main(int argc, char *argv[]){

	int nThreads = 4;
	omp_set_num_threads(nThreads);

	unsigned long long n = 100000000;
	//scanf("%ld", &n);
	double sum = 0, step = 1.0/((double)n);

	/*
	 * FOR
	 * schedule(type, [chunk])
	 * shared(list)
	 * private(list)
	 * firstprivate(list)
	 * lastprivate(list)
	 * reduction(operator: list)
	 * nowait
	 * ordered
	 */
	#pragma omp parallel for reduction(+: sum)
	for(unsigned long long i = 0; i < n; i++){
		sum += 4.0/(1.0 + ((i + 0.5) * step)*((i + 0.5) * step));
	}

	printf("Pi = %.20lf\n", step*sum);
	return 0;
}
