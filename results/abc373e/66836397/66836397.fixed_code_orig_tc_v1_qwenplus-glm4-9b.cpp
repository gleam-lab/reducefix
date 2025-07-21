#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> prefix_sum(n);
    prefix_sum[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    vector<long long> min_votes_needed(n);
    for (int i = 0; i < n; i++) {
        long long votes_needed = prefix_sum[m - 1] - A[i] + 1;
        if (votes_needed <= k) {
            min_votes_needed[i] = votes_needed - A[i];
        } else {
            min_votes_needed[i] = -1;
        }
    }

    for (long long vote : min_votes_needed) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}