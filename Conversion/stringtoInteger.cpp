// OUTSIDE MAIN

ll stringToInt(string s)
{
	ll ret = 0;
	f(i,0,len(s)-1) ret = ret * 10 + (s[i] - 48);
	return ret;
}