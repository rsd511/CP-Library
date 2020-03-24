// OUTSIDE MAIN


class segmentTree {
public:

	ll n, target;
	vector <ll> st;

	segmentTree(ll a[], ll N, ll tar) {
		n = N;
		target = tar;
		st.assign(4*n,0);
		build(0,a,0,n-1);
	}

	ll left_child(ll i) { return 2 * i + 1; }
	ll right_child(ll i) { return 2 * i + 2; }

	void build(ll id, ll a[], ll left, ll right) {
		if(left == right) {
			st[id] = (a[left] == target) ? 1 : 0;
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
			st[id] = (val == target) ? 1 : 0;
			return;
		}
		ll mid = (left + right) / 2;
		if(mid >= pos) ue(left_child(id),left,mid,pos,val);
		else ue(right_child(id),mid+1,right,pos,val);
		st[id] = st[left_child(id)] + st[right_child(id)];
	}

	ll range_query_freq(ll s, ll e) { return rqf(0,0,n-1,s,e); }

	ll rqf(ll id, ll left, ll right, ll s, ll e) {
		if(s <= left && right <= e) return st[id];
		ll ret = 0;
		ll mid = (left + right) / 2;
		if(mid < s) return rqf(right_child(id),mid+1,right,s,e);
		if(mid + 1 > e) return rqf(left_child(id),left,mid,s,e);
		ll leftq = rqf(left_child(id),left,mid,s,e);
		ll rightq = rqf(right_child(id),mid+1,right,s,e);
		ret += leftq + rightq;
		return ret;
	}

	ll range_query_kth(ll s, ll e, ll k) { 
		ll padding = 0, total = 0;
		if(s-1 >= 0) padding = range_query_freq(0,s-1);
		total = range_query_freq(0,e);
		if(padding+k > total) return -1;
		return rqk(0,0,n-1,padding+k);
	}

	ll rqk(ll id, ll left, ll right, ll k) {
		if(left == right) return left;
		ll mid = (left + right) / 2;
		if(k <= st[left_child(id)]) return rqk(left_child(id),left,mid,k);
		else return rqk(right_child(id),mid+1,right,k-st[left_child(id)]);
	}

};