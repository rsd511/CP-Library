// OUTSIDE MAIN


class mulSrcBFS {
public:

    ll INF = 1000000000;
    vector <ll> dist, visited, par;
    deque <ll> dq;

    mulSrcBFS(ll n, vector < vector <ll> > adj, vector <ll> src) {
        dist.resize(n); f(i,0,n-1) dist[i] = INF; fa(x,src) dist[x] = 0;
        visited.assign(n,0); fa(x,src) visited[x] = 1;
        par.resize(n); fa(x,src) par[x] = x;
        fa(x,src) dq.pb(x);
        while(!dq.empty()) {
            ll u = dq[0]; dq.pop_front();
            f(i,0,sz(adj[u])-1) {
                ll v = adj[u][i];
                if(visited[v]) continue;
                dist[v] = dist[u] + 1;
                visited[v] = 1;
                par[v] = u;
                dq.pb(v);
            }
        }
        f(i,0,n-1) if(dist[i] == 1000000000) dist[i] = -1;
    }

};