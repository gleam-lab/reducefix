#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 9;
int n, k, ans;
vector<pair<int, int>> a, b;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n), b.resize(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        
        vector<int> sumB(k + 1, 0);
        for (int i = 0; i < k; ++i) {
            sumB[i + 1] = sumB[i] + b[a[i].second].first;
        }

        ans = INT_MAX;
        for (int i = k; i <= n; ++i) {
            ans = min(ans, (sumB[i] - sumB[i - k]) * a[i - 1].first);
        }

        cout << ans << '\n';
    }

    return 0;
}