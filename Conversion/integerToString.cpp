// OUTSIDE MAIN


string intToString(ll n)
{
	if(n == 0) return "0";
	string ret = "";
	bool negative = false;
	if(n < 0) negative = true, n *= -1;
	while(n > 0) {
		ll rem = n % 10;
		ret += (char)(rem + 48);
		n /= 10;
	}
	if(negative) ret.pb('-');
	reverse(ret.begin(), ret.end());
	return ret;
}