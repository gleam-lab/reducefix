#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    set<ll> row capturingRows, col capturingCols, diag1, diag2;
    set<pair<ll, ll>> capturingPositions;

    for (ll i = 1; i <= m; ++i) {
        ll a, b;
        cin >> a >> b;
        capturingRows.insert(a);
        capturingCols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        capturingPositions.insert({a, b});
    }

    // Calculate the number of empty rows and columns
    ll availableRows = n - capturingRows.size();
    ll availableCols = n - capturingCols.size();

    // Calculate the number of empty squares in diagonals
    ll availableDiag1 = n - diag1.size();
    ll availableDiag2 = n - diag2.size();

    // Calculate the total number of squares, then subtract the number of squares that are captured
    ll totalSquares = n * n;
    ll capturedSquares = capturingRows.size() * n + capturingCols.size() * n;

    for (auto pos : capturingPositions) {
        capturedSquares += pos.first - pos.second;
        capturedSquares += pos.first + pos.second;
        capturedSquares -= 2; // Subtract twice because we have counted (a-b) and (a+b) twice
    }

    // Calculate the number of squares that are not captured by any existing piece
    ll notCapturedSquares = totalSquares - capturedSquares;

    // Output the result
    cout << notCapturedSquares << endl;

    return 0;
}