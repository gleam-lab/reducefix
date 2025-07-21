#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        vector<int> distances(N);
        rep(i, N) distances[i] = abs(a[i] - b);
        
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}