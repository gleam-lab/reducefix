#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    rep(q, Q) {
        ll b, k;
        cin >> b >> k;
        vector<ll> distances;
        distances.reserve(N);
        for (ll a : A) {
            distances.push_back(abs(a - b));
        }
        nth_element(distances.begin(), distances.begin() + (k - 1), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}