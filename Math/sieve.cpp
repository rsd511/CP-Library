// OUTSIDE MAIN


// Calculates till MAX
#define MAX 1000000

ll isPrime[MAX + 1];

void sieve()
{
	isPrime[0] = isPrime[1] = 0;
	f(i,2,MAX) isPrime[i] = 1;
	for(ll i = 2; i*i <= MAX; i++) if(isPrime[i]) {
		for(ll j = i*i; j <= MAX; j += i)
			isPrime[j] = 0;
	}
}



// INSIDE MAIN

sieve();