// OUTSIDE MAIN


vector <ll> parent, Rank;

// For 0 to n-1
void constructUFDS(ll n)
{
	parent.clear(); Rank.clear();
	f(i,0,n-1) parent.pb(i), Rank.pb(0);
}

ll findSet(ll u)
{
	if(parent[u] == u) return u;
	else return parent[u] = findSet(parent[u]);
}

ll isSameSet(ll u, ll v) { return (findSet(u) == findSet(v)); }

void unionSet(ll u, ll v)
{
	if(isSameSet(u,v)) return;
	ll pu = findSet(u), pv = findSet(v);
	if(Rank[pu] > Rank[pv]) parent[pv] = pu;
	else {
		parent[pu] = pv;
		if(Rank[pu] == Rank[pv]) Rank[pv]++;	
	}
}