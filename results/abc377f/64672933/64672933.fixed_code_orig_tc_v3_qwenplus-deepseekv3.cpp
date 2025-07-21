#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total = N * N;
    i64 row_count = rows.size();
    i64 col_count = cols.size();
    i64 diag1_count = diag1.size();
    i64 diag2_count = diag2.size();
    
    i64 unsafe = row_count * N + col_count * N - row_count * col_count;
    
    // Calculate for diagonals i+j = constant
    i64 diag1_unsafe = 0;
    for (auto s : diag1) {
        i64 i_plus_j = s;
        i64 min_i = max(1LL, i_plus_j - N);
        i64 max_i = min(N, i_plus_j - 1);
        if (min_i > max_i) continue;
        diag1_unsafe += max_i - min_i + 1;
    }
    
    // Calculate for anti-diagonals i-j = constant
    i64 diag2_unsafe = 0;
    for (auto s : diag2) {
        i64 i_minus_j = s;
        i64 min_i = max(1LL, 1 + i_minus_j);
        i64 max_i = min(N, N + i_minus_j);
        if (min_i > max_i) continue;
        diag2_unsafe += max_i - min_i + 1;
    }
    
    unsafe += diag1_unsafe + diag2_unsafe;
    
    // Subtract overlaps between rows/cols and diagonals
    set<pair<i64, i64>> intersections;
    for (auto [a, b] : pieces) {
        intersections.insert({a, b});
    }
    
    for (auto s1 : diag1) {
        for (auto s2 : diag2) {
            if ((s1 + s2) % 2 != 0) continue;
            i64 x = (s1 + s2) / 2;
            i64 y = s1 - x;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                intersections.insert({x, y});
            }
        }
    }
    
    for (auto r : rows) {
        for (auto c : cols) {
            intersections.insert({r, c});
        }
    }
    
    for (auto s : diag1) {
        i64 i_plus_j = s;
        for (auto r : rows) {
            i64 c = i_plus_j - r;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            i64 r = i_plus_j - c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    
    for (auto s : diag2) {
        i64 i_minus_j = s;
        for (auto r : rows) {
            i64 c = r - i_minus_j;
            if (c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (auto c : cols) {
            i64 r = i_minus_j + c;
            if (r >= 1 && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    
    unsafe -= intersections.size();
    
    i64 safe = total - unsafe;
    cout << safe << "\n";
    
    return 0;
}