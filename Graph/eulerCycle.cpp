// OUTSIDE MAIN


// For 1-component (undirected)
class eulerCycle {
public:

	ll n, m;
	vector < set<ll> > adj;

	bool isCycle;
	vector <ll> cycle;

	eulerCycle(ll N, vector < vector<ll> > graph) {
		n = N; m = 0;
		f(i,0,n-1) m += sz(graph[i]);
		m /= 2; adj.resize(n);
		f(i,0,n-1) fa(x,graph[i]) adj[i].insert(x);
		isCycle = true;
		f(i,0,n-1) if(sz(graph[i]) % 2) isCycle = false;
		if(isCycle) dfs(0);
	}

	void dfs(ll u) {
		while(sz(adj[u]) > 0) {
			ll v = *adj[u].begin();
			adj[u].erase(v);
			adj[v].erase(u);
			dfs(v);
		}
		cycle.pb(u);
	}

};