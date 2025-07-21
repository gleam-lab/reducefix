#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> a, b;

// Function to calculate the maximum sum of B for subsets with max element <= x
int maxSumWithMax.getX(int x) {
    int maxSum = 0;
    vector<int> prefixSum(b.size() + 1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            prefixSum[i + 1] = prefixSum[i] + b[i];
        } else {
            break;
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++) {
        int sum = 0, count = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += b[j];
                count++;
            }
        }
        if (count != 0 && count != n) {
            int tempSum = prefixSum[n] - prefixSum[min(n, __builtin_ctz(i) + 1)];
            sum += tempSum;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int left = 0, right = a.back();
        int ans = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxSum = maxSumWithMax.getX(mid);
            if (maxSum >= mid) {
                ans = min(ans, maxSum);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}