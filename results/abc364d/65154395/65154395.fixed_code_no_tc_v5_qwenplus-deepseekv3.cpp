#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        vector<ll> distances;
        for (int i = max(0, pos - 100); i < min(N, pos + 100); i++) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        
        if (k <= distances.size()) {
            cout << distances[k - 1] << endl;
        } else {
            distances.clear();
            for (int i = 0; i < N; i++) {
                distances.push_back(abs(A[i] - b));
            }
            sort(distances.begin(), distances.end());
            cout << distances[k - 1] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}