#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

bool can_win(vector<ll>& votes, vector<ll>& counts, int k, int target, int i) {
    int m = counts.size();
    ll sum = 0;
    for (int j = 0; j < m; j++) {
        if (j != i) {
            sum += counts[j];
        }
    }
    if (sum + k < target) {
        return false;
    }
    return true;
}

vector<ll> min_votes(vector<ll>& votes, vector<ll>& counts, int k, int m) {
    vector<ll> res(m, -1);
    for (int i = 0; i < m; i++) {
        int target = votes[i] + 1;
        ll low = 0, high = k;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (can_win(votes, counts, k, target, i)) {
                res[i] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n), counts(m);

    for (int i = 0; i < n; i++) {
        cin >> votes[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> counts[i];
    }

    vector<ll> res = min_votes(votes, counts, k, m);

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}