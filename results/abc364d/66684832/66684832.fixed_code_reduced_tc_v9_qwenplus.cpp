#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int INF = 1e18;

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
        k--; // convert to 0-indexed

        // We'll collect distances from B to all A points, then get the k-th smallest
        vector<int> distances;
        for (int i = 0; i < N; i++) {
            distances.push_back(abs(a[i] - b));
        }
        nth_element(distances.begin(), distances.begin() + k, distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}