// OUTSIDE MAIN


// Dijkstra object_name(n,adjList,source);
class Dijkstra {
public:

	ll INF = 1000000000000000000;
	vector <ll> dist;
	priority_queue < pair<ll,ll> , vector < pair<ll,ll> > , greater < pair<ll,ll> > > pq;

	Dijkstra(ll n, vector < vector < pair<ll,ll> > > adj, ll src) {
		dist.clear(); f(i,1,n) dist.pb(INF); dist[src] = 0;
		pq.push(mp(0,src));
		while(!pq.empty()) {
			pair<ll,ll> tar = pq.top(); pq.pop();
			ll d = tar.ff, u = tar.ss;
			if(d > dist[u]) continue;
			f(i,0,sz(adj[u])-1) {
				ll v = adj[u][i].ff, w = adj[u][i].ss;
				if(dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.push(mp(dist[v],v));
				}
			}
		}
		f(i,0,n-1) if(dist[i] == 1000000000000000000) dist[i] = -1;
	}

};