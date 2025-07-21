#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 200000 + 9;
int a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a, a + n);
        vector<pair<int, int>> AB(n);
        for (int i = 0; i < n; ++i) {
            AB[i] = {b[i], a[n - 1 - i]};
        }
        sort(AB.begin(), AB.end());
        long long ans = LLONG_MAX;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += AB[i].first;
            ans = min(ans, AB[i].second * sum);
        }
        cout << ans << endl;
    }
    return 0;
}