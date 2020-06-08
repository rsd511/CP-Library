// OUTSIDE MAIN


ll compute_hash(string& s) {
    ll p = 31;
    ll m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    fa(c,s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}