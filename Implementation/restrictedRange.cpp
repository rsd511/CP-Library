// OUTSIDE MAIN


// Change argument data type here
vector <ll> left_range(vector <ll> v, ll n)
{
	vector <ll> ret(n);
	ret[0] = 0;
	deque < pair<ll,ll> > stk; stk.pb(mp(v[0],0));
	f(i,1,n-1) {
		while(sz(stk) != 0) {
			ll u = stk[sz(stk)-1].ff, pos = stk[sz(stk)-1].ss;
			// Change Restriction Here
			if(u > v[i]) {
				ret[i] = pos+1;
				stk.pb(mp(v[i],i));
				break;
			}
			else {
				stk.pop_back();
			}
		}
		if(sz(stk) == 0) {
			ret[i] = 0;
			stk.pb(mp(v[i],i));
		}
	}
	return ret;
}



// INSIDE MAIN

// Add-on for right_range
reverse(v.begin(), v.end());
vector <ll> right = left_range(v,n);
reverse(v.begin(), v.end());
reverse(right.begin(), right.end());
f(i,0,n-1) right[i] = n-1-right[i];