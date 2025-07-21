#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

int check(int x, int y, int z) {
    vector<int> distances;
    for (int i = 1; i <= n; ++i) {
        distances.push_back(abs(a[i] - y));
    }
    sort(distances.begin(), distances.end());
    return distances[z - 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        cin >> x >> y;
        cout << check(x, y, x) << "\n"; // Adjusted the call to check function
    }
    return 0;
}