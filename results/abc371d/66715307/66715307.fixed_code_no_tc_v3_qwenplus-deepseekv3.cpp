#include <bits/stdc++.h>
using namespace std;
int n,x[200050],p[200050],q,a[200050];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=n;i++){
        cin>>p[i];
        a[i]=a[i-1]+p[i];
    }
    cin>>q;
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int l1=1,r1=n;
        while (l1<=r1){
            int mid=(l1+r1)/2;
            if (x[mid]>=l) r1=mid-1;
            else l1=mid+1;
        }
        int l2=1,r2=n;
        while (l2<=r2){
            int mid=(l2+r2)/2;
            if (x[mid]<=r) l2=mid+1;
            else r2=mid-1;
        }
        if (l1<=n && r2>=1 && l1<=r2)
            cout<<a[r2]-a[l1-1]<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}