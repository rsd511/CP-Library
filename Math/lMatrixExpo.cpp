// OUTSIDE MAIN


class lMatrixExpo {
public:

    ll k;
    vector <ll> coeff, init;
    vector < vector<ll> > M, Md, res, mul;

    lMatrixExpo(ll c[], ll m[], ll n) {
        k = n; M.resize(n); Md.resize(n); res.resize(n); mul.resize(n);
        f(i,0,n-1) coeff.pb(c[i]);
        f(i,0,n-1) init.pb(m[i]);
        f(i,0,n-1) f(j,0,n-1) M[i].pb(0);
        f(i,0,n-1) f(j,0,n-1) Md[i].pb(0);
        f(i,0,n-1) f(j,0,n-1) res[i].pb(0);
        f(i,0,n-1) f(j,0,n-1) mul[i].pb(0);
        buildMatrix();
    }

    void buildMatrix() {
        f(i,0,k-1) Md[k-1][i] = coeff[k-i-1];
        f(i,0,k-2) Md[i][i+1] = 1;
    }

    void multiply(ll mod) {
        f(i,0,k-1) f(j,0,k-1) mul[i][j] = 0;
        f(i,0,k-1) f(j,0,k-1) f(r,0,k-1) mul[i][j] = (mul[i][j] + (((res[i][r] % mod) * (M[r][j] % mod)) % mod)) % mod;
        f(i,0,k-1) f(j,0,k-1) res[i][j] = mul[i][j];
    }

    void mergeMultiply(ll mod) {
        f(i,0,k-1) f(j,0,k-1) mul[i][j] = 0;
        f(i,0,k-1) f(j,0,k-1) f(r,0,k-1) mul[i][j] = (mul[i][j] + (((M[i][r] % mod) * (M[r][j] % mod)) % mod)) % mod;
        f(i,0,k-1) f(j,0,k-1) M[i][j] = mul[i][j];   
    }

    void fastMaxExpo(ll n, ll mod) {
        f(i,0,k-1) f(j,0,k-1) res[i][j] = 0;
        f(i,0,k-1) res[i][i] = 1;
        f(i,0,k-1) f(j,0,k-1) M[i][j] %= mod;
        while(n > 0) {
            if(n & 1) multiply(mod);
            mergeMultiply(mod);
            n >>= 1;
        }
    }

    // 0-based
    ll query(ll n, ll mod) {
        if(n <= k-1) return init[n];
        n -= k-1;
        f(i,0,k-1) f(j,0,k-1) M[i][j] = Md[i][j] % mod;
        fastMaxExpo(n, mod);
        ll ret = 0;
        f(i,0,k-1) ret = (ret + (((res[k-1][i] % mod) * (init[i] % mod)) % mod)) % mod;
        return ret;
    }

};