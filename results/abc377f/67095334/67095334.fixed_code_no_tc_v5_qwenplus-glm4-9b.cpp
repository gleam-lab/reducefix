#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);

    // Read the positions of the existing pieces
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Initialize sets to store unique rows, columns, and diagonals
    set<ll> rows, cols, diag1, diag2;

    // Populate the sets with the positions of the existing pieces
    for (ll i = 0; i < m; ++i) {
        rows.insert(pieces[i].first);
        cols.insert(pieces[i].second);
        diag1.insert(pieces[i].first + pieces[i].second);
        diag2.insert(pieces[i].first - pieces[i].second);
    }

    // Calculate the number of unique diagonals
    set<ll> uniqueDiags;
    for (ll i = 1; i <= n + n; ++i) {
        uniqueDiags.insert(i);
        uniqueDiags.insert(-i);
    }
    uniqueDiags.erase(diag1.begin());  // Remove diagonals already taken by pieces
    uniqueDiags.erase(diag2.begin());
    for (ll d1 : diag1) {
        uniqueDiags.insert(-d1);
    }
    for (ll d2 : diag2) {
        uniqueDiags.insert(d2);
    }

    // Calculate the number of valid positions
    ll validPositions = n * n;
    validPositions -= rows.size();   // Subtract rows with pieces
    validPositions -= cols.size();   // Subtract columns with pieces
    validPositions -= uniqueDiags.size();  // Subtract diagonals with pieces

    cout << validPositions << endl;
    return 0;
}