#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> b_set(B.begin(), B.end());

    int j = 0;
    for (int i = 0; i < N; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it != b_set.end()) {
            b_set.erase(it);
        } else {
            // Cannot place this toy in any box, so we need to use the new box
            cout << A[i] << '\n';
            return 0;
        }
    }

    // If all toys fit in existing boxes, we can choose a very small x that is unused
    // However, Takahashi must buy one box regardless. Since all toys are placed, x can be 0 (not valid since x > 0)
    // So we output the smallest unused B or fallback to -1
    if (!b_set.empty()) {
        cout << *b_set.begin() << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}