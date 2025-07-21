for(ll s=0;s<=B[i];s++){
    ll t=(max(0LL,x-A[i]*s)+B[i]-1)/B[i];
    val=min(val,s*P[i]+t*Q[i]);
}