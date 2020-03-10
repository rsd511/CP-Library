// OUTSIDE MAIN


// TarjanSCC object_name(n,adjList);
class TarjanSCC {
public:

	ll n;
	vector < vector<ll> > adj;

	ll n_SCC, dfsNumAssigner;
	vector < vector<ll> > SCC;
	vector <ll> dfsNum, dfsLow, visited, stk;

	TarjanSCC(ll N, vector < vector<ll> > graph) {
		n = N; adj = graph;
		n_SCC = dfsNumAssigner = 0;
		dfsLow.clear(); dfsNum.clear();
		visited.clear(); stk.clear();
		f(i,1,n) dfsNum.pb(-1), dfsLow.pb(0);
		f(i,1,n) visited.pb(0);
		f(i,0,n-1) if(dfsNum[i] == -1) dfs(i);
	}

	void dfs(ll u) {
		dfsLow[u] = dfsNum[u] = dfsNumAssigner++;
		stk.pb(u); visited[u] = 1;
		f(i,0,sz(adj[u])-1) {
			ll v = adj[u][i];
			if(dfsNum[v] == -1) dfs(v);
			if(visited[v]) dfsLow[u] = min(dfsLow[u],dfsLow[v]);
		}
		if(dfsLow[u] == dfsNum[u]) {
			vector <ll> new_scc; n_SCC++; 
			while(1) {
				ll cc = stk.back(); stk.pop_back();
				visited[cc] = 0; new_scc.pb(cc);
				if(u == cc) break;
			}
			SCC.pb(new_scc);
		}
	}

};