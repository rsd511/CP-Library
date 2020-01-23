// OUTSIDE MAIN


// Needed Global
ll n;
vector < vector <ll> > adj;

ll endpoint1, depth1, found;
vector <ll> diameterNodes;

void dfsDiameter(ll u, ll p, ll d)
{
	if(d > depth1) endpoint1 = u, depth1 = d;
	f(i,0,sz(adj[u])-1) if(adj[u][i] != p) dfsDiameter(adj[u][i],u,d+1);
}

void pathDiameter(ll u, ll p, ll dest)
{
	if(u == dest) { found = 1; return; }
	if(found) return;
	f(i,0,sz(adj[u])-1) if(adj[u][i] != p) {
		if(found) break;
		diameterNodes.pb(adj[u][i]);
		pathDiameter(adj[u][i],u,dest);
		if(!found) diameterNodes.pop_back();
	}
}

// Call this
vector <ll> diameterTree()
{
	diameterNodes.clear(); depth1 = 0;
	dfsDiameter(0,0,0);
	ll x = endpoint1;
	depth1 = 0;
	dfsDiameter(x,x,0);
	ll y = endpoint1;
	diameterNodes.pb(x);
	found = 0;
	pathDiameter(x,x,y);
	return diameterNodes;
}