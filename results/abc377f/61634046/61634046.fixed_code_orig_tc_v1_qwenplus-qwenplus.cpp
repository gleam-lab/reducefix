#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MAX_M 1003

int N, M;
set<int> rows, cols;
set<int> diag1, diag2; // x + y, x - y

// For diagonal lines: store sum and diff
map<int, vector<pii>> sum_map, diff_map;

ll count_points(set<int>& s) {
    ll total = 0;
    for (int val : s) {
        total += N;
        // Subtract overlaps from other directions
        // This is handled in the main function
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
        
        sum_map[x + y].emplace_back(x, y);
        diff_map[x - y].emplace_back(x, y);
    }

    ll total = (ll)N * N;
    
    // Subtract squares attacked by existing pieces
    // We need to use inclusion-exclusion principle

    // Count of all squares on attacked lines
    ll attacked = 0;

    // Row and column contributions
    attacked += (ll)rows.size() * N;
    attacked += (ll)cols.size() * N;

    // Diagonal contributions
    for (int s : diag1) attacked += N; // x + y = s
    for (int d : diag2) attacked += N; // x - y = d

    // Subtract overlaps between two directions
    for (int r : rows) {
        for (int c : cols) {
            int s = r + c;
            int d = r - c;
            if (diag1.count(s)) attacked--;
            if (diag2.count(d)) attacked--;
        }
    }

    // Subtract overlaps between row and diagonals
    for (int r : rows) {
        for (int s : diag1) {
            int c = s - r;
            if (1 <= c && c <= N) {
                if (cols.count(c)) attacked--;
                if (diag2.count(r - c)) attacked--;
            }
        }
    }

    // Subtract overlaps between col and diagonals
    for (int c : cols) {
        for (int s : diag1) {
            int r = s - c;
            if (1 <= r && r <= N) {
                if (rows.count(r)) attacked--;
                if (diag2.count(r - c)) attacked--;
            }
        }
    }

    // Subtract overlaps between diagonals
    for (int s : diag1) {
        for (int d : diag2) {
            int r = (s + d) / 2;
            int c = s - r;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.count(r)) attacked--;
                if (cols.count(c)) attacked--;
            }
        }
    }

    // Add back overlaps among three directions (inclusion-exclusion)
    for (int r : rows) {
        for (int c : cols) {
            int s = r + c;
            int d = r - c;
            if (diag1.count(s) && diag2.count(d)) attacked++;
        }
    }

    // Subtract overlaps among four directions (inclusion-exclusion)
    for (int r : rows) {
        for (int c : cols) {
            int s = r + c;
            int d = r - c;
            if (diag1.count(s) && diag2.count(d)) attacked--;
        }
    }

    // Now subtract occupied squares (already counted as attacked)
    attacked -= M;

    // Total available empty squares that are not attacked
    cout << total - attacked << endl;

    return 0;
}