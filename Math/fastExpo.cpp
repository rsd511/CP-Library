// OUTSIDE MAIN


ll fastExpo(ll a, ll b, ll m)
{
	ll ret = 1; a %= m;
	while(b > 0) {
		if(b & 1) ret = (ret * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ret;
}