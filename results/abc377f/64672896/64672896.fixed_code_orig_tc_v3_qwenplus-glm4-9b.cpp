#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    set<pair<long long, long long>> rowCapture, colCapture, diag1Capture, diag2Capture;

    // Read the pieces and initialize the capture sets
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
        rowCapture.insert({a, 1});
        colCapture.insert({b, 1});
        diag1Capture.insert({a + b, 1});
        diag2Capture.insert({a - b, 1});
    }

    // Check if any row, column, or diagonal has all pieces
    bool fullRow = rowCapture.size() == N;
    bool fullCol = colCapture.size() == N;
    bool fullDiag1 = diag1Capture.size() == N;
    bool fullDiag2 = diag2Capture.size() == N;

    // Calculate the number of unoccupied squares
    long long unoccupied = N * N;
    if (fullRow) unoccupied -= N; // Subtract all columns in the full row
    if (fullCol) unoccupied -= N; // Subtract all rows in the full column
    if (fullDiag1) unoccupied -= N; // Subtract the diagonal
    if (fullDiag2) unoccupied -= N; // Subtract the anti-diagonal

    // Subtract squares captured by multiple pieces (intersection of capture sets)
    long long subtracted = 0;
    for (auto &p : pieces) {
        auto rowIt = rowCapture.lower_bound({p.first, 0});
        auto colIt = colCapture.lower_bound({p.second, 0});
        auto diag1It = diag1Capture.lower_bound({p.first + p.second, 0});
        auto diag2It = diag2Capture.lower_bound({p.first - p.second, 0});

        // Check if any of the capture sets are fully occupied by the piece
        if (rowIt->first == p.first && (rowIt == rowCapture.end() || rowIt->second == 1)) {
            subtracted++;
        }
        if (colIt->first == p.second && (colIt == colCapture.end() || colIt->second == 1)) {
            subtracted++;
        }
        if (diag1It->first == p.first + p.second && (diag1It == diag1Capture.end() || diag1It->second == 1)) {
            subtracted++;
        }
        if (diag2It->first == p.first - p.second && (diag2It == diag2Capture.end() || diag2It->second == 1)) {
            subtracted++;
        }
    }

    cout << unoccupied - subtracted << endl;

    return 0;
}