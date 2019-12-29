// OUTSIDE MAIN


vector <ll> Z(string s) 
{
	ll n = len(s);
    vector <ll> z(n); z[0] = 0;
    ll l = 0, r = 0;
    f(i,1,n-1) {
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
    return z;
}