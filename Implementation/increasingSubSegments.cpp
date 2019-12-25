// OUTSIDE MAIN


vector < pair<ll,ll> > incSubSeg(ll a[], ll n)
{
	vector < pair<ll,ll> > ret;
	ret.pb(mp(0,0));
	f(i,1,n-1) {
		if(a[i] > a[i-1]) ret[sz(ret)-1].ss = i;
		else ret.pb(mp(i,i));
	}
	return ret;
}