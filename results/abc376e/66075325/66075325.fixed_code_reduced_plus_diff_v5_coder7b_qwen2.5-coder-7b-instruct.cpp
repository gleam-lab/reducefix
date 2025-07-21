#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct Compare {
    bool operator()(pii &a, pii &b) {
        return a.first * a.second > b.first * b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pii> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].second;
        }

        // Sort based on the product of A[i] and B[i]
        sort(ab.begin(), ab.end());

        int result = 0;
        for (int i = 0; i < k; ++i) {
            result += ab[i].first * ab[i].second;
        }

        cout << result << endl;
    }

    return 0;
}