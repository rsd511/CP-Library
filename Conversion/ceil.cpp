// OUTSIDE MAIN


ll ceil(ll num, ll den)
{
	ll ret = num / den;
	if(num % den) ret++;
	return ret;
}