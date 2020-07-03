// OUTSIDE MAIN


// sparseTable object_name(array_name, n);
class sparseTable {
public:

	ll n, k = 25;
	vector < vector<ll> > st;

	// Change this function to change initiation
	ll init() { return -1000000000; }

	// Change this function to change behaviour
	ll compute(ll a, ll b) { return max(a,b); }

	// Takes array, for vector change argument datatype
	sparseTable(ll a[], ll N) {
		st.clear(); n = N; st.resize(n); 
		f(i,0,n-1) st[i].resize(k+1), st[i][0] = a[i];
		f(j,1,k) f(i,0,n-(1<<j)) 
			st[i][j] = compute(st[i][j-1], st[i + (1<<(j-1))][j-1]);
	}

	ll rq(ll left, ll right) {
		ll result = init();
		rf(j,k,0) if((1<<j) <= right - left + 1)
			result = compute(result, st[left][j]), left += (1<<j);
		return result;
	}

};