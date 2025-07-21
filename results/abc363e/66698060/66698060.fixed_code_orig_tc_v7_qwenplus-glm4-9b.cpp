#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

ll h, w, y;
ll grid[1001][1001];
vb used(1001, vb(1001, false));
priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

int main() {
    // Input reading and priority queue setup
    // ...

    // Simulation loop for each year
    for (ll year = 0; year < y; year++) {
        // Initialize variables for the year
        ll remaining_area = 0;

        // Extract the lowest elevation section that is not yet marked as used
        // ...

        // Propagate the sinking process to adjacent sections
        // ...

        // Update the remaining area
        // ...

        // Output the area for this year
        remaining_area;
    }

    return 0;
}