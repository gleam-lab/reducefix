#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, k, t;

struct Pair {
    int value;
    int index;
    Pair(int val, int idx) : value(val), index(idx) {}
};

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<Pair> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].value;
            a[i].index = i;
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i].value;
            b[i].index = i;
        }
        
        sort(a.begin(), a.end(), [](const Pair& x, const Pair& y) {
            return x.value > y.value;
        });
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + b[a[i].index].value;
        }
        
        long long ans = LLONG_MAX;
        for (int i = 0, sum = 0; i < k - 1; ++i) {
            sum += b[a[i].index].value;
        }
        ans = min(ans, (long long)a[k - 1].value * sum);
        
        for (int i = 1; i < n - k + 1; ++i) {
            sum -= b[a[i + k - 2].index].value;
            sum += b[a[i + k - 1].index].value;
            ans = min(ans, (long long)a[i + k - 1].value * prefixSum[i + k - 1]);
        }
        
        cout << ans << endl;
    }
    return 0;
}