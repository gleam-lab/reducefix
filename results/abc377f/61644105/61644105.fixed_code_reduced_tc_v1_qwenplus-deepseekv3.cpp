#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, sums, diffs;
    vector<pair<long long, long long>> pieces(M);
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        sums.insert(a + b);
        diffs.insert(a - b);
    }
    
    long long total = N * N;
    
    long long row_attack = rows.size() * N;
    long long col_attack = cols.size() * N;
    
    long long sum_attack = 0;
    for (long long s : sums) {
        long long min_xplusy = max(1LL + 1, s - N);
        long long max_xplusy = min(N + N, s);
        long long count = max_xplusy - min_xplusy + 1;
        sum_attack += count;
    }
    
    long long diff_attack = 0;
    for (long long d : diffs) {
        long long min_xminusy = max(1LL - N, d);
        long long max_xminusy = min(N - 1LL, d);
        long long count = max_xminusy - min_xminusy + 1;
        diff_attack += count;
    }
    
    long long row_col = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (sums.count(r + c) || diffs.count(r - c)) {
                continue;
            }
            row_col++;
        }
    }
    
    long long row_sum = 0;
    for (long long r : rows) {
        for (long long s : sums) {
            long long c = s - r;
            if (c >= 1 && c <= N) {
                row_sum++;
            }
        }
    }
    
    long long row_diff = 0;
    for (long long r : rows) {
        for (long long d : diffs) {
            long long c = r - d;
            if (c >= 1 && c <= N) {
                row_diff++;
            }
        }
    }
    
    long long col_sum = 0;
    for (long long c : cols) {
        for (long long s : sums) {
            long long r = s - c;
            if (r >= 1 && r <= N) {
                col_sum++;
            }
        }
    }
    
    long long col_diff = 0;
    for (long long c : cols) {
        for (long long d : diffs) {
            long long r = d + c;
            if (r >= 1 && r <= N) {
                col_diff++;
            }
        }
    }
    
    long long sum_diff = 0;
    for (long long s : sums) {
        for (long long d : diffs) {
            if ((s - d) % 2 != 0) continue;
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                sum_diff++;
            }
        }
    }
    
    long long row_col_sum = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (sums.count(r + c)) {
                row_col_sum++;
            }
        }
    }
    
    long long row_col_diff = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (diffs.count(r - c)) {
                row_col_diff++;
            }
        }
    }
    
    long long row_sum_diff = 0;
    for (long long r : rows) {
        for (long long s : sums) {
            long long c = s - r;
            if (c >= 1 && c <= N && diffs.count(r - c)) {
                row_sum_diff++;
            }
        }
    }
    
    long long col_sum_diff = 0;
    for (long long c : cols) {
        for (long long s : sums) {
            long long r = s - c;
            if (r >= 1 && r <= N && diffs.count(r - c)) {
                col_sum_diff++;
            }
        }
    }
    
    long long row_col_sum_diff = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (sums.count(r + c) && diffs.count(r - c)) {
                row_col_sum_diff++;
            }
        }
    }
    
    long long attacked = row_attack + col_attack + sum_attack + diff_attack
                       - row_col - row_sum - row_diff - col_sum - col_diff - sum_diff
                       + row_col_sum + row_col_diff + row_sum_diff + col_sum_diff
                       - row_col_sum_diff;
    
    long long safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}