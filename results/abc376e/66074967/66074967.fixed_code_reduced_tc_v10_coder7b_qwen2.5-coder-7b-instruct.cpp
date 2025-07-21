#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 9;
ll n, k, t, ans;

struct Pair {
    ll val, idx;
};

bool compare(Pair &a, Pair &b) {
    return a.val < b.val;
}

ll solve() {
    vector<Pair> A(n), B(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].val;
        A[i].idx = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i].val;
        B[i].idx = i;
    }
    
    // Sort A based on values
    sort(A.begin(), A.end(), compare);
    
    // Create an array to store the sorted indices of A
    vector<ll> sortedIndices(n);
    for (int i = 0; i < n; ++i) {
        sortedIndices[A[i].idx] = i;
    }
    
    // Sort B based on the sorted indices of A
    vector<ll> sortedB(n);
    for (int i = 0; i < n; ++i) {
        sortedB[i] = B[sortedIndices[i]].val;
    }
    
    // Sliding window to find the minimum product
    ll maxVal = 0, sum = 0;
    for (int i = 0; i < k; ++i) {
        maxVal = max(maxVal, A[i].val);
        sum += sortedB[i];
    }
    ans = maxVal * sum;
    
    for (int i = k; i < n; ++i) {
        maxVal = max(maxVal, A[i].val);
        sum += sortedB[i] - sortedB[i - k];
        ans = min(ans, maxVal * sum);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ans = solve();
        cout << ans << '\n';
    }
    
    return 0;
}