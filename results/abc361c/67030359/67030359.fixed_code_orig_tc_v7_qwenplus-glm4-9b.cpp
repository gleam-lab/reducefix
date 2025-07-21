#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // If the array is not sorted, we need to sort it first
    if (is_sorted(A.begin(), A.end()) == false) {
        sort(A.begin(), A.end());
    }

    int l = 0, r = N - 1;
    while (K--) {
        // Calculate the difference if we remove the left-most or right-most element
        ll diffLeft = llong(A[r] - A[l]);
        ll diffRight = llong(A[r - 1] - A[l + 1]);

        // Choose the side to remove based on which reduces the range more
        if (diffLeft < diffRight) {
            r--;
        } else {
            l++;
        }
    }

    cout << A[r] - A[l] << '\n';
    return 0;
}