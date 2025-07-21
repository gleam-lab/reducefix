#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int a[N];

int find_kth_distance(int n, int x, int k) {
    vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        distances[i] = abs(a[i + 1] - x);
    }
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << find_kth_distance(n, x, k) << endl;
    }

    return 0;
}