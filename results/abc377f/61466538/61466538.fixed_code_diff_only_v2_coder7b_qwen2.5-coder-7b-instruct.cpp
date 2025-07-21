#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check if a position is within bounds
bool inBounds(ll x, ll n) {
    return 1 <= x && x <= n;
}

// Function to count the number of valid positions
ll countValidPositions(ll n, ll m, vector<pair<ll, ll>>& pieces) {
    unordered_set<ll> rows, cols, diagonals1, diagonals2;

    // Insert all occupied positions into sets
    for (const auto& piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diagonals1.insert(piece.first - piece.second);
        diagonals2.insert(piece.first + piece.second);
    }

    // Calculate total number of positions minus those occupied
    ll totalPositions = n * n;
    ll occupiedPositions = rows.size() * n + cols.size() * n - rows.size() * cols.size();

    // Subtract positions that can be captured horizontally and vertically
    ll horizontalVerticalCaptures = totalPositions - occupiedPositions;

    // Add back positions that were subtracted twice because they can be captured both horizontally and vertically
    for (const auto& piece : pieces) {
        horizontalVerticalCaptures++;
    }

    // Now calculate captures along diagonals
    for (ll d1 = -(n-1); d1 <= n-1; ++d1) {
        ll count = min(rows.size(), n - abs(d1));
        horizontalVerticalCaptures -= count;
    }

    for (ll d2 = -(n-1); d2 <= n-1; ++d2) {
        ll count = min(cols.size(), n - abs(d2));
        horizontalVerticalCaptures -= count;
    }

    // Adjust for positions that can be captured diagonally
    for (ll d1 = -(n-1); d1 <= n-1; ++d1) {
        unordered_set<ll> intersectingRows, intersectingCols;
        for (const auto& piece : pieces) {
            if (piece.first - piece.second == d1) {
                intersectingRows.insert(piece.first);
                intersectingCols.insert(piece.second);
            }
        }
        horizontalVerticalCaptures += min(intersectingRows.size(), intersectingCols.size());
    }

    for (ll d2 = -(n-1); d2 <= n-1; ++d2) {
        unordered_set<ll> intersectingRows, intersectingCols;
        for (const auto& piece : pieces) {
            if (piece.first + piece.second == d2) {
                intersectingRows.insert(piece.first);
                intersectingCols.insert(piece.second);
            }
        }
        horizontalVerticalCaptures += min(intersectingRows.size(), intersectingCols.size());
    }

    return totalPositions - horizontalVerticalCaptures;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << countValidPositions(n, m, pieces) << '\n';

    return 0;
}