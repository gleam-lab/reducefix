#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e5 + 9;

int n, q;
int a[N];

// Binary search to find the k-th smallest distance
int find_kth_distance(int b, int k) {
    vector<int> distances;
    for (int i = 1; i <= n; ++i) {
        distances.push_back(abs(a[i] - b));
    }
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1); // Sort A points for better cache performance

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << endl;
    }

    return 0;
}