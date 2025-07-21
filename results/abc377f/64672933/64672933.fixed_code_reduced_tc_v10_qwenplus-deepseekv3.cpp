#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    unordered_set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    for (i64 d : diag1) {
        i64 start = max(1LL, d - N);
        i64 end = min(N, d - 1);
        if (start <= end) {
            unsafe += end - start + 1;
        }
    }
    
    for (i64 d : diag2) {
        i64 start = max(1LL, 1 - d);
        i64 end = min(N, N - d);
        if (start <= end) {
            unsafe += end - start + 1;
        }
    }
    
    i64 intersections = 0;
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                intersections++;
            }
        }
    }
    
    for (i64 d1 : diag1) {
        for (i64 d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 x = (d1 + d2) / 2;
                i64 y = (d1 - d2) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    intersections++;
                }
            }
        }
    }
    
    for (i64 r : rows) {
        for (i64 d2 : diag2) {
            i64 y = r - d2;
            if (y >= 1 && y <= N && diag1.count(r + y) && cols.count(y)) {
                intersections++;
            }
        }
    }
    
    for (i64 c : cols) {
        for (i64 d1 : diag1) {
            i64 x = d1 - c;
            if (x >= 1 && x <= N && diag2.count(x - c) && rows.count(x)) {
                intersections++;
            }
        }
    }
    
    unsafe -= intersections;
    i64 total = N * N - unsafe;
    cout << total << "\n";
    return 0;
}