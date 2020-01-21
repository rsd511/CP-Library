// OUTSIDE MAIN


ll bit_ones(ll n)
{
	ll ret = 0;
	while(n > 0) {
		if(n % 2) ret++;
		n /= 2;
	}
	return ret;
}