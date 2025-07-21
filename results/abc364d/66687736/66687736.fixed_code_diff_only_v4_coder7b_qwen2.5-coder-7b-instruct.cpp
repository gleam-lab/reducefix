#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<pair<long long, int>> distances;
    for(int i = 0; i < q; ++i) {
        long long b;
        int k;
        cin >> b >> k;
        for(int j = 0; j < n; ++j) {
            distances.push_back({abs(a[j] - b), j});
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1].first << '\n';
        distances.clear();
    }

    return 0;
}