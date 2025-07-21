#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX_N = 100000 + 10;
const int MAX_Q = 100000 + 10;
const long long INF = 1e18;

int a[MAX_N];
long long distances[MAX_N][MAX_Q];
bool sorted[MAX_N];

int compare(int i, int j) {
    return distances[i][0] < distances[j][0];
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < q; ++j) {
        cin >> distances[j][1] >> distances[j][0];
    }

    // Calculate distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            distances[j][0] = abs(a[i] - distances[j][1]);
        }
    }

    // Sort distances for each point A_i
    for (int i = 0; i < n; ++i) {
        sort(distances[i], distances[i] + q, compare);
        sorted[i] = true;
    }

    // Find k-th closest point for each query
    for (int j = 0; j < q; ++j) {
        for (int i = 0; i < n; ++i) {
            if (sorted[i] && distances[i][j][0] == distances[j][0] && distances[i][j][1] == j + 1) {
                cout << distances[i][j][0] << endl;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}