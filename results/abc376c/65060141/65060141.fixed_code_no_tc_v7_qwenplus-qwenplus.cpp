#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n), B(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We will use binary search to find the minimum x
    ll left = 1, right = 1e18, answer = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;

        // Merge B and mid into a new array of size n
        vector<ll> boxes = B;
        boxes.push_back(mid);
        sort(boxes.begin(), boxes.end());

        bool canFit = true;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] < A[i]) {
                canFit = false;
                break;
            }
        }

        if (canFit) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}