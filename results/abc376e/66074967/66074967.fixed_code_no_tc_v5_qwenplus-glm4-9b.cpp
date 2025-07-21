#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200010;
vector<pair<int, int>> A, B;

pair<long long, long long> solve(int n, int k, vector<int> &a, vector<int> &b) {
    long long min_value = LLONG_MAX;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += b[i];
        if (i >= k - 1) { // At least one more value must be considered if i >= k-1
            if (i >= k) { // If i >= k, we can't include a[i] in the max part
                sum -= b[i - k];
            }
            min_value = min(min_value, (sum + b[i]) * a[i]);
        }
    }
    return {min_value, 0}; // The second value is a dummy to match the function signature of the other solve function
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        A.resize(n);
        B.resize(n);
        for (int &a : A) cin >> a.first;
        for (int &b : B) cin >> b.first;
        sort(A.begin(), A.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first; // Sort descending
        });
        sort(B.begin(), B.end());
        auto result = solve(n, k, A, B);
        cout << result.first << endl;
    }
    return 0;
}