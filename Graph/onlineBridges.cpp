// OUTSIDE MAIN


pair<ll,ll> minMaxPair(ll a, ll b) {
    if(a > b) swap(a,b);
    return mp(a,b);
}

ll lca_identify;
vector <ll> val;
vector <ll> par, dsu_cc, dsu_2ecc, dsu_cc_size;
set < pair<ll,ll> > bridge;
map < pair<ll,ll>, pair<ll,ll> > Real;

void init(ll n)
{
    par.resize(n);
    dsu_2ecc.resize(n);
    dsu_cc.resize(n);
    dsu_cc_size.resize(n);
    val.assign(n,-1);
    lca_identify = 0;
    bridge.clear();
    f(i,0,n-1) {
        dsu_cc[i] = dsu_2ecc[i] = i;
        dsu_cc_size[i] = 1;
        par[i] = -1;
    }
}

ll find_2ecc(ll i) { 
    if(i == -1) return i;
    if(dsu_2ecc[i] == i) return i; 
    else return dsu_2ecc[i] = find_2ecc(dsu_2ecc[i]); 
}

ll find_cc(ll i) { 
    if(i == -1) return i;
    if(dsu_cc[i] == i) return i; 
    else return dsu_cc[i] = find_cc(dsu_cc[i]); 
}

void make_root(ll u)
{
    u = find_2ecc(u);
    ll root = u;
    ll child = -1;
    while(u != -1) {
        ll p = find_2ecc(par[u]);
        par[u] = child;
        dsu_cc[u] = root;
        child = u;
        u = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_cycle(ll u, ll v)
{
    lca_identify++;
    vector <ll> path_u, path_v;
    ll lca = -1;
    while(lca == -1) {
        if(u != -1) {
            u = find_2ecc(u);
            path_u.pb(u);
            if(val[u] == lca_identify) lca = u;
            val[u] = lca_identify;
            u = par[u];                
        }
        if(v != -1) {
            v = find_2ecc(v);
            path_v.pb(v);
            if(val[v] == lca_identify) lca = v;
            val[v] = lca_identify;
            v = par[v];    
        }
    }
    f(i,0,sz(path_u)-1) {
        dsu_2ecc[path_u[i]] = lca;
        if(path_u[i] == lca) break;
        bridge.erase(Real[minMaxPair(path_u[i],path_u[i+1])]);
    }
    f(i,0,sz(path_v)-1) {
        dsu_2ecc[path_v[i]] = lca;
        if(path_v[i] == lca) break;
        bridge.erase(Real[minMaxPair(path_v[i],path_v[i+1])]);
    }
}

void add_edge(ll u, ll v)
{
    ll du = u, dv = v;
    u = find_2ecc(u);
    v = find_2ecc(v);
    if(u == v) return;
    ll tu = find_cc(u);
    ll tv = find_cc(v);
    if(tu == tv) merge_cycle(u,v);
    else {
        bridge.insert(minMaxPair(du,dv));
        Real[minMaxPair(u,v)] = minMaxPair(du,dv);
        if(dsu_cc_size[tu] > dsu_cc_size[tv]) {
            swap(u,v);
            swap(tu,tv);
        }
        make_root(u);
        par[u] = v;
        dsu_cc[u] = v;
        dsu_cc_size[tv] += dsu_cc_size[u];
    }
}



// INSIDE MAIN


init(n);