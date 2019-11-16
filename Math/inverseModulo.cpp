// OUTSIDE MAIN

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    }
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}

ll invMOD(ll b, ll m) 
{ 
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    return (x % m + m) % m; 
}