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
        ll b, k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        auto cmp = [b](ll x, ll y) {
            return abs(x - b) < abs(y - b);
        };
        
        nth_element(a.begin(), a.begin() + k - 1, a.end(), cmp);
        cout << abs(a[k - 1] - b) << '\n';
    }
    
    return 0;
}