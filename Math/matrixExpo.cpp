// OUTSIDE MAIN


ll M[2][2], res[2][2];

void multiply(ll a[2][2], ll b[2][2], ll mod) {
    ll mul[2][2];
    f(i,0,1) f(j,0,1) mul[i][j] = 0;
    f(i,0,1) f(j,0,1) f(k,0,1) mul[i][j] = (mul[i][j] + a[i][k] * b[k][j] + mod) % mod;
    f(i,0,1) f(j,0,1) a[i][j] = mul[i][j];
}

void fastMaxExpo(ll n, ll mod) {
    f(i,0,1) f(j,0,1) {
        if(i == j) res[i][j] = 1;
        else res[i][j] = 0;
    }
    while(n > 0) {
        if(n & 1) multiply(res,M,mod);
        multiply(M,M,mod);
        n >>= 1;
    }
}