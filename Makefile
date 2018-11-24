hello: hello.c
	gcc hello.c -o hello -fopenmp -std=c99

sum: sum.c
	gcc sum.c -o sum -fopenmp -std=c99

pi: pi.c
	gcc pi.c -o pi -fopenmp -std=c99

nest: nest.c
	gcc nest.c -o nest -fopenmp -std=c99

