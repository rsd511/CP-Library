// OUTSIDE MAIN


ll baseToDec(vector <ll> v, ll b)
{
	if(sz(v) == 0) return 0;
	ll ret = 0, n = sz(v);
	ll power[n]; power[0] = 1;
	f(i,1,n-1) power[i] = power[i-1]*b;
	f(i,0,n-1) {
		ll coeff = v[i];
		ret += (coeff * power[n-1-i]);
	}
	return ret;
}