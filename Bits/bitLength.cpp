// OUTSIDE MAIN


ll bit_length(ll n)
{
	ll ret = 0;
	while(n > 0) {
		ret++;
		n /= 2;
	}
	return ret;
}