#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (long long& x : a) cin >> x;

    long long sum_a = accumulate(begin(a), end(a), 0LL);
    long long total_votes_needed = k - sum_a;

    vector<long long> diff(n);
    for (long long i = 0; i < n; ++i) {
        diff[i] = (i + 1) * m - a[i];
    }

    sort(begin(diff), end(diff));

    long long additional_votes = 0;
    long long current_sum = 0;

    for (long long i = 0; i < n; ++i) {
        current_sum += diff[i];
        if (current_sum >= total_votes_needed) {
            additional_votes = diff[i];
            break;
        }
    }

    for (long long i = 0; i < n; ++i) {
        if (additional_votes == -1) {
            cout << "-1 ";
        } else if (diff[i] == additional_votes) {
            cout << 0 << " ";
        } else {
            cout << additional_votes - diff[i] << " ";
        }
    }

    cout << endl;

    return 0;
}