// OUTSIDE MAIN


// Articulation object_name(n,adjList);
class Articulation {
public:

	ll n;
	vector < vector<ll> > adj;

	ll n_articPoint, n_articEdge;
	vector <ll> articPoint;
	vector < pair<ll,ll> > articEdge;

	ll dfsNumAssigner, dfsRoot, rootChildren;
	vector <ll> dfsNum, dfsLow, parent;

	Articulation(ll V, vector < vector<ll> > graph) {
		n = V; adj = graph;
		n_articPoint = 0; n_articEdge = 0;
		articPoint.clear();
		f(i,1,n) articPoint.pb(0);
		articEdge.clear();
		dfsNumAssigner = 0;
		dfsNum.clear(); dfsLow.clear();
		f(i,1,n) dfsNum.pb(-1), dfsLow.pb(0);
		parent.clear(); parent.resize(n);
		f(i,0,n-1) if(dfsNum[i] == -1) {
			dfsRoot = i; rootChildren = 0;
			articDfs(i);
			articPoint[i] = (rootChildren > 1);
		}
		f(i,0,n-1) if(articPoint[i]) n_articPoint++;
		n_articEdge = sz(articEdge);
		sort(articEdge.begin(), articEdge.end());
	}

	void articDfs(ll u) {
		dfsLow[u] = dfsNum[u] = dfsNumAssigner++;
		f(i,0,sz(adj[u])-1) {
			ll v = adj[u][i];
			if(dfsNum[v] == -1) {
				parent[v] = u;
				if(u == dfsRoot) rootChildren++;
				articDfs(v);
				if(dfsNum[u] <= dfsLow[v]) articPoint[u] = 1;
				if(dfsNum[u] < dfsLow[v]) articEdge.pb(mp(u,v));
				dfsLow[u] = min(dfsLow[u],dfsLow[v]);
			}
			else if(v != parent[u]) dfsLow[u] = min(dfsLow[u],dfsNum[v]);
		}
	}

	ll isArticEdge(ll u, ll v) {
		return (binary_search(articEdge.begin(), articEdge.end(), mp(u,v)) 
		|| binary_search(articEdge.begin(), articEdge.end(), mp(v,u)));
	}

};