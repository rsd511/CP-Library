ll LLIS(vector <ll> v)
{
    vector <ll> liss;
    f(i,0,sz(v)-1) {
        if(sz(liss) == 0) liss.pb(v[i]);
        else if(v[i] > liss[sz(liss)-1]) liss.pb(v[i]);
        else if(v[i] == liss[sz(liss)-1]) continue;
        else liss[lower_bound(liss.begin(), liss.end(), v[i]) - liss.begin()] = v[i];
    }
    return sz(liss);
}

// Returns Seeked LIS
vector <ll> LIS(vector <ll> v, ll llis)
{
    vector <ll> lis;
    ll n = sz(v);
    ll where[n]; f(i,0,n-1) where[i] = -1;
    f(i,0,n-1) {
        if(sz(lis) == 0) {
            lis.pb(v[i]); 
            where[i] = 1;
        }
        else if(v[i] > lis[sz(lis)-1]) {
            lis.pb(v[i]); 
            where[i] = sz(lis);
        }
        else if(v[i] == lis[sz(lis)-1]) continue;
        else {
            ll id = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[id] = v[i]; where[i] = id+1;
        }
    }
    // Seek LIS
    ll id = -1;
    f(i,0,n-1) if(where[i] == llis) {
        id = i; break;
    }
    lis.clear();
    ll target = llis;
    rf(i,id,0) if(where[i] == target && target >= 1) lis.pb(v[i]), target--;
    reverse(lis.begin(), lis.end());
    return lis;
}