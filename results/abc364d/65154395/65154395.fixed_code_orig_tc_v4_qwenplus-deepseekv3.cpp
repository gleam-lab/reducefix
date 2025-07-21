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
        k--; // convert to 0-based index
        
        int left = 0;
        int right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        vector<ll> distances;
        int l = pos - 1;
        int r = pos;
        for (int i = 0; i < N; ++i) {
            if (l >= 0 && r < N) {
                if (abs(A[l] - b) <= abs(A[r] - b)) {
                    distances.push_back(abs(A[l] - b));
                    l--;
                } else {
                    distances.push_back(abs(A[r] - b));
                    r++;
                }
            } else if (l >= 0) {
                distances.push_back(abs(A[l] - b));
                l--;
            } else {
                distances.push_back(abs(A[r] - b));
                r++;
            }
        }
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}