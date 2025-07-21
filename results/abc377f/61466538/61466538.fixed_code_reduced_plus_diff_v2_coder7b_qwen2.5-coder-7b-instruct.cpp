#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 1e9;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    for(long long i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<long long> rows, cols, diagonals1, diagonals2;

    for(auto &piece : pieces) {
        rows.insert(piece.first);
        cols.insert(piece.second);
        diagonals1.insert(piece.first - piece.second);
        diagonals2.insert(piece.first + piece.second);
    }

    long long total_empty_squares = n * n;
    total_empty_squares -= rows.size() * n;
    total_empty_squares -= cols.size() * n;
    total_empty_squares += rows.size() * cols.size();

    for(auto &diagonal1 : diagonals1) {
        set<pair<long long, long long>> intersections;
        for(auto &row : rows) {
            if((row - diagonal1) % 2 == 0) {
                long long col = (row - diagonal1) / 2;
                if(col > 0 && col <= n) {
                    intersections.insert({row, col});
                }
            }
        }
        for(auto &col : cols) {
            if((col + diagonal1) % 2 == 0) {
                long long row = (col + diagonal1) / 2;
                if(row > 0 && row <= n) {
                    intersections.insert({row, col});
                }
            }
        }
        long long num_intersections = intersections.size();
        total_empty_squares -= n - abs(diagonal1);
        total_empty_squares += num_intersections;
    }

    for(auto &diagonal2 : diagonals2) {
        set<pair<long long, long long>> intersections;
        for(auto &row : rows) {
            if((row + diagonal2) % 2 == 0) {
                long long col = (row + diagonal2) / 2;
                if(col > 0 && col <= n) {
                    intersections.insert({row, col});
                }
            }
        }
        for(auto &col : cols) {
            if((col - diagonal2) % 2 == 0) {
                long long row = (col - diagonal2) / 2;
                if(row > 0 && row <= n) {
                    intersections.insert({row, col});
                }
            }
        }
        long long num_intersections = intersections.size();
        long long range = diagonal2 < n ? (diagonal2 - 1) : (2 * n - diagonal2 + 1);
        total_empty_squares -= range;
        total_empty_squares += num_intersections;
    }

    cout << total_empty_squares << endl;

    return 0;
}