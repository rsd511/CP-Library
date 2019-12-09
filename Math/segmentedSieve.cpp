// OUTSIDE MAIN


// Calculates till MAX
#define MAX 1000000

ll isPrime[MAX + 1];

void sieve()
{
	isPrime[0] = isPrime[1] = 0;
	f(i,2,MAX) isPrime[i] = 1;
	for(ll i = 2; i*i <= MAX; i++) if(isPrime[i]) {
		for(ll j = i*i; j <= MAX; j += i)
			isPrime[j] = 0;
	}
}

vector <ll> segmentedSieve(ll low, ll high) {
	low = max(low,(ll)2);
	vector <ll> ret; ret.clear();
	ll limit = (ll)sqrt(high) + 1;
	ll n = high - low + 1;
	ll mark[n + 1] = {0};
	f(i,2,limit) if(isPrime[i]) {
		ll lowerLimit = (low / i) * i;
		if(lowerLimit < low) lowerLimit += i;
		if(lowerLimit == i) lowerLimit += i;
		for(ll j = lowerLimit; j <= high; j += i)
			mark[j-low] = 1;
	}
	f(i,low,high) if(!mark[i-low]) ret.pb(i);
	return ret;
}



// INSIDE MAIN

sieve();