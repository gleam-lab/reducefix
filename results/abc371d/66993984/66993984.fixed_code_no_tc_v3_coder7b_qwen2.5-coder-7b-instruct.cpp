#include<bits/stdc++.h>
using namespace std;

int n,q,x[200005],p[200005];
vector<int>sum;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(i==1) sum.push_back(p[i]);
        else sum.push_back(sum.back() + p[i]);
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        auto it1 = lower_bound(x, x+n, L);
        auto it2 = upper_bound(x, x+n, R);
        int c = distance(x, it1) + (it1 != x ? 1 : 0);
        int d = distance(x, it2) + (it2 != x+n ? 1 : 0);
        cout<<sum[d-1]-(c==1?0:sum[c-2])<<endl;
    }
}