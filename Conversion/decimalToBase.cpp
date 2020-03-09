// OUTSIDE MAIN


string decToBase(ll n, ll b)
{
	if(n == 0) return "0";
	string ret = "";
	while(n > 0) {
		ll rem = n % b;
		ret += (char)(rem+48);
		n /= b;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}