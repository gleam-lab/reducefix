#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll a[N], b[N-1];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    // Find the maximum toy size to determine the required box size
    ll maxToySize = *max_element(a, a + N);

    // Check if there is a box that can accommodate the largest toy
    bool canPlaceLargestToy = false;
    for (ll size : b) {
        if (size >= maxToySize) {
            canPlaceLargestToy = true;
            break;
        }
    }

    // If no existing box can accommodate the largest toy, print -1
    if (!canPlaceLargestToy) {
        cout << -1 << endl;
        return;
    }

    // If there is a box that can accommodate the largest toy, find the minimum box size needed
    ll minBoxSize = maxToySize + 1; // Start with size just larger than the largest toy size
    for (ll size : b) {
        if (size >= maxToySize) {
            minBoxSize = min(minBoxSize, size + 1);
        }
    }

    cout << minBoxSize << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}