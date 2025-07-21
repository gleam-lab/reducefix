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
        int l1=1,r1=n,l2=1,r2=n;
        
        // Find first x[i] >= l
        while (l1<r1){
            int mid=l1+(r1-l1)/2;
            if (x[mid]>=l) r1=mid;
            else l1=mid+1;
        }
        if (x[l1] < l) l1 = n + 1; // no elements >= l
        
        // Find last x[i] <= r
        while (l2<r2){
            int mid=l2+(r2-l2+1)/2;
            if (x[mid]<=r) l2=mid;
            else r2=mid-1;
        }
        if (x[l2] > r) l2 = 0; // no elements <= r
        
        if (l1 <= l2 && l1 >=1 && l2 <=n)
            cout<<a[l2]-a[l1-1]<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}