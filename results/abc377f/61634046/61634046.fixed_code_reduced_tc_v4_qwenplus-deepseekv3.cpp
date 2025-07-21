#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<long long> rows, cols, diag1, diag2;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }

    long long attacked = 0;
    
    // Rows and columns
    attacked += N * rows.size() + N * cols.size();
    
    // Diagonals i+j = k
    for (long long d : diag1) {
        long long min_sum = 2;
        long long max_sum = 2 * N;
        if (d < min_sum || d > max_sum) continue;
        long long cnt = min(d - 1, 2 * N - d + 1);
        attacked += cnt;
    }
    
    // Diagonals i-j = k
    for (long long d : diag2) {
        long long min_diff = -(N - 1);
        long long max_diff = N - 1;
        if (d < min_diff || d > max_diff) continue;
        long long cnt = N - abs(d);
        attacked += cnt;
    }
    
    // Overlaps between rows and columns
    attacked -= rows.size() * cols.size();
    
    // Overlaps between rows and diag1 (i+j = k)
    for (long long a : rows) {
        for (long long d : diag1) {
            long long b = d - a;
            if (b >= 1 && b <= N) {
                if (pieces.count({a, b}) == 0) {
                    attacked--;
                }
            }
        }
    }
    
    // Overlaps between rows and diag2 (i-j = k)
    for (long long a : rows) {
        for (long long d : diag2) {
            long long b = a - d;
            if (b >= 1 && b <= N) {
                if (pieces.count({a, b}) == 0) {
                    attacked--;
                }
            }
        }
    }
    
    // Overlaps between columns and diag1 (i+j = k)
    for (long long b : cols) {
        for (long long d : diag1) {
            long long a = d - b;
            if (a >= 1 && a <= N) {
                if (pieces.count({a, b}) == 0) {
                    attacked--;
                }
            }
        }
    }
    
    // Overlaps between columns and diag2 (i-j = k)
    for (long long b : cols) {
        for (long long d : diag2) {
            long long a = d + b;
            if (a >= 1 && a <= N) {
                if (pieces.count({a, b}) == 0) {
                    attacked--;
                }
            }
        }
    }
    
    // Overlaps between diag1 and diag2
    for (long long sum : diag1) {
        for (long long diff : diag2) {
            long long a = (sum + diff) / 2;
            long long b = (sum - diff) / 2;
            if ((sum + diff) % 2 == 0 && (sum - diff) % 2 == 0) {
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    if (pieces.count({a, b}) == 0) {
                        attacked--;
                    }
                }
            }
        }
    }
    
    // Overlaps between rows, columns, and diag1
    for (long long a : rows) {
        for (long long b : cols) {
            if (pieces.count({a, b}) == 0) {
                if (diag1.count(a + b) > 0) {
                    attacked++;
                }
            }
        }
    }
    
    // Overlaps between rows, columns, and diag2
    for (long long a : rows) {
        for (long long b : cols) {
            if (pieces.count({a, b}) == 0) {
                if (diag2.count(a - b) > 0) {
                    attacked++;
                }
            }
        }
    }
    
    // Overlaps between rows, diag1, and diag2
    for (long long a : rows) {
        for (long long sum : diag1) {
            long long b = sum - a;
            if (b >= 1 && b <= N) {
                if (pieces.count({a, b}) == 0 && diag2.count(a - b) > 0) {
                    attacked++;
                }
            }
        }
    }
    
    // Overlaps between columns, diag1, and diag2
    for (long long b : cols) {
        for (long long sum : diag1) {
            long long a = sum - b;
            if (a >= 1 && a <= N) {
                if (pieces.count({a, b}) == 0 && diag2.count(a - b) > 0) {
                    attacked++;
                }
            }
        }
    }
    
    // Overlaps between rows, columns, diag1, and diag2
    for (long long a : rows) {
        for (long long b : cols) {
            if (pieces.count({a, b}) == 0) {
                if (diag1.count(a + b) > 0 && diag2.count(a - b) > 0) {
                    attacked--;
                }
            }
        }
    }

    long long total = N * N - M;
    long long safe = total - attacked;
    cout << safe << endl;

    return 0;
}