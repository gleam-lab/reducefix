#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N], dist[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int b, k;
        cin >> b >> k;
        dist[i] = a[b] - b; // Compute the distance from point B_j to each point A_i
    }
    sort(dist + 1, dist + 1 + n); // Sort the distances
    for (int i = 1; i <= q; i++) {
        // Find the k-th closest point to B_j in the sorted list of distances
        cout << dist[i + k - 1] << endl;
    }
    return 0;
}