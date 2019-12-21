// OUTSIDE MAIN


string decToBase(ll n, ll b)
{
	if(n == 0) return "0";
	string ret = "";
	while(n > 0) {
		ll rem = n % b;
		if(rem <= 9) ret += (char)(rem+48);
		else ret += (char)(rem+55);
		n /= b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}