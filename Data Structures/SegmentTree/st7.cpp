// OUTSIDE MAIN


class mergeSortTree {
public:

    ll n;
    vector < vector<ll> > st; 

    mergeSortTree(ll a[], ll N) {
        n = N;
        st.resize(4*n);
        build(0,a,0,n-1);
    }

    ll left_child(ll i) { return 2 * i + 1; }
    ll right_child(ll i) { return 2 * i + 2; }

    void build(ll id, ll a[], ll left, ll right) {
        if(left == right) {
            st[id].pb(a[left]);
            return;
        }
        ll mid = (left + right) / 2;
        build(left_child(id),a,left,mid);
        build(right_child(id),a,mid+1,right);
        st[id].resize(sz(st[left_child(id)]) + sz(st[right_child(id)]));
        merge(st[left_child(id)].begin(), st[left_child(id)].end(), st[right_child(id)].begin(), st[right_child(id)].end(), st[id].begin());
    }

    ll range_query(ll s, ll e, ll val) { return rq(0,0,n-1,s,e,val); }

    ll rq(ll id, ll left, ll right, ll s, ll e, ll val) {
        if(s <= left && right <= e) return lower_bound(st[id].begin(), st[id].end(), val) - st[id].begin();
        ll ret = 0;
        ll mid = (left + right) / 2;
        if(mid < s) return rq(right_child(id),mid+1,right,s,e,val);
        if(mid + 1 > e) return rq(left_child(id),left,mid,s,e,val);
        ll leftq = rq(left_child(id),left,mid,s,e,val);
        ll rightq = rq(right_child(id),mid+1,right,s,e,val);
        ret = leftq + rightq;
        return ret;
    }

};