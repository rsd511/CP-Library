// OUTSIDE MAIN


vector <ll> LPS(string s)
{
	ll n = len(s);
	vector <ll> ret(n); ret[0] = 0;
	ll id = 0, i = 1;
	while(i < n) {
		if(s[i] == s[id]) ret[i++] = ++id;
		else {
			if(id != 0) id = ret[id-1];
			else ret[i++] = 0;
		}
	}
	return ret;
}