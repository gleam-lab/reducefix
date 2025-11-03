#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        int b, k;
        cin >> b >> k;
        vector<int> distances;
        for (int i = 0; i < N; i++) {
            distances.push_back(abs(a[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}