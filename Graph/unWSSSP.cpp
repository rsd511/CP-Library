// OUTSIDE MAIN


// unWSSSP object_name(n,adjList,source);
class unWSSSP {
public:

    ll INF = 1000000000;
    vector <ll> dist, visited, par;
    deque <ll> dq;

    unWSSSP(ll n, vector < vector <ll> > adj, ll src) {
        dist.clear(); f(i,1,n) dist.pb(INF); dist[src] = 0;
        visited.assign(n,0); visited[src] = 1;
        par.resize(n); par[src] = src;
        dq.pb(src);
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