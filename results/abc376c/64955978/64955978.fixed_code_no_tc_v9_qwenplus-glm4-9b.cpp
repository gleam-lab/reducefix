#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (ll i = 0; i < N-1; ++i) {
        cin >> B[i];
    }

    // Pair toys and boxes with their indices and sort by size in descending order
    vector<pair<ll, ll>> toys(N), boxes(N-1);
    for (ll i = 0; i < N; ++i) {
        toys[i] = {A[i], i};
    }
    for (ll i = 0; i < N-1; ++i) {
        boxes[i] = {B[i], i};
    }
    sort(toys.begin(), toys.end(), greater<pair<ll, ll>>());
    sort(boxes.begin(), boxes.end(), greater<pair<ll, ll>>());

    // Try to place each toy in a box
    for (ll i = 0; i < N; ++i) {
        bool placed = false;
        for (ll j = 0; j < N-1; ++j) {
            if (toys[i].first <= boxes[j].first) {
                // If the toy fits in the box, mark it as placed and move to the next toy
                placed = true;
                break;
            }
        }
        if (!placed) {
            // If the toy cannot be placed in any of the existing boxes, it must go in the new box
            cout << A[i] << '\n';
            return 0;
        }
    }

    // If all toys are placed, we need to find the minimum box size that can hold the largest toy
    ll maxToy = 0, smallestBox = LLONG_MAX;
    for (ll i = 0; i < N; ++i) {
        if (toys[i].first > maxToy) {
            maxToy = toys[i].first;
        }
    }
    for (ll i = 0; i < N-1; ++i) {
        if (maxToy <= boxes[i].first && boxes[i].first < smallestBox) {
            smallestBox = boxes[i].first;
        }
    }
    cout << smallestBox << '\n';

    return 0;
}