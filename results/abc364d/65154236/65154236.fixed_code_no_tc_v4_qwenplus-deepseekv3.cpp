#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        
        // Binary search to find the k-th closest point
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll d_mid = abs(A[mid] - b);
            
            // Count the number of points with distance <= d_mid
            auto it_l = lower_bound(A.begin(), A.end(), b - d_mid);
            auto it_r = upper_bound(A.begin(), A.end(), b + d_mid);
            int count = it_r - it_l;
            
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Now find the exact k-th closest distance
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}