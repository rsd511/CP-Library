// OUTSIDE MAIN


vector < pair<ll,ll> > consecutiveCount(ll a[], ll n)
{
	vector < pair<ll,ll> > ret;
	// Change the order from here
	ret.pb(mp(a[0],1));
	f(i,1,n-1) {
		if(a[i] == a[i-1]) ret[sz(ret)-1].ss++;
		else ret.pb(mp(a[i],1));
	}
	return ret;
}