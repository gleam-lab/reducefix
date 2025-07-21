#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<long long> a(M), b(M);
    unordered_set<long long> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }
    
    long long unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    for (long long d : diag1) {
        long long min_x = max(1LL, d - N);
        long long max_x = min(N, d - 1);
        unsafe += (max_x - min_x + 1);
    }
    
    for (long long d : diag2) {
        long long min_x = max(1LL, 1 - d);
        long long max_x = min(N, N - d);
        unsafe += (max_x - min_x + 1);
    }
    
    long double intersect1 = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                intersect1 += 1;
            }
        }
    }
    
    long double intersect2 = 0;
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            long long x = (d1 + d2) / 2;
            long long y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (rows.count(x) && cols.count(y)) {
                    intersect2 += 1;
                }
            }
        }
    }
    
    unsafe -= (rows.size() * cols.size() + rows.size() * diag1.size() + rows.size() * diag2.size() +
               cols.size() * diag1.size() + cols.size() * diag2.size() + diag1.size() * diag2.size());
    
    unsafe += (rows.size() * cols.size() * diag1.size() + rows.size() * cols.size() * diag2.size() +
               rows.size() * diag1.size() * diag2.size() + cols.size() * diag1.size() * diag2.size());
    
    unsafe -= rows.size() * cols.size() * diag1.size() * diag2.size();
    
    long long total = N * N;
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}