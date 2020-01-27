// OUTSIDE MAIN


#define MAX 100005
ll fib[MAX+1];

void calculate_fibonacci()
{
	fib[0] = 0; fib[1] = 0; fib[2] = 1;
	f(i,3,MAX) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
}


// INSIDE MAIN

calculate_fibonacci();