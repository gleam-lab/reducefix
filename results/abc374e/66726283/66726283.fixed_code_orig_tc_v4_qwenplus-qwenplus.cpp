#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, x;
int a[N], p[N], b[N], q[N];

int computeMinCost(int i, int mid) {
    int minCost = LLONG_MAX;
    // Try all possible number of type A attacks
    for (int j = 0; j <= b[i]; j++) {
        int remaining = max(0LL, mid - j * a[i]);
        int neededB = (remaining + b[i] - 1) / b[i];
        minCost = min(minCost, j * p[i] + neededB * q[i]);
    }
    // Try all possible number of type B attacks
    for (int j = 0; j <= a[i]; j++) {
        int remaining = max(0, mid - j * b[i]);
        int neededA = (remaining + a[i] - 1) / a[i];
        minCost = min(minCost, j * q[i] + neededA * p[i]);
    }
    return minCost;
}

bool isPossible(int mid) {
    int totalCost = 0;
    for (int i = 1; i <= n; i++) {
        int itemCost = computeMinCost(i, mid);
        totalCost += itemCost;
        if (totalCost > x) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int low = 0, high = 20000000, answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer;
    return 0;
}