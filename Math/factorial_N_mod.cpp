// OUTSIDE MAIN

// Default MOD 1e9 + 7 in template

ll factorial(ll n)
{
	ll ret = 1;
	f(i,2,n) ret *= i, ret %= MOD;
	return ret;
}
