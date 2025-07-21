#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e5 + 9;
int n, q;
vector<int> a(N + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        // Calculate distances between each A_i and B_j
        vector<pair<int, int>> dists;
        for (int j = 1; j <= n; j++) {
            int d = abs(a[j] - b);
            dists.emplace_back(d, j);
        }
        // Sort distances
        sort(dists.begin(), dists.end());

        // Get the k-th closest point
        int ans = dists[k - 1].second;
        cout << a[ans] << endl;
    }

    return 0;
}