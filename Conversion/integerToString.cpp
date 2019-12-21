// OUTSIDE MAIN


string intToString(ll n)
{
	if(n == 0) return "0";
	string ret = "";
	while(n > 0) {
		ll rem = n % 10;
		ret += (char)(rem + 48);
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}