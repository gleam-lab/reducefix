#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

// Helper function to add all possible capturing positions of a piece
void addCapturePositions(set<pair<ll, ll>>& capturePositions, pair<ll, ll> position) {
    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (auto move : moves) {
        ll x = position.first + move.first;
        ll y = position.second + move.second;
        if (x >= 0 && x < N && y >= 0 && y < N) {
            capturePositions.insert({x, y});
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--; // Convert to 0-based index
        pieces[i].second--; // Convert to 0-based index
    }

    set<pair<ll, ll>> capturePositions;
    for (auto& piece : pieces) {
        addCapturePositions(capturePositions, piece);
    }

    // The total number of empty squares minus the number of squares that are captured by existing pieces
    ll maxEmptySquares = n * n - capturePositions.size();
    cout << maxEmptySquares << endl;

    return 0;
}