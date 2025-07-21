#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    int a, p, b, q;
};

long long dp[100][10005]; // Increased size to accommodate larger inputs

int N, X;

long long cost(const vector<Item>& items, int i, int n) {
    int a = items[i].a, b = items[i].b, p = items[i].p, q = items[i].q;
    int d = n / (a * b), rem = n % (a * b);
    return dp[i][rem] + d * (a > b ? p : q);
}

bool canMake(vector<Item>& items, int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(items, i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int binarySearch(vector<Item>& items) {
    int left = 0, right = INT_MAX;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMake(items, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    cin >> N >> X;
    
    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p) {
            swap(items[i].a, items[i].b);
            swap(items[i].p, items[i].q);
        }
        dp[i][0] = 0;
        for (int j = 1; j <= min(items[i].a * items[i].b, 10000); ++j) {
            dp[i][j] = min(dp[i][max(0, j - items[i].a)] + items[i].p, dp[i][max(0, j - items[i].b)] + items[i].q);
        }
    }

    cout << binarySearch(items) << endl;
    return 0;
}