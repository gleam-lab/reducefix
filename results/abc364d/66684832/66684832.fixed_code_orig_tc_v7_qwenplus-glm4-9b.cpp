#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100009
#define Q 100009
#define INT_MAX 1000000000

int n, q;
int A[N], B[Q], k[Q];
vector<pair<int, int>> dist(N);

int main() {
    cin >> n >> q;

    // Reading coordinates
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 0; i < q; ++i) cin >> B[i] >> k[i];

    // Calculate all distances and store them with their indices
    for (int i = 1; i <= n; ++i) {
        int d;
        for (int j = 0; j < q; ++j) {
            d = abs(A[i] - B[j]);
            dist[i].push_back({d, i});
        }
    }

    // For each B_j, sort distances and find the k_th smallest distance
    for (int j = 0; j < q; ++j) {
        sort(dist[k[j]].begin(), dist[k[j]].end());
        int ans = 0;
        for (int i = 0; i < k[j]; ++i) {
            ans += abs(A[dist[k[j]][i].second] - B[j]);
        }
        cout << ans << endl;
    }

    return 0;
}