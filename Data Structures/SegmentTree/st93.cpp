// OUTSIDE MAIN


class pSegmentTree {
public:

    struct Vertex {
        Vertex *left_child, *right_child;
        ll sum;

        Vertex(ll val) : left_child(nullptr), right_child(nullptr), sum(val) {}
        Vertex(Vertex *left_child, Vertex *right_child) : left_child(left_child), right_child(right_child), sum(0) {
            if(left_child) sum += left_child->sum;
            if(right_child) sum += right_child->sum;
        }
    };

    ll n;
    vector <Vertex*> root;

    pSegmentTree(ll a[], ll N) {
        n = N;
        root.pb(build(a,0,n-1));
    }

    Vertex* build(ll a[], ll left, ll right) {
        if(left == right) return new Vertex(a[left]);
        ll mid = (left + right) / 2;
        return new Vertex(build(a,left,mid), build(a,mid+1,right));
    }

    void update_element(ll id, ll pos, ll val) { root.pb(ue(root[id],0,n-1,pos,val)); }

    Vertex* ue(Vertex* v, ll left, ll right, ll pos, ll val) {
        if(left == right) return new Vertex(v->sum + val);
        ll mid = (left + right) / 2;
        if(mid < pos) return new Vertex(v->left_child, ue(v->right_child,mid+1,right,pos,val));
        else return new Vertex(ue(v->left_child,left,mid,pos,val), v->right_child); 
    }

    ll range_query(ll id, ll s, ll e) { return rq(root[id],0,n-1,s,e); }

    ll rq(Vertex* v, ll left, ll right, ll s, ll e) {
        if(s <= left && right <= e) return v->sum;
        ll ret = 0;
        ll mid = (left + right) / 2;
        if(mid < s) return rq(v->right_child,mid+1,right,s,e);
        if(mid + 1 > e) return rq(v->left_child,left,mid,s,e);
        ll leftq = rq(v->left_child,left,mid,s,e);
        ll rightq = rq(v->right_child,mid+1,right,s,e);
        ret = leftq + rightq;
        return ret;
    }

};