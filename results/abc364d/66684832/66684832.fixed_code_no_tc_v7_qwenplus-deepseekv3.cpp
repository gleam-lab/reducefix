#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 10;
int a[N];

int find_kth_distance(int x, int k, int n) {
    vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        distances[i] = abs(a[i] - x);
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(a[i] - x);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}