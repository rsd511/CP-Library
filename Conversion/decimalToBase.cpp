// OUTSIDE MAIN


vector <ll> decToBase(ll n, ll b)
{
	vector <ll> ret;
	if(n == 0) {
		ret.pb(0);
		return ret;
	}
	while(n > 0) {
		ll rem = n % b;
		ret.pb(rem);
		n /= b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}