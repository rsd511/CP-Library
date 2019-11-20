// OUTSIDE MAIN

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); }

ll lcm(ll a, ll b) { if (a == 0 || b == 0) return 0; return ((a / gcd(a,b)) * b); }