#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 5;
vector<int> a(N);

int main() {
    int n, q, b, k, ans;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int j = 0; j < q; ++j) {
        cin >> b >> k;
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = abs(b - a[i]);
        }
        sort(distances.begin(), distances.end());
        ans = distances[k - 1];
        cout << ans << "\n";
    }
    
    return 0;
}