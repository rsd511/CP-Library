// OUTSIDE MAIN

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); }