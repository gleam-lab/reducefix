#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

struct node{
    int val,idx;
};

bool cmp(node &a,node &b){
    return a.val>b.val;
}
signed main() {
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<node> A(n),B(n);
        for(int i=0;i<n;i++){
            cin>>A[i].val;
            A[i].idx=i;
        }
        for(int i=0;i<n;i++){
            cin>>B[i].val;
        }
        sort(A.begin(),A.end(),cmp);
        sort(B.begin(),B.end());
        int sum=0,ans=inf;
        for(int i=0;i<k;i++){
            sum+=B[A[i].idx];
        }
        for(int i=0;i<=n-k;i++){
            ans=min(ans,sum*A[i].val);
            if(i+k<n){
                sum-=B[A[i].idx];
                sum+=B[A[i+k].idx];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}