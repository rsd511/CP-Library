// OUTSIDE MAIN


vector <ll> factors(ll n)
{
	vector <ll> ret;
	f(i,1,sqrt(n)) if(n % i == 0) {
		if(i == n/i) ret.pb(i);
		else ret.pb(i), ret.pb(n/i);
	}
	// Comment out to return unsorted
	sort(ret.begin(), ret.end());
	return ret;
}