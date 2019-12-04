// OUTSIDE MAIN


// Also returns the number of inversions
ll mergesort(ll a[], ll left, ll right) 
{ 
    ll ret = 0; 
    if (right > left) { 
        ll mid = (right + left) / 2; 
        ret = mergesort(a, left, mid); 
        ret += mergesort(a, mid + 1, right);
        ll temp[right-left+1];
        ll i = left, j = mid + 1, k = 0;
        while((i <= mid) && (j <= right)) {
        	if(a[i] <= a[j]) temp[k++] = a[i++];
        	else temp[k++] = a[j++], ret += (mid-i+1);
        }
        while(i <= mid) temp[k++] = a[i++];
        while(j <= right) temp[k++] = a[j++];
        f(i,left,right) a[i] = temp[i-left];
    } 
    return ret; 
}