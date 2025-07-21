#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<ll> B(N - 1);
    for (ll i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    // The strategy is to find the maximum size of toy that can fit into the smallest box.
    // We will do this by comparing the toys from largest to smallest with the boxes from largest to smallest.
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    ll minBoxSize = -1; // This will store the minimum box size needed.

    // If the largest toy doesn't fit into any existing box, we need to find the smallest box that can fit this toy
    for (ll i = 0; i < N; i++) {
        ll toySize = A[i];
        bool canFit = false; // Flag to check if the toy can fit in any of the boxes so far.

        // Compare the toy size with each box.
        for (ll j = 0; j < N - 1; j++) {
            if (toySize <= B[j]) {
                canFit = true; // Toy can fit into box B[j]
                break;
            }
        }

        // If the toy cannot fit into any existing box, the smallest box needed is the size of the toy itself.
        if (!canFit) {
            minBoxSize = toySize;
            break; // No need to check further, we found the minimum box size required.
        }
    }

    // If no box is small enough, return -1.
    if (minBoxSize == -1) {
        cout << -1 << endl;
    } else {
        // Otherwise, print the minimum box size.
        cout << minBoxSize << endl;
    }

    return 0;
}