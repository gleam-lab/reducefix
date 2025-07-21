#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int N = 2e5 + 10;

vector<i64> A, sorted_A;

bool can_win(i64 base, i64 X, i64 K_remaining) {
    // Candidate's total votes after adding X
    i64 total = base + X;

    // Find how many candidates have votes > total
    int M = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();
    int need = M - 1; // We need to ensure less than M candidates are ahead

    if (need <= 0) return true;

    // Need to take top (need) candidates and see if we can block them from all getting more
    // Take the smallest of those top candidates that are above us
    int n = A.size();
    vector<i64> others;
    for (int i = n - 1; i >= 0 && (int)others.size() < need; --i) {
        if (sorted_A[i] > total) {
            others.push_back(sorted_A[i]);
        }
    }

    // If there aren't enough candidates with more votes, it's automatically possible
    if ((int)others.size() < need) return true;

    // Calculate how much needed to reduce the gap with the weakest among those
    i64 required = 0;
    for (auto v : others) {
        required += (v - total + 1);
    }

    return required > K_remaining - X;
}

void solve() {
    int n, m;
    i64 K;
    cin >> n >> m >> K;

    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    i64 total_used = accumulate(A.begin(), A.end(), 0LL);
    i64 remaining = K - total_used;

    vector<i64> result;
    for (int i = 0; i < n; ++i) {
        i64 lo = 0, hi = remaining, ans = -1;
        i64 base = A[i];

        while (lo <= hi) {
            i64 mid = (lo + hi) / 2;
            if (can_win(base, mid, remaining)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result.push_back(ans);
    }

    for (auto x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}