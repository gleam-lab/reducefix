#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    int a, p, b, q;
};

long long dp[100][10000];

bool canPack(const vector<Item>& items, int X, int target) {
    int N = items.size();
    for (int i = 0; i <= target; ++i) dp[0][i] = INT_MAX;
    dp[0][0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= items[i - 1].a * items[i - 1].b) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - items[i - 1].a * items[i - 1].b] + items[i - 1].p * items[i - 1].b);
            }
            if (j >= items[i - 1].a * items[i - 1].q) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - items[i - 1].a * items[i - 1].q] + items[i - 1].p * items[i - 1].q);
            }
        }
    }
    
    return dp[N][target] <= X;
}

int binarySearch(vector<Item>& items, int X, int maxTarget) {
    int left = 0, right = maxTarget;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canPack(items, X, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        if (items[i].a * items[i].q < items[i].b * items[i].p) {
            swap(items[i].a, items[i].b);
            swap(items[i].p, items[i].q);
        }
    }
    
    int maxTarget = 10000;
    cout << binarySearch(items, X, maxTarget) << endl;
    
    return 0;
}