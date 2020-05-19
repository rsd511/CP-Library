// OUTSIDE MAIN

// p - reference, q - 1st point, r - 2nd point
// 0 - collinear, 1 - clockwise, -1 - anti-clockwise
ll orientation(pair <ll,ll> p, pair <ll,ll> q, pair <ll,ll> r) 
{
    ll val = (q.ss - p.ss) * (r.ff - q.ff) - (q.ff - p.ff) * (r.ss - q.ss);
    if (val == 0) return 0;
    return (val > 0)? 1: -1; 
}