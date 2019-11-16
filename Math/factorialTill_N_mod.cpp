// OUTSIDE MAIN

// Default MOD 1e9 + 7
#define MOD 1000000007
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