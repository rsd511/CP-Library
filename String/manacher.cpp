// OUTSIDE MAIN


void manacher(string s, vector <ll> *d1, vector <ll> *d2) 
{
	ll n = len(s);
	(*d1).resize(n);
	(*d2).resize(n);
	for (ll i = 0, l = 0, r = -1; i < n; i++) {
	    ll k = (i > r) ? 1 : min((*d1)[l + r - i], r - i + 1);
	    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
	        k++;
	    }
	    (*d1)[i] = k--;
	    if (i + k > r) {
	        l = i - k;
	        r = i + k;
	    }
	}
	for (ll i = 0, l = 0, r = -1; i < n; i++) {
	    ll k = (i > r) ? 0 : min((*d2)[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
	        k++;
	    }
	    (*d2)[i] = k--;
	    if (i + k > r) {
	        l = i - k - 1;
	        r = i + k ;
	    }
	}
}


// INSIDE MAIN


vector <ll> odd, even;
manacher(s,&odd,&even);