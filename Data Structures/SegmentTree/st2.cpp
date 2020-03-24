// OUTSIDE MAIN


class segmentTree {
public:

	ll n;
	vector < pair<ll,ll> > st;

	segmentTree(ll a[], ll N) {
		n = N;
		st.resize(4*n);
		build(0,a,0,n-1);
	}

	ll left_child(ll i) { return 2 * i + 1; }
	ll right_child(ll i) { return 2 * i + 2; }

	void build(ll id, ll a[], ll left, ll right) {
		if(left == right) {
			st[id] = mp(a[left],1);
			return;
		}
		ll mid = (left + right) / 2;
		build(left_child(id),a,left,mid);
		build(right_child(id),a,mid+1,right);
		if(st[left_child(id)].ff > st[right_child(id)].ff)
			st[id] = st[left_child(id)];
		else if(st[left_child(id)].ff < st[right_child(id)].ff)
			st[id] = st[right_child(id)];
		else st[id] = mp(st[left_child(id)].ff, st[left_child(id)].ss + st[right_child(id)].ss);
	}

	void update_element(ll pos, ll val) { ue(0,0,n-1,pos,val); }

	void ue(ll id, ll left, ll right, ll pos, ll val) {
		if(left == pos && right == pos) {
			st[id] = mp(val,1);
			return;
		}
		ll mid = (left + right) / 2;
		if(mid < pos) ue(right_child(id),mid+1,right,pos,val);
		else ue(left_child(id),left,mid,pos,val);
		if(st[left_child(id)].ff > st[right_child(id)].ff)
			st[id] = st[left_child(id)];
		else if(st[left_child(id)].ff < st[right_child(id)].ff)
			st[id] = st[right_child(id)];
		else st[id] = mp(st[left_child(id)].ff, st[left_child(id)].ss + st[right_child(id)].ss);
	}

	pair<ll,ll> range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

	pair<ll,ll> rq(ll id, ll left, ll right, ll s, ll e) {
		if(s <= left && right <= e) return st[id];
		pair<ll,ll> ret;
		ll mid = (left + right) / 2;
		if(mid < s) return rq(right_child(id),mid+1,right,s,e);
		if(mid+1 > e) return rq(left_child(id),left,mid,s,e);
		pair<ll,ll> leftq = rq(left_child(id),left,mid,s,e);
		pair<ll,ll> rightq = rq(right_child(id),mid+1,right,s,e);
		if(leftq.ff > rightq.ff)
			ret = leftq;
		else if(leftq.ff < rightq.ff)
			ret = rightq;
		else ret = mp(leftq.ff, leftq.ss + rightq.ss);
		return ret;
	}

};