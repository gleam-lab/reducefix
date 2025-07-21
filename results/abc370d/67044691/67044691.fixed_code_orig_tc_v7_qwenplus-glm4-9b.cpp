#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Define the segment tree and helper functions here

int main() {
    ll h, w, q;
    scanf("%lld %lld %lld", &h, &w, &q);
    vector<ll> row_walls(h), col_walls(w);
    vector<vector<ll>> seg_tree(4 * h, vector<ll>(w, 1)); // Initialize with 1 for all walls

    for (ll i = 0; i < q; ++i) {
        ll r, c;
        scanf("%lld %lld", &r, &c);
        r--; c--;

        if (row_walls[r] == 1 && col_walls[c] == 1) {
            seg_tree[r * 4 + c] = 0; // Bomb destroys the wall
            row_walls[r] = 0;
            col_walls[c] = 0;
        } else {
            // Find nearest walls in each direction and destroy in between
            // Update the segment tree accordingly
        }

        // Update the answer based on the number of walls remaining
    }

    // Sum up the remaining walls in total_walls
    cout << total_walls << endl;
}