#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

void solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i]};
    }
    
    // Sort by A[i] and then by B[i]
    sort(AB.begin(), AB.end());
    
    // Calculate the prefix sums of B[i]
    vector<long long> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + AB[i - 1].second;
    }
    
    // Find the minimum product
    long long ans = inf;
    for (int i = k - 1; i < n; ++i) {
        ans = min(ans, static_cast<long long>(AB[i].first) * (prefix_sum[n] - prefix_sum[i]));
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        solve(n, k, A, B);
    }
    
    return 0;
}