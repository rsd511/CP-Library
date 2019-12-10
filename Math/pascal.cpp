// OUTSIDE MAIN


// Calculates till Max for N & R
# define MAX 1000
ll C[MAX + 1][MAX + 1];

void build_pascal()
{
	f(i,0,MAX) f(j,0,MAX) 
	C[i][j] = 0; C[0][0] = 1;
    f(i,1,MAX) {
    	C[i][0] = 1;
    	f(j,1,i) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}



// INSIDE MAIN

build_pascal();