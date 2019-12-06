// OUTSIDE MAIN


// segmentTree obj_name(array_name,n);
class segmentTree {
public:

	ll n;
	vector <ll> st, lazy;

	// Change this function to change ST initiation
	ll init() { return 0; }

	// Change this function to change ST behaviour
	ll compute(ll a, ll b) { return (a+b); }

	// Change this function to change Update behaviour
	ll compute_update(ll a, ll b, ll left, ll right) { return (a + (b * (right - left + 1))); }

	// Change this function to change Lazy initiation
	ll init_lazy() { return 0; }

	// Change this function to change Lazy behaviour
	ll compute_lazy(ll a, ll b) { return (a+b); }

	// Takes array, for vector change argument datatype
	segmentTree(ll a[], ll N) {
		n = N;  st.clear(); lazy.clear();
		st.resize(4*N); f(i,1,4*N) lazy.pb(init_lazy());
		buildST(0,a,0,N-1);
	}

	ll left_child(ll id) { return (2*id + 1); }

	ll right_child(ll id) { return (2*id + 2); }

	// Takes array, for vector change argument datatype
	void buildST(ll id, ll a[], ll left, ll right) {
		if(left == right) {
			st[id] = a[left];
			return;
		}
		ll mid = (left + right) / 2;
		buildST(left_child(id),a,left,mid);
		buildST(right_child(id),a,mid+1,right);
		st[id] = compute(st[left_child(id)], st[right_child(id)]);
	}

	void update(ll s, ll e, ll val) { update_range(0,0,n-1,val,s,e); }

	void update_node(ll id, ll left, ll right) {
		st[id] = compute_update(st[id],lazy[id],left,right);
		if(left < right) {
			lazy[left_child(id)] = compute_lazy(lazy[left_child(id)],lazy[id]);
			lazy[right_child(id)] = compute_lazy(lazy[right_child(id)],lazy[id]);
		}
		lazy[id] = init_lazy();
	}

	void update_range(ll id, ll left, ll right, ll val, ll s, ll e) {
		update_node(id,left,right);
		if(left >= s && right <= e) {
			lazy[id] = compute_lazy(lazy[id],val);
			return;
		}
		ll mid = (left + right) / 2;
		if(mid >= s && left <= e) update_range(left_child(id),left,mid,val,s,e);
		if(right >= s && mid + 1 <= e) update_range(right_child(id),mid+1,right,val,s,e);
		update_node(left_child(id),left,mid);
		update_node(right_child(id),mid+1,right);
		st[id] = compute(st[left_child(id)], st[right_child(id)]);
	}

	ll rq(ll s, ll e) { return range_query(0,0,n-1,s,e); }

	ll range_query(ll id, ll left, ll right, ll s, ll e) {
		update_node(id,left,right);
		if(left >= s && right <= e) return st[id];
		ll result = init();
		ll mid = (left + right) / 2;
		if(mid >= s && left <= e) 
			result = compute(result,range_query(left_child(id),left,mid,s,e));
		if(right >= s && mid + 1 <= e) 
			result = compute(result,range_query(right_child(id),mid+1,right,s,e));
		return result;
	}

};