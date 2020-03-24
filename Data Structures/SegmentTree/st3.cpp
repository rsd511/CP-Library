class segmentTree {

private:

	ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); }

	ll lcm(ll a, ll b) { if (a == 0 || b == 0) return 0; return ((a / gcd(a,b)) * b); }

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
			st[id] = mp(a[left],a[left]);
			return;
		}
		ll mid = (left + right) / 2;
		build(left_child(id),a,left,mid);
		build(right_child(id),a,mid+1,right);
		st[id] = mp(gcd(st[left_child(id)].ff,st[right_child(id)].ff),lcm(st[left_child(id)].ss,st[right_child(id)].ss));
	}

	void update_element(ll pos, ll val) { ue(0,0,n-1,pos,val); }

	void ue(ll id, ll left, ll right, ll pos, ll val) {
		if(left == pos && right == pos) {
			st[id] = mp(val,val);
			return;
		}
		ll mid = (left + right) / 2;
		if(mid < pos) ue(right_child(id),mid+1,right,pos,val);
		else ue(left_child(id),left,mid,pos,val);
		st[id] = mp(gcd(st[left_child(id)].ff,st[right_child(id)].ff),lcm(st[left_child(id)].ss,st[right_child(id)].ss));
	}

	pair <ll,ll> range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

	pair <ll,ll> rq(ll id, ll left, ll right, ll s, ll e) {
		if(s <= left && right <= e) return st[id];
		pair <ll,ll> ret;
		ll mid = (left + right) / 2;
		if(mid < s) return rq(right_child(id),mid+1,right,s,e);
		if(mid + 1 > e) return rq(left_child(id),left,mid,s,e);
		pair <ll,ll> leftq = rq(left_child(id),left,mid,s,e);
		pair <ll,ll> rightq = rq(right_child(id),mid+1,right,s,e);
		ret = mp(gcd(leftq.ff,rightq.ff),lcm(leftq.ss,rightq.ss));
		return ret;
	}

};