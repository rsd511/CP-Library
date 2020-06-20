// OUTSIDE MAIN


class kosaraju {
public:

	ll n;
	vector < vector <ll> > adj, radj;

	ll n_scc;
	vector <bool> vis;
	vector <ll> order, component;
	vector < vector <ll> > SCC;

	vector <ll> group;
	set < pair<ll,ll> > edge;
	vector < vector <ll> > gSCC;

	kosaraju(ll N, vector < vector <ll> > graph) {
		n = N; adj = graph; radj.resize(n);
		f(u,0,n-1) fa(v,adj[u]) radj[v].pb(u);
		vis.assign(n,false);
		f(i,0,n-1) if(!vis[i]) dfs(i);
		vis.assign(n,false);
		reverse(order.begin(), order.end());
		f(i,0,n-1) if(!vis[order[i]]) {
			dfs2(order[i]);
			SCC.pb(component);
			component.clear();
		}
		n_scc = sz(SCC);
	}

	void dfs(ll u) {
		vis[u] = true;
		fa(v,adj[u]) if(!vis[v]) dfs(v);
		order.pb(u);
	}

	void dfs2(ll u) {
		vis[u] = true;
		component.pb(u);
		fa(v,radj[u]) if(!vis[v]) dfs2(v);
	}

	void condensate() {
		group.resize(n);
		f(i,0,n_scc-1) fa(x,SCC[i]) group[x] = i;
		gSCC.resize(n_scc);
		f(u,0,n-1) fa(v,adj[u])
			if(group[u] != group[v])
				edge.insert(mp(group[u],group[v]));
		fa(x,edge) gSCC[x.ff].pb(x.ss);
	}

};