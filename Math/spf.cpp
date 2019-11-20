// OUTSIDE MAIN


// Calculates till MAX
#define MAX 1000000

ll spf[MAX+1];

void buildSPF()
{
	f(i,0,MAX) spf[i] = 0;
	f(i,2,MAX) {
		if(spf[i] == 0) {
			spf[i] = i;
			for(ll j = i + i; j <= MAX; j += i)
				if(spf[j] == 0)
					spf[j] = i;
		}
	}
}


// INSIDE MAIN

buildSPF();