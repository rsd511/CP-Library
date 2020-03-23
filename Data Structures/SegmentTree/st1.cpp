// OUTSIDE MAIN


class segmentTree {
public:

	ll n;
	vector <ll> st;

	segmentTree(ll a[], ll N) {
		n = N;
		st.assign(4*n,0);
		build(0,a,0,n-1);
	}

	ll left_child(ll i) { return 2 * i + 1; }
	ll right_child(ll i) { return 2 * i + 2; }

	void build(ll id, ll a[], ll left, ll right) {
		if(left == right) {
			st[id] = a[left];
			return;
		}
		ll mid = (left + right) / 2;
		build(left_child(id),a,left,mid);
		build(right_child(id),a,mid+1,right);
		st[id] = st[left_child(id)] + st[right_child(id)];
	}

	void update_element(ll pos, ll val) { ue(0,0,n-1,pos,val); }

	void ue(ll id, ll left, ll right, ll pos, ll val) {
		if(left == pos && right == pos) {
			st[id] = val;
			return;
		}
		ll mid = (left + right) / 2;
		if(mid >= pos) ue(left_child(id),left,mid,pos,val);
		else ue(right_child(id),mid+1,right,pos,val);
		st[id] = st[left_child(id)] + st[right_child(id)];
	}

	ll range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

	ll rq(ll id, ll left, ll right, ll s, ll e) {
		if(s <= left && right <= e) return st[id];
		ll ret = 0;
		ll mid = (left + right) / 2;
		if(mid < s) return rq(right_child(id),mid+1,right,s,e);
		if(mid + 1 > e) return rq(left_child(id),left,mid,s,e);
		ll leftq = rq(left_child(id),left,mid,s,e);
		ll rightq = rq(right_child(id),mid+1,right,s,e);
		ret += leftq + rightq;
		return ret;
	}

};