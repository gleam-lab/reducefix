#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum = (sum + arr[(i + j - 1) % n]) % m;
            if (sum == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}