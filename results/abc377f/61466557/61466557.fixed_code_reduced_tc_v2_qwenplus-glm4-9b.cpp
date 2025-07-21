#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--; // Convert to zero-indexed
        pieces[i] = {a, b};
    }

    unordered_set<ll> rows, cols, diag1, diag2, diag3, diag4;

    // Initialize the sets with all possible entries in the grid
    for (ll i = 0; i < n; ++i) {
        rows.insert(i);
        cols.insert(i);
        diag1.insert(i - (i - 1));
        diag2.insert(i - (i + 1));
        diag3.insert(i + (i - 1));
        diag4.insert(i + (i + 1));
    }

    // Remove the occupied positions and their captures from the sets
    for (const auto& p : pieces) {
        ll r = p.first;
        ll c = p.second;

        // Remove the row and column
        rows.erase(r);
        cols.erase(c);

        // Remove the diagonals
        diag1.erase(r - c);
        diag2.erase(r + c);
        diag3.erase(r + c);
        diag4.erase(-r + c);
    }

    // Calculate the number of unoccupied squares
    ll unoccupied = 0;
    for (ll i = 0; i < n; ++i) {
        unoccupied += rows.count(i);
        unoccupied += cols.count(i);
    }
    unoccupied -= rows.size() * cols.size(); // Subtract the intersections

    // Add the unoccupied diagonals
    unoccupied += diag1.size() + diag2.size() + diag3.size() + diag4.size();

    cout << unoccupied << '\n';

    return 0;
}