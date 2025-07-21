#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int n, q;
int a[N];

int find_kth_distance(int b, int k) {
    vector<int> distances(n);
    for (int i = 0; i < n; ++i) {
        distances[i] = abs(a[i] - b);
    }
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << endl;
    }

    return 0;
}