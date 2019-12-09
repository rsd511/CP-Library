// OUTSIDE MAIN


// LCA object_name(n,adjList,root);
class LCA {
public:

	ll n, level;
	vector < vector<ll> > adj;
	vector <ll> depth;
	vector < vector<ll> > parent;

	LCA(ll N, vector < vector<ll> > tree, ll root) {
		n = N; adj = tree; level = 25;
		depth.resize(n); depth[root] = 0;
		parent.assign(n,vector <ll> (level,-1));
		dfs(root,root);
		f(i,1,level-1) f(node,0,n-1) if(parent[node][i-1] != -1)
		parent[node][i] = parent[parent[node][i-1]][i-1];
	}

	void dfs(ll u, ll p) {
		if(u != p) depth[u] = depth[p] + 1;
		parent[u][0] = p;
		f(i,0,sz(adj[u])-1) if(adj[u][i] != p) dfs(adj[u][i],u);
	}

	ll lca(ll u, ll v) {
		if(depth[v] < depth[u]) swap(u,v);
		ll diff = depth[v] - depth[u]; 
		f(i,0,level-1) if((diff>>i)&1) v = parent[v][i];
		if(u == v) return u;
		rf(i,level-1,0) if(parent[u][i] != parent[v][i])
		u = parent[u][i], v = parent[v][i];
		return parent[u][0]; 
	}

};