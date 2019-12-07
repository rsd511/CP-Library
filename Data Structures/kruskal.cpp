// OUTSIDE MAIN


// NOTE :- Include UFDS structure

// Kruskal object_name(n,edges);
class Kruskal {
public:

	ll n, weight;
	vector < vector< pair<ll,ll> > > spanningTree;

	// Takes 0-based Edges
	Kruskal(ll N, vector < pair < ll,pair<ll,ll> > > edges) {
		n = N; weight = 0;
		spanningTree.clear(); spanningTree.resize(n);
		sort(edges.begin(), edges.end());
		ll edge_count = 0;
		UFDS ufds(n);
		f(i,0,sz(edges)-1) {
			ll u = edges[i].ss.ff;
			ll v = edges[i].ss.ss;
			ll w = edges[i].ff;
			if(ufds.isSameSet(v,u)) continue;
			spanningTree[u].pb(mp(v,w));
			spanningTree[v].pb(mp(u,w));
			ufds.unionSet(u,v);
			edge_count++;
			weight += w;
			if(edge_count == n-1) break;
		}
	}

};