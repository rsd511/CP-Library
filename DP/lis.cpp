// OUTSIDE MAIN


ll LLIS(vector <ll> v)
{
	vector <ll> liss;
	f(i,0,sz(v)-1) {
		if(sz(liss) == 0) liss.pb(v[i]);
		else if(v[i] > liss[sz(liss)-1]) liss.pb(v[i]);
		else if(v[i] == liss[sz(liss)-1]) continue;
		else liss[upper_bound(liss.begin(), liss.end(), v[i]) - liss.begin()] = v[i];
	}
	return sz(liss);
}

// Returns First LIS
vector <ll> LIS(vector <ll> v, ll n)
{
	vector <ll> lis;
	f(i,0,sz(v)-1) {
		if(sz(lis) == 0) {
			lis.pb(v[i]);
			if(sz(lis) == n) break;
		}
		else if(v[i] > lis[sz(lis)-1]) {
			lis.pb(v[i]);
			if(sz(lis) == n) break;
		}
		else if(v[i] == lis[sz(lis)-1]) continue;
		else lis[upper_bound(lis.begin(), lis.end(), v[i]) - lis.begin()] = v[i];
	}
	return lis;
}