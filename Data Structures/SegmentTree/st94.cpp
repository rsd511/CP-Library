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
    vector <ll> vec;
    map <ll,ll> Map;
    vector <Vertex*> root;

    pSegmentTree(ll org[], ll N) {
        n = N;
        set <ll> s; f(i,0,n-1) s.insert(org[i]);
        fa(x,s) vec.pb(x);
        f(i,0,sz(vec)-1) Map[vec[i]] = i;
        ll a[n]; f(i,0,n-1) a[i] = 0;
        root.pb(build(a,0,n-1));
        f(i,0,n-1) update_element(sz(root)-1,Map[org[i]],1);
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

    ll range_query(ll s, ll e, ll k) { return vec[rq(root[s],root[e+1],0,n-1,k)]; }

    ll rq(Vertex* vl, Vertex* vr, ll left, ll right, ll k) {
        if(left == right) return left;
        ll mid = (left + right) / 2;
        ll left_count = vr->left_child->sum - vl->left_child->sum;
        if(k <= left_count) return rq(vl->left_child,vr->left_child,left,mid,k);
        else return rq(vl->right_child,vr->right_child,mid+1,right,k-left_count);
    }

};