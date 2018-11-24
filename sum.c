#include<stdio.h>
#include<omp.h>

int main(int argc, char *argv[]){

	int nThreads = 4;
	omp_set_num_threads(nThreads);

	int n = 0;
	scanf("%d", &n);
	double sum1 = 0, sum2 = 0, sum3 = 0;
	double sum1P[nThreads];
	double sum2P[nThreads];
	for(int i = 0; i < nThreads+1; i++)
		sum1P[i] = sum2P[i] = 0;

	/*
	 * if(expression)
	 * num_threads(int|expression)
	 * private(list)
	 * firstprivate(list)
	 * shared(list)
	 * default(shared|none)
	 * copyin(list)
	 * reduction(operator: list) //basic operators only
	 */
	#pragma omp parallel
	{
		int at = omp_get_thread_num();
		int end = (at+1)*(n/nThreads);
		for(int i = at*(n/nThreads); i < end; i++)
			sum1P[at] += i;
	}
	if(n%4 == 0)
		sum1 += n*((n%4)+1)-(n%4);
	else if(n%4 == 1)
		sum1 += n*((n%4)+1)-(n%4);
	else if(n%4 == 2)
		sum1 += n*((n%4)+1)-(n%4-1)-2;
	else
		sum1 += n*((n%4)+1)-2*(n%4);
	for(int i = 0; i < nThreads; i++){
		sum1 += sum1P[i];
	}

	#pragma omp parallel for
	for(int i = 0; i <= n; i++){
		sum2P[omp_get_thread_num()] += i;
	}
	for(int i = 0; i < nThreads; i++){
		sum2 += sum2P[i];
	}

	#pragma omp parallel for reduction(+: sum3)
	for(int i = 0; i <= n; i++){
		//printf("Hello from thread #%d iteration #%d\n", omp_get_thread_num(), i);
		sum3 += i;
	}

	printf("Sum1 from 0 to %d = %.0lf\n", n, sum1);
	printf("Sum2 from 0 to %d = %.0lf\n", n, sum2);
	printf("Sum3 from 0 to %d = %.0lf\n", n, sum3);
	return 0;
}
