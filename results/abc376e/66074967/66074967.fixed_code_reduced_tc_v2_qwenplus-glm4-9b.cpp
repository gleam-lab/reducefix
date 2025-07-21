#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long ans = 1e18;
        long long sum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            sum += B[right];
            while (right - left + 1 > k) {
                sum -= B[left++];
            }
            if (right - left + 1 == k) {
                ans = min(ans, (long long)A[right] * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}