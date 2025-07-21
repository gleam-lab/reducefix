for(int i=0;i<N;i++){
    ll val=INF;
    for(ll s=0;s<=B[i];s++){//機械sをB[i]代まで使う
        ll t=(max(0LL,x-A[i]*s)+B[i]-1)/B[i];
        val=min(val,s*P[i]+t*Q[i]);
    }

    for(ll t=0;t<=A[i];t++){//機械tをA[i]台まで使う
        ll s=(max(0LL,x-B[i]*t)+A[i]-1)/A[i];
        val=min(val,t*Q[i]+s*P[i]);
    }
    if(val==INF){
        return false; // If we cannot achieve the processing capacity with the given budget, return false.
    }
    res-=val;
}