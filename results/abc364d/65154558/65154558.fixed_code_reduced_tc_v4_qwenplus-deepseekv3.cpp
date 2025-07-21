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
        ll b, k;
        cin >> b >> k;
        
        int left = lower_bound(A.begin(), A.end(), b) - A.begin();
        int right = left;
        vector<ll> distances;
        
        int l = left - 1, r = right;
        for (int i = 0; i < k; ++i) {
            ll left_dist = (l >= 0) ? abs(b - A[l]) : LLONG_MAX;
            ll right_dist = (r < N) ? abs(b - A[r]) : LLONG_MAX;
            if (left_dist <= right_dist) {
                distances.push_back(left_dist);
                --l;
            } else {
                distances.push_back(right_dist);
                ++r;
            }
        }
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}