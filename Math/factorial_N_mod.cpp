// OUTSIDE MAIN

// Default MOD 1e9 + 7
#define MOD 1000000007

ll factorial(ll n)
{
	ll ret = 1;
	f(i,2,n) ret *= i, ret %= MOD;
	return ret;
}



// INSIDE MAIN