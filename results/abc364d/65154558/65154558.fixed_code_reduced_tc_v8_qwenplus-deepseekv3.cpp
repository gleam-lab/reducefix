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
        
        int l = left - 1, r = left;
        for (int i = 0; i < k && (l >= 0 || r < N); ++i) {
            if (l >= 0 && r < N) {
                if (b - A[l] <= A[r] - b) {
                    distances.push_back(b - A[l]);
                    --l;
                } else {
                    distances.push_back(A[r] - b);
                    ++r;
                }
            } else if (l >= 0) {
                distances.push_back(b - A[l]);
                --l;
            } else {
                distances.push_back(A[r] - b);
                ++r;
            }
        }
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}