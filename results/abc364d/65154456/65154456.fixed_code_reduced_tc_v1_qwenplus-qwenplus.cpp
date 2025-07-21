#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b_j to elements in A
ll get_kth_distance(ll b, int k) {
    int n = A.size();
    vector<pair<ll, int>> candidates;
    
    // Find the closest point using binary search
    auto it = lower_bound(A.begin(), A.end(), b);
    int idx = it - A.begin();
    
    // Two pointers for left and right of the closest point
    int left = idx - 1;
    int right = idx;
    
    // We need k-th smallest distance
    multiset<ll> distances;
    
    while (distances.size() < k && (left >= 0 || right < n)) {
        if (distances.size() == k) break;
        
        ll d_left = (left >= 0) ? abs(b - A[left]) : LLONG_MAX;
        ll d_right = (right < n) ? abs(b - A[right]) : LLONG_MAX;
        
        if (d_left <= d_right) {
            distances.insert(d_left);
            left--;
        } else {
            distances.insert(d_right);
            right++;
        }
    }
    
    // The k-th smallest distance is at the beginning of the set
    return *distances.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        cout << get_kth_distance(b, k) << endl;
    }
    
    return 0;
}