#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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
        vector<ll> distances;
        for (ll num : a) {
            distances.push_back(abs(num - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}