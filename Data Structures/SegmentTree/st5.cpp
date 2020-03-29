// OUTSIDE MAIN


class segmentTree {
public:

    ll n;
    vector <ll> st;

    segmentTree(ll a[], ll N) {
        n = N;
        st.resize(4*n);
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
        st[id] = max(st[left_child(id)],st[right_child(id)]);
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
        st[id] = max(st[left_child(id)],st[right_child(id)]);
    }

    ll range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

    ll rq(ll id, ll left, ll right, ll s, ll e) {
        if(s <= left && right <= e) return st[id];
        ll ret;
        ll mid = (left + right) / 2;
        if(mid < s) return rq(right_child(id),mid+1,right,s,e);
        if(mid + 1 > e) return rq(left_child(id),left,mid,s,e);
        ll leftq = rq(left_child(id),left,mid,s,e);
        ll rightq = rq(right_child(id),mid+1,right,s,e);
        ret = max(leftq, rightq);
        return ret;
    }

    ll lower_bound(ll l, ll r, ll val) { return lb(0,0,n-1,l,r,val); }

    ll lb(ll id, ll left, ll right, ll s, ll e, ll val) {
        if(st[id] < val) return -1;
        if(left == right) return left;
        if(s <= left && right <= e) {
            ll mid = (left + right) / 2;
            if(st[left_child(id)] >= val) return lb(left_child(id),left,mid,s,e,val);
            else return lb(right_child(id),mid+1,right,s,e,val);
        }
        ll ret;
        ll mid = (left + right) / 2;
        if(mid < s) return lb(right_child(id),mid+1,right,s,e,val);
        if(mid + 1 > e) return lb(left_child(id),left,mid,s,e,val);
        ret = lb(left_child(id),left,mid,s,e,val);
        if(ret == -1) return lb(right_child(id),mid+1,right,s,e,val);
        else return ret;
    }

    ll upper_bound(ll l, ll r, ll val) { return ub(0,0,n-1,l,r,val); }

    ll ub(ll id, ll left, ll right, ll s, ll e, ll val) {
        if(st[id] <= val) return -1;
        if(left == right) return left;
        if(s <= left && right <= e) {
            ll mid = (left + right) / 2;
            if(st[left_child(id)] > val) return ub(left_child(id),left,mid,s,e,val);
            else return ub(right_child(id),mid+1,right,s,e,val);
        }
        ll ret;
        ll mid = (left + right) / 2;
        if(mid < s) return ub(right_child(id),mid+1,right,s,e,val);
        if(mid + 1 > e) return ub(left_child(id),left,mid,s,e,val);
        ret = ub(left_child(id),left,mid,s,e,val);
        if(ret == -1) return ub(right_child(id),mid+1,right,s,e,val);
        else return ret;
    }

};