while(hi-lo>1){
    int mid = (hi+lo)>>1;
    if(f(mid))lo=mid;
    else hi=mid-1;
}
if(lo!=hi && f(lo+1))lo++;