// OUTSIDE MAIN


// Calculates till MAX ( < 10^7)
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

vector < pair<ll,ll> > primeFactorsWithCountOf(ll n)
{
	 vector < pair<ll,ll> > ret;
	 while(n > 1) {
	 	ll currentFactor = spf[n];
	 	ll currentCount = 0;
	 	while(n % currentFactor == 0) n /= currentFactor, currentCount++;
	 	ret.pb(mp(currentFactor,currentCount));
	 }
	 return ret;
}


// INSIDE MAIN

buildSPF();