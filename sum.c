#include<stdio.h>
#include<omp.h>

int main(int argc, char *argv[]){

	int nThreads = 4;

	omp_set_num_threads(nThreads);

	int n = 0;
	scanf("%d", &n);
	double sum = 0, sum2 = 0;
	double sumP[nThreads];
	double sumP2[nThreads];
	for(int i = 0; i < nThreads+1; i++)
		sumP[i] = sumP2[i] = 0;

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
	#pragma omp parallel num_threads(nThreads)
	{
		int at = omp_get_thread_num();
		int end = (at+1)*(n/nThreads);
		for(int i = at*(n/nThreads); i < end; i++)
			sumP[at] += i;
	}
	if(n%4 == 0)
		sum += n*((n%4)+1)-(n%4);
	else if(n%4 == 1)
		sum += n*((n%4)+1)-(n%4);
	else if(n%4 == 2)
		sum += n*((n%4)+1)-(n%4-1);
	else
		sum += n*((n%4)+1)-2*(n%4);

	#pragma omp parallel for
	for(int i = 0; i <= n; i++){
		sumP2[omp_get_thread_num()] += i;
	}

	for(int i = 0; i < nThreads; i++){
		sum += sumP[i];
		sum2 += sumP2[i];
	}

	printf("Sum from 0 to %d = %.0lf\n", n, sum);
	printf("Sum2 from 0 to %d = %.0lf\n", n, sum2);
	return 0;
}
