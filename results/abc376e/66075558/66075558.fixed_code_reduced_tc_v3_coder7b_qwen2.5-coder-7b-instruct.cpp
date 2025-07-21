#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

struct Data{
    int val, idx;
};

bool cmp(const Data&a, const Data&b){
    if(a.val == b.val)return a.idx < b.idx;
    return a.val > b.val;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<Data>A(n+1), B(n+1);
        
        for(int i=1; i<=n; ++i) cin >> A[i].val, A[i].idx = i;
        for(int i=1; i<=n; ++i) cin >> B[i].val, B[i].idx = i;
        
        sort(A.begin()+1, A.end(), cmp);
        sort(B.begin()+1, B.end(), cmp);
        
        int ans = inf;
        for(int i=1; i+k-1<=n; ++i){
            int mx = A[i].val, sm = 0;
            for(int j=i; j<i+k; ++j) sm += B[j].val;
            ans = min(ans, mx * sm);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}