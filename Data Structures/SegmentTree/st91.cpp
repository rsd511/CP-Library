// OUTSIDE MAIN


class segmentTree {
public:

    ll n;
    vector <ll> st, lazy;

    segmentTree(ll a[], ll N) {
        n = N; 
        st.resize(4*n); 
        // Change Lazy Initialization here
        lazy.assign(4*n,0);
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
        // Computation for main query
        st[id] = st[left_child(id)] + st[right_child(id)];
    }

    void propagate(ll id, ll left, ll right) {
        // Passing to main node
        st[id] += (right - left + 1) * lazy[id];
        // Passing to lazy children
        if(left != right) {
            lazy[left_child(id)] += lazy[id];
            lazy[right_child(id)] += lazy[id];
        }
        // Reinitializing Lazy Node
        lazy[id] = 0;
    }

    void update_range(ll s, ll e, ll val) { ur(0,0,n-1,s,e,val); }

    void ur(ll id, ll left, ll right, ll s, ll e, ll val) {
        propagate(id,left,right);
        if(s <= left && right <= e) {
            // Stacking Lazy Node
            lazy[id] += val;
            return;
        }
        ll mid = (left + right) / 2;
        if(s <= mid) ur(left_child(id),left,mid,s,e,val);
        if(e >= mid + 1) ur(right_child(id),mid+1,right,s,e,val);
        propagate(left_child(id),left,mid);
        propagate(right_child(id),mid+1,right);
        // Recomputing for main query
        st[id] = st[left_child(id)] + st[right_child(id)];
    }

    ll range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

    ll rq(ll id, ll left, ll right, ll s, ll e) {
        propagate(id,left,right);
        if(s <= left && right <= e) return st[id];
        // Initialize main query answer
        ll ret = 0;
        ll mid = (left + right) / 2;
        if(mid < s) return rq(right_child(id),mid+1,right,s,e);
        if(mid + 1 > e) return rq(left_child(id),left,mid,s,e);
        ll leftq = rq(left_child(id),left,mid,s,e);
        ll rightq = rq(right_child(id),mid+1,right,s,e);
        // Computing main query
        ret = leftq + rightq;
        return ret;
    }

};