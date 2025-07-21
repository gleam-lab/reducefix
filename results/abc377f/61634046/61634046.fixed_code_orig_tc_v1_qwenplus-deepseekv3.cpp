#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    set<long long> rows, cols, up_diags, down_diags;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        up_diags.insert(a + b);
        down_diags.insert(a - b);
    }
    
    long long total = N * N;
    
    long long row_count = rows.size();
    long long col_count = cols.size();
    long long up_count = up_diags.size();
    long long down_count = down_diags.size();
    
    total -= row_count * N;
    total -= col_count * N;
    total += row_count * col_count;
    
    for (long long d : up_diags) {
        long long min_val = max(1LL, d - N);
        long long max_val = min(N, d - 1);
        if (max_val >= min_val) {
            total -= (max_val - min_val + 1);
        }
    }
    
    for (long long d : down_diags) {
        long long min_val = max(1LL, 1 - d);
        long long max_val = min(N, N - d);
        if (max_val >= min_val) {
            total -= (max_val - min_val + 1);
        }
    }
    
    for (long long r : rows) {
        for (long long d : up_diags) {
            long long c = d - r;
            if (cols.count(c)) {
                total += 1;
            }
        }
        for (long long d : down_diags) {
            long long c = r - d;
            if (cols.count(c)) {
                total += 1;
            }
        }
    }
    
    for (long long d1 : up_diags) {
        for (long long d2 : down_diags) {
            if ((d1 + d2) % 2 != 0) continue;
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if (rows.count(r) && cols.count(c)) {
                total += 1;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}