#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        vector<ll> distances;
        int l = pos - 1, r = pos;
        for (int i = 0; i < k; ++i) {
            if (l >= 0 && (r >= N || abs(a[l] - b) <= abs(a[r] - b))) {
                distances.push_back(abs(a[l] - b));
                --l;
            } else {
                distances.push_back(abs(a[r] - b));
                ++r;
            }
        }
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}