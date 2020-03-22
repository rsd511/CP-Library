// OUTSIDE MAIN


ll isPalindrome(string s)
{
	if(s == "") return 1;
	ll n = len(s);
	ll l = 0, r = n-1;
	while(l < r) {
		if(s[l] != s[r]) {
			return 0;
		}
		l++; r--;
	}
	return 1;
}