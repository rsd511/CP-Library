// OUTSIDE MAIN


// SQRT object_name(array_name, n);
class SQRT {
public:

	ll n, sqrtN;
	vector <ll> a,b;

	// Change this function to change initiation
	ll init() { return 0; }

	// Change this function to change behaviour
	ll compute(ll a, ll b) { return (a + b); }

	// Takes array, for vector change argument datatype
	SQRT(ll v[], ll N) {
		n = N; a.clear(); b.clear();
		f(i,0,n-1) a.pb(v[i]);
		sqrtN = (ll)sqrt(n) + 1;
		f(i,1,sqrtN) b.pb(init());
		f(i,0,n-1) b[i/sqrtN] = compute(b[i/sqrtN],a[i]);
	}

	ll rq(ll s, ll e) {
		ll result = init();
		while(s % sqrtN != 0 && s <= e) result = compute(result,a[s++]);
		while(e % sqrtN != sqrtN - 1 && e >= s) result = compute(result,a[e--]);
		while(s < e) result = compute(result,b[s/sqrtN]), s += sqrtN;
		return result;
	}

};