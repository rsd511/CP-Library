// OUTSIDE MAIN


// Node creation outside :- segmentTree::node 
class segmentTree {
public:

    struct node {
        ll sum, ans;
        ll prefix, suffix;
    };

    ll n;
    vector <node> st;

    segmentTree(ll a[], ll N) {
        n = N;
        st.resize(4*n);
        build(0,a,0,n-1);
    }

    ll left_child(ll i) { return 2 * i + 1; }
    ll right_child(ll i) { return 2 * i + 2; }

    void build(ll id, ll a[], ll left, ll right) {
        if(left == right) {
            st[id].sum = a[left];
            st[id].ans = a[left];
            st[id].prefix = a[left];
            st[id].suffix = a[left];
            return;
        }
        ll mid = (left + right) / 2;
        build(left_child(id),a,left,mid);
        build(right_child(id),a,mid+1,right);
        st[id].sum = st[left_child(id)].sum + st[right_child(id)].sum;
        st[id].prefix = max(st[left_child(id)].prefix, st[left_child(id)].sum + st[right_child(id)].prefix);
        st[id].suffix = max(st[right_child(id)].suffix, st[right_child(id)].sum + st[left_child(id)].suffix);
        st[id].ans = max({ st[left_child(id)].ans, st[right_child(id)].ans, st[left_child(id)].suffix + st[right_child(id)].prefix });
    }

    void update_element(ll pos, ll val) { ue(0,0,n-1,pos,val); }

    void ue(ll id, ll left, ll right, ll pos, ll val) {
        if(left == pos && right == pos) {
            st[id].sum = val;
            st[id].ans = val;
            st[id].prefix = val;
            st[id].suffix = val;
            return;
        }
        ll mid = (left + right) / 2;
        if(mid < pos) ue(right_child(id),mid+1,right,pos,val);
        else ue(left_child(id),left,mid,pos,val);
        st[id].sum = st[left_child(id)].sum + st[right_child(id)].sum;
        st[id].prefix = max(st[left_child(id)].prefix, st[left_child(id)].sum + st[right_child(id)].prefix);
        st[id].suffix = max(st[right_child(id)].suffix, st[right_child(id)].sum + st[left_child(id)].suffix);
        st[id].ans = max({ st[left_child(id)].ans, st[right_child(id)].ans, st[left_child(id)].suffix + st[right_child(id)].prefix });
    }

    node range_query(ll s, ll e) { return rq(0,0,n-1,s,e); }

    node rq(ll id, ll left, ll right, ll s, ll e) {
        if(s <= left && right <= e) return st[id];
        node ret;
        ll mid = (left + right) / 2;
        if(mid < s) return rq(right_child(id),mid+1,right,s,e);
        if(mid + 1 > e) return rq(left_child(id),left,mid,s,e);
        node leftq = rq(left_child(id),left,mid,s,e);
        node rightq = rq(right_child(id),mid+1,right,s,e);
        ret.sum = leftq.sum + rightq.sum;
        ret.prefix = max(leftq.prefix, leftq.sum + rightq.prefix);
        ret.suffix = max(rightq.suffix, rightq.sum + leftq.suffix);
        ret.ans = max({ leftq.ans, rightq.ans, leftq.suffix + rightq.prefix });
        return ret;
    }

};