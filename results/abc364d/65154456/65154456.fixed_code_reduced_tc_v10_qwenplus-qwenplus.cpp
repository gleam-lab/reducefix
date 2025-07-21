#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search helper to find k-th smallest distance from b
ll get_kth_distance(ll b, int k) {
    // We want to find the k-th smallest |A[i] - b|
    int n = A.size();
    
    // Binary search on the possible distance value
    ll low = 0, high = 2e8; // Max possible distance is 2*1e8
    ll answer = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        
        // Count how many elements are within distance <= mid from b
        int leftCount = upper_bound(A.begin(), A.end(), b - mid) - A.begin();
        int rightCount = A.end() - lower_bound(A.begin(), A.end(), b + mid);
        int total = n - leftCount - rightCount;
        
        if (total >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return answer;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        cout << get_kth_distance(b, k) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}