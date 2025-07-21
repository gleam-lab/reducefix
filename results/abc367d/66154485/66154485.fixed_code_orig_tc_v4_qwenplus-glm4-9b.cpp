#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> prefixSum(n + 1, 0);

    // Read input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int ans = 0;

    // Calculate the number of valid subsequences
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((prefixSum[j + 1] - prefixSum[i]) % m == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}