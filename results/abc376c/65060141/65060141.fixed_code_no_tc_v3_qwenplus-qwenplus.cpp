#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> A(n), B(n - 1);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We try to fit the largest toys into the largest available boxes
    int toyPtr = n - 1;
    int boxPtr = n - 2;

    // We'll use a multiset to simulate the available boxes
    multiset<ll> boxes;
    ll minNeededBoxSize = -1;

    // Traverse from largest toy to smallest
    while (toyPtr >= 0) {
        if (boxPtr >= 0 && B[boxPtr] >= A[toyPtr]) {
            // Box is sufficient, use it
            boxes.insert(B[boxPtr]);
            boxPtr--;
            toyPtr--;
        } else {
            // Try to place current toy
            auto it = boxes.lower_bound(A[toyPtr]);
            if (it != boxes.end()) {
                // Found a suitable box
                boxes.erase(it);
                toyPtr--;
            } else {
                // Need an additional box, and this toy must go into it
                if (minNeededBoxSize == -1) {
                    minNeededBoxSize = A[toyPtr];
                } else {
                    // Already needed one, can't have more than one extra box
                    cout << -1 << endl;
                    return 0;
                }
                toyPtr--;
            }
        }
    }

    cout << minNeededBoxSize << endl;
    return 0;
}