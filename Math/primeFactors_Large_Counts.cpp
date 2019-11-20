// OUTSIDE MAIN

// Efficient till 10^12
vector < pair<ll,ll> > primeFactorsWithCountOfLarge(ll n)
{
	 vector < pair<ll,ll> > ret;
	 if(n == 0) return ret;
	 for(ll i = 2; i * i <= n; i++) {
	 	if(n % i == 0) {
	 		ll currentFactor = i, currentCount = 0;
	 		while(n % currentFactor == 0) n /= currentFactor, currentCount++;
	 		ret.pb(mp(currentFactor,currentCount));
	 	}
	 }
	 if(n != 1) ret.pb(mp(n,1));
	 return ret;
}