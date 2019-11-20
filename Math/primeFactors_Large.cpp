// OUTSIDE MAIN

// Efficient till 10^12
vector <ll> primeFactorsOfLarge(ll n)
{
	 vector <ll> ret;
	 if(n == 0) return ret;
	 for(ll i = 2; i * i <= n; i++) {
	 	if(n % i == 0) {
	 		ll currentFactor = i;
	 		ret.pb(currentFactor);
	 		while(n % currentFactor == 0) n /= currentFactor;
	 	}
	 }
	 if(n != 1) ret.pb(n);
	 return ret;
}