#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    // We need to find the smallest box size that can fit all toys.
    // Start with the largest box size `b[0]` and try to fit all toys into existing boxes + this largest box.
    sort(b.begin(), b.end(), greater<ll>()); // Sort the box sizes in descending order
    ll smallestValidBoxSize = b[0]; // Start with the largest box size

    // Try to fit each toy into the existing boxes or the largest box
    for (ll toySize : a) {
        bool canFit = false;
        for (ll boxSize : b) {
            if (toySize <= boxSize) {
                // Toy can fit in this box
                canFit = true;
                break;
            }
        }
        if (!canFit) {
            // If a toy cannot fit into any existing box, then we need a larger box
            smallestValidBoxSize = max(smallestValidBoxSize, toySize);
        }
    }

    // Now we need to see if we can fit the largest toy into the smallest valid box size
    // Check if the smallest valid box size can contain all toys
    bool canFitAllToys = true;
    for (ll toySize : a) {
        if (toySize > smallestValidBoxSize) {
            // If any toy does not fit, we need a larger box
            canFitAllToys = false;
            break;
        }
    }

    if (canFitAllToys) {
        cout << smallestValidBoxSize << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}