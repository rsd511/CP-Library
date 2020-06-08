// OUTSIDE MAIN

// Default MOD 1e9 + 7 in template

// MAX -> Till
#define MAX 10

ll factorial[MAX+1];

void build_factorials()
{
	factorial[0] = 1;
	ll fact = 1;
	f(i,1,MAX) {
		fact *= i;
		fact %= MOD;
		factorial[i] = fact;
	}
}



// INSIDE MAIN

build_factorials();