// OUTSIDE MAIN


vector <ll> KMPsearch(string txt, string pat)
{
	vector <ll> ret;
	ll m = len(pat), n = len(txt);
	ll lps[m]; lps[0] = 0;
	ll id = 0, i = 1;
	while(i < m) {
		if(pat[i] == pat[id]) lps[i++] = ++id;
		else {
			if(id != 0) id = lps[id-1];
			else lps[i++] = 0;
		}
	}
	ll j = 0; i = 0;
	while(i < n) {
		if(pat[j] == txt[i]) i++, j++;
		if(j == m) ret.pb(i-j), j = lps[j-1];
		else if(i < n && pat[j] != txt[i]) {
			if(j != 0) j = lps[j-1];
			else i++;
		}
	}

	return ret;
}