// OUTSIDE MAIN


// Pass 2D Vector by address
class segmentTree2D {
public:

    ll n, m;
    vector < vector<ll> > st;

    segmentTree2D(vector < vector<ll> > * a, ll N, ll M) {
        n = N; m = M;
        st.resize(4*n, vector <ll> (4*m));
        build_x(0,a,0,n-1);
    }

    ll left_child(ll i) { return 2 * i + 1; }
    ll right_child(ll i) { return 2 * i + 2; }

    void build_y(ll id_x, ll left_x, ll right_x, ll id_y, ll left_y, ll right_y, vector < vector<ll> > * a) {
        if(left_y == right_y) {
            if(left_x == right_x) st[id_x][id_y] = (*a)[left_x][left_y];
            else st[id_x][id_y] = st[left_child(id_x)][id_y] + st[right_child(id_x)][id_y];
            return;
        }
        ll mid_y = (left_y + right_y) / 2;
        build_y(id_x,left_x,right_x,left_child(id_y),left_y,mid_y,a);
        build_y(id_x,left_x,right_x,right_child(id_y),mid_y+1,right_y,a);
        st[id_x][id_y] = st[id_x][left_child(id_y)] + st[id_x][right_child(id_y)];
    }

    void build_x(ll id_x, vector < vector<ll> > * a, ll left_x, ll right_x) {
        if(left_x < right_x) {
            ll mid_x = (left_x + right_x) / 2;
            build_x(left_child(id_x),a,left_x,mid_x);
            build_x(right_child(id_x),a,mid_x+1,right_x);
        }
        build_y(id_x,left_x,right_x,0,0,m-1,a);
    }

    void update_element(ll x, ll y, ll val) { ue_x(0,0,n-1,x,y,val); }

    void ue_y(ll id_x, ll left_x, ll right_x, ll id_y, ll left_y, ll right_y, ll x, ll y, ll val) {
        if(left_y == right_y) {
            if(left_x == right_x) st[id_x][id_y] = val;
            else st[id_x][id_y] = st[left_child(id_x)][id_y] + st[right_child(id_x)][id_y];
            return;
        }
        ll mid_y = (left_y + right_y) / 2;
        if(mid_y < y) ue_y(id_x,left_x,right_x,right_child(id_y),mid_y+1,right_y,x,y,val);
        else ue_y(id_x,left_x,right_x,left_child(id_y),left_y,mid_y,x,y,val);
        st[id_x][id_y] = st[id_x][left_child(id_y)] + st[id_x][right_child(id_y)];
    }

    void ue_x(ll id_x, ll left_x, ll right_x, ll x, ll y, ll val) {
        if(left_x < right_x) {
            ll mid_x = (left_x + right_x) / 2;
            if(mid_x < x) ue_x(right_child(id_x),mid_x+1,right_x,x,y,val);
            else ue_x(left_child(id_x),left_x,mid_x,x,y,val);
        }
        ue_y(id_x,left_x,right_x,0,0,m-1,x,y,val);
    }

    // Format :- P1.x, P1.y ; P2.x, P2.y
    ll range_query(ll x1, ll y1, ll x2, ll y2) { 
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        return rq_x(0,0,n-1,x1,x2,y1,y2);
    }

    ll rq_y(ll id_x, ll id_y, ll left_y, ll right_y, ll y1, ll y2) {
        if(y1 <= left_y && right_y <= y2) return st[id_x][id_y];
        ll ret = 0;
        ll mid_y = (left_y + right_y) / 2;
        if(mid_y < y1) return rq_y(id_x,right_child(id_y),mid_y+1,right_y,y1,y2);
        if(mid_y + 1 > y2) return rq_y(id_x,left_child(id_y),left_y,mid_y,y1,y2);
        ll leftq = rq_y(id_x,left_child(id_y),left_y,mid_y,y1,y2);
        ll rightq = rq_y(id_x,right_child(id_y),mid_y+1,right_y,y1,y2);
        ret = leftq + rightq;
        return ret;
    }

    ll rq_x(ll id_x, ll left_x, ll right_x, ll x1, ll x2, ll y1, ll y2) {
        if(x1 <= left_x && right_x <= x2) return rq_y(id_x,0,0,m-1,y1,y2);
        ll ret = 0;
        ll mid_x = (left_x + right_x) / 2;
        if(mid_x < x1) return rq_x(right_child(id_x),mid_x+1,right_x,x1,x2,y1,y2);
        if(mid_x + 1 > x2) return rq_x(left_child(id_x),left_x,mid_x,x1,x2,y1,y2);
        ll leftq = rq_x(left_child(id_x),left_x,mid_x,x1,x2,y1,y2);
        ll rightq = rq_x(right_child(id_x),mid_x+1,right_x,x1,x2,y1,y2);
        ret = leftq + rightq;
        return ret;
    }

};