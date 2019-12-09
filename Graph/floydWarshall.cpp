// INSIDE MAIN

f(k,0,n-1) f(i,0,n-1) f(j,0,n-1)
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);