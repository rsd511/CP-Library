// OUTSIDE MAIN


// Current functionality -> Count of Distinct Numbers
// Range till 10^6 (Change to map for higher)

ll n,q;
vector <ll> v;
vector < pair < pair<ll,ll>,ll > > query;

ll mo_left, mo_right, curr_ans, blockSize;
vector <ll> answer;

// Functionality Variables
// For Counting Distinct Numbers
ll mo_map[1000001];

// Query comparing function
bool compareQuery(pair < pair<ll,ll>,ll > x, pair < pair<ll,ll>,ll > y) 
{
    ll block_x = x.ff.ff / blockSize;
    ll block_y = y.ff.ff / blockSize;
    if(block_x != block_y) return block_x < block_y;
    return x.ff.ss < y.ff.ss;
}

// Add function
void add(ll id) 
{
	if(mo_map[v[id]] <= 0) mo_map[v[id]] = 1, curr_ans++;
	else mo_map[v[id]] += 1;
}

// Remove function
void remove(ll id)
{
	mo_map[v[id]] -= 1;
	if(mo_map[v[id]] <= 0) curr_ans--;
}

// Takes array, for vector change argument datatype
void MO(ll a[], vector < pair<ll,ll> > queries) 
{
	v.clear(); 
	f(i,0,n-1) v.pb(a[i]);
	query.clear();
	f(i,0,q-1) query.pb(mp(mp(queries[i].ff,queries[i].ss),i));
	mo_left = 0; mo_right = -1;
	answer.clear(); answer.resize(q);
	blockSize = (ll)sqrt(n);
	sort(query.begin(), query.end(), compareQuery);
	f(i,0,1000000) mo_map[i] = 0;
	// Initialize
	curr_ans = 0;
	f(i,0,q-1) {
		ll left = query[i].ff.ff;
		ll right = query[i].ff.ss;
		while(mo_right < right) mo_right++, add(mo_right);
        while(mo_right > right) remove(mo_right), mo_right--;
        while(mo_left < left) remove(mo_left), mo_left++;
        while(mo_left > left) mo_left--, add(mo_left);
        answer[query[i].ss] = curr_ans;
	}
}