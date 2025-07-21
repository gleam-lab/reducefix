#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

struct node {
    int val, idx;
};

bool cmp(node a, node b) {
    return a.val == b.val ? a.idx < b.idx : a.val < b.val;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<node> A(n), B(n);
        for(int i=0; i<n; ++i) {
            cin >> A[i].val;
            A[i].idx = i;
        }
        for(int i=0; i<n; ++i) {
            cin >> B[i].val;
            B[i].idx = i;
        }
        
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        
        vector<int> prefix_sum(n+1);
        for(int i=0; i<n; ++i) {
            prefix_sum[i+1] = prefix_sum[i] + B[A[i].idx];
        }
        
        int ans = inf;
        for(int i=k-1; i<n; ++i) {
            int max_val = A[i].val;
            int sum_val = prefix_sum[i+1] - prefix_sum[i-k+1];
            ans = min(ans, static_cast<long long>(max_val) * sum_val);
        }
        
        cout << ans << endl;
    }
    return 0;
}