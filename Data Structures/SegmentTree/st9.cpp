// OUTSIDE MAIN


// Include PBDS
class mergeSortTree {
public:

    ll n;
    vector < ordered_set > st; 

    mergeSortTree(ll a[], ll N) {
        n = N;
        st.resize(4*n);
        build(0,a,0,n-1);
    }

    ll left_child(ll i) { return 2 * i + 1; }
    ll right_child(ll i) { return 2 * i + 2; }

    void build(ll id, ll a[], ll left, ll right) {
        if(left == right) {
            st[id].insert(a[left]);
            return;
        }
        ll mid = (left + right) / 2;
        build(left_child(id),a,left,mid);
        build(right_child(id),a,mid+1,right);
        fa(ele,st[left_child(id)]) st[id].insert(ele);
        fa(ele,st[right_child(id)]) st[id].insert(ele);
    }

    void update_element(ll pos, ll old_val, ll new_val) { ue(0,0,n-1,pos,old_val,new_val); }

    void ue(ll id, ll left, ll right, ll pos, ll old_val, ll new_val) {
        if(left == pos && right == pos) {
            st[id].erase(old_val);
            st[id].insert(new_val);
            return;
        }
        ll mid = (left + right) / 2;
        if(mid >= pos) ue(left_child(id),left,mid,pos,old_val,new_val);
        else ue(right_child(id),mid+1,right,pos,old_val,new_val);
        st[id].erase(old_val);
        st[id].insert(new_val);
    }

    ll range_query(ll s, ll e, ll val) { return rq(0,0,n-1,s,e,val); }

    ll rq(ll id, ll left, ll right, ll s, ll e, ll val) {
        if(s <= left && right <= e) return st[id].order_of_key(val);
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