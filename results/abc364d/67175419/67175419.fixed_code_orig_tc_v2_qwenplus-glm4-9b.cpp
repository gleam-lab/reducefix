int l=0,r=1e8;
while(l<=r)
{
    int mid=(l+r)/2;
    if(!check(mid,x,y))
        l=mid+1;
    else
        r=mid-1;
}