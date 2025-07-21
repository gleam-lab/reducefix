#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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
        vector<ll> distances;
        int idx = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        int left = max(0, idx - 100000);
        int right = min(N, idx + 100000);
        for (int i = left; i < right; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}