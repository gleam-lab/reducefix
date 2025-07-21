#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        k--; // Convert to 0-based index
        
        // Binary search to find the k-th closest point
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            ll diff_mid = abs(A[mid] - b);
            ll diff_mid_plus_1 = (mid + 1 < N) ? abs(A[mid + 1] - b) : LLONG_MAX;
            ll diff_mid_minus_1 = (mid > 0) ? abs(A[mid - 1] - b) : LLONG_MAX;
            
            if (abs(A[mid] - b) < abs(A[mid + 1] - b)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        int start = max(0, left - k);
        int end = min(N - 1, left + k);
        
        vector<ll> distances;
        for (int i = start; i <= end; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}