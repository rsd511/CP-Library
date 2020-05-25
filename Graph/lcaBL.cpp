// OUTSIDE MAIN


class LCA {
public:

	ll n, root;
	vector < vector<ll> > adj;

	ll L, timer;
	vector <ll> tin, tout;
	vector < vector<ll> > up;

	LCA(ll N, vector < vector<ll> > tree, ll r) {
		n = N; root = r; adj = tree;
		timer = 0; tin.resize(n); tout.resize(n);
		L = ceil(log2(n));
		up.assign(n,vector<ll>(L+1));
		dfs(root,root);
	}

	void dfs(ll u, ll p) {
		tin[u] = ++timer;
		up[u][0] = p;
		f(i,1,L) up[u][i] = up[up[u][i-1]][i-1];
		fa(v,adj[u]) if(v != p) dfs(v,u);
		tout[u] = ++timer;
	}

	bool is_ancestor(ll u, ll v) { return tin[u] <= tin[v] and tout[u] >= tout[v]; }

	ll lca(ll u, ll v) {
		if(is_ancestor(u,v)) return u;
		if(is_ancestor(v,u)) return v;
		rf(i,L,0) if(!is_ancestor(up[u][i],v)) u = up[u][i];
    	return up[u][0];
	}

	pair < ll,pair<ll,ll> > lca_plus(ll u, ll v) {
		if(is_ancestor(u,v)) {
			rf(i,L,0) if(!is_ancestor(up[v][i],u)) v = up[v][i];
			return mp(u,mp(u,v));
		}
		if(is_ancestor(v,u)) {
			rf(i,L,0) if(!is_ancestor(up[u][i],v)) u = up[u][i];
			return mp(v,mp(u,v));
		}
		rf(i,L,0) if(!is_ancestor(up[u][i],v)) u = up[u][i];
		rf(i,L,0) if(!is_ancestor(up[v][i],u)) v = up[v][i];
		return mp(up[u][0],mp(u,v));
	}

};