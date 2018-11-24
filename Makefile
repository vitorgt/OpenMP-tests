hello: hello.c
	gcc hello.c -o hello -fopenmp -std=c99

sum: sum.c
	gcc sum.c -o sum -fopenmp -std=c99

