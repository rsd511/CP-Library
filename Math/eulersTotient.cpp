// OUTSIDE MAIN


ll eulers_totient(ll n, vector <ll> prime_factors)
{
	ll ret = n;
	fa(x,prime_factors) ret *= (x - 1);
	fa(x,prime_factors) ret /= x;
	return ret;
}