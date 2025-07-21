#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 9;
int n, q;
int a[N], b[N], k[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    for (int i = 0; i < q; ++i) {
        int b_i = b[i];
        int k_i = k[i];

        // Calculate the distance from B_j to all A_i and sort them
        vector<pair<int, int>> dist(n);
        for (int j = 0; j < n; ++j) {
            dist[j] = {abs(a[j] - b_i), a[j]};
        }
        sort(dist.begin(), dist.end());

        // Find the k_i-th closest point to B_j
        int x = dist[k_i - 1].second;
        long long answer = abs(x - b_i);
        cout << answer << endl;
    }

    return 0;
}