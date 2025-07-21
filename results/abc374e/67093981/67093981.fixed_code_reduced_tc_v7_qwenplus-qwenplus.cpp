#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct {
    int a, p, b, q;
} Item;

const int MAX_PRECOMPUTE = 10010; // Slightly more than a*b for each item

int main() {
    int N, X;
    cin >> N >> X;

    vector<Item> items(N);
    vector<vector<long long>> dp(N, vector<long long>(MAX_PRECOMPUTE, 0));

    for (int i = 0; i < N; ++i) {
        cin >> items[i].a >> items[i].p >> items[i].b >> items[i].q;
        
        // Ensure we're using the better option
        if (items[i].a * items[i].q < items[i].b * items[i].p) {
            swap(items[i].a, items[i].b);
            swap(items[i].p, items[i].q);
        }

        // Precompute minimum cost for 0 to a*b units
        for (int j = 1; j <= items[i].a * items[i].b; ++j) {
            dp[i][j] = min(
                dp[i][max(0, j - items[i].a)] + items[i].p,
                dp[i][max(0, j - items[i].b)] + items[i].q
            );
        }
    }

    // Binary search for maximum number of units
    int low = 0, high = 2e9;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long total_cost = 0;

        for (int i = 0; i < N; ++i) {
            int a = items[i].a, b = items[i].b, p = items[i].p, q = items[i].q;
            int period = a * b;
            int full_periods = mid / period;
            int remainder = mid % period;
            
            total_cost += dp[i][remainder] + full_periods * p * b;
            
            if (total_cost > X) break;
        }

        if (total_cost <= X) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}