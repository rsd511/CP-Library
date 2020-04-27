// OUTSIDE MAIN

ll stringToInt(string s)
{
	if(s[0] == '-') return -1 * stringToInt(s.substr(1));
	ll ret = 0;
	f(i,0,len(s)-1) ret = ret * 10 + (s[i] - 48);
	return ret;
}