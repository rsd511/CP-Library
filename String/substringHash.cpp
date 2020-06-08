// OUTSIDE MAIN


ll n, p, m, pinv;
vector <ll> p_pow, pinv_pow, p_hash;

void build_substring_hash(string& s)
{
	n = len(s); p = 31; m = 1e9 + 9;
	// Only for this p = 31 & m = 1e9 + 9
	pinv = 838709685;
	p_pow.resize(n+1); pinv_pow.resize(n+1);
	p_pow[0] = 1; pinv_pow[0] = 1;
	f(i,1,n) p_pow[i] = (p_pow[i-1] * p) % m;
	f(i,1,n) pinv_pow[i] = (pinv_pow[i-1] * pinv) % m;
	p_hash.resize(n); p_hash[0] = (s[0] - 'a' + 1) % m;
	f(i,1,n-1) p_hash[i] = (p_hash[i-1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
}

ll substring_hash(ll l, ll r)
{
	ll ret = p_hash[r];
	if(l > 0) ret = (ret - p_hash[l-1] + m) % m;
	ret = (ret * pinv_pow[l]) % m;
	return ret;
}



// INSIDE MAIN

build_substring_hash(s);