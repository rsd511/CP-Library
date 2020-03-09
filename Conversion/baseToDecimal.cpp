// OUTSIDE MAIN


ll baseToDec(string s, ll b)
{
	if(s == "0") return 0;
	ll ret = 0, n = len(s);
	ll power[n]; power[0] = 1;
	f(i,1,n-1) power[i] = power[i-1]*b;
	f(i,0,n-1) {
		ll coeff = s[i] - 48;
		ret += (coeff * power[n-1-i]);
	}
	return ret;
}