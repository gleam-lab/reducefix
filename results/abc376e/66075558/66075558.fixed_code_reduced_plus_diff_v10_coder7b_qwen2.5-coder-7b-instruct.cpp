#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9;

struct Element {
    int val, idx;
};

bool cmp(const Element &a, const Element &b) {
    return a.val != b.val ? a.val < b.val : a.idx < b.idx;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Element> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].val;
            A[i].idx = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i].val;
            B[i].idx = i;
        }
        
        // Sort both arrays based on their values
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end(), cmp);
        
        // Sliding window to find the minimum value of the expression
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + B[i].val;
        }
        
        int minAns = LLONG_MAX;
        for (int i = 0; i <= n - k; ++i) {
            int maxA = A[i + k - 1].val;
            int sumB = prefixSum[i + k] - prefixSum[i];
            minAns = min(minAns, static_cast<long long>(maxA) * sumB);
        }
        
        cout << minAns << '\n';
    }
    
    return 0;
}