#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long countFreeSquares(int N, int M, vector<pair<int, int>>& pieces) {
    // We only care about the unique diagonals since each piece can capture the same set of squares.
    set<pair<int, int>> diagonals; // (constant, piece_count)
    vector<pair<int, int>> lines;

    for (auto& p : pieces) {
        int x = p.first, y = p.second;
        // Diagonals based on i + j and i - j
        diagonals.insert({x + y, 1});
        diagonals.insert({y - x, 1});
        lines.push_back({x, 1}); // x-th line (column x)
        lines.push_back({y, 1}); // y-th line (row y)
    }

    // Add all possible diagonals
    for (int i = 1; i <= N; ++i) {
        diagonals.insert({i, 1});
        diagonals.insert({-i, 1});
    }

    // Subtract the counts of captured squares
    for (auto& line : lines) {
        int x = line.first;
        for (int i = 1; i <= N; ++i) {
            if (i != x) {
                if (diagonals.find({x + i, line.second}) != diagonals.end()) {
                    diagonals[{x + i, line.second}]++;
                }
                if (diagonals.find({i + x, line.second}) != diagonals.end()) {
                    diagonals[{i + x, line.second}]++;
                }
                if (diagonals.find({-x - i, line.second}) != diagonals.end()) {
                    diagonals[{-x - i, line.second}]++;
                }
                if (diagonals.find({-i - x, line.second}) != diagonals.end()) {
                    diagonals[{-i - x, line.second}]++;
                }
            }
        }
    }

    // Calculate the number of free squares
    long long freeSquares = N * N;
    for (auto& diag : diagonals) {
        if (diag.second > 1) {
            freeSquares -= (diag.second - 1) * (diag.second - 1);
        }
    }

    return freeSquares;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << countFreeSquares(N, M, pieces) << endl;
    return 0;
}