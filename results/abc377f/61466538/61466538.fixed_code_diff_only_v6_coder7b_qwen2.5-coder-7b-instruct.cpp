#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

bool inBounds(long long a, long long n) {
    return 1 <= a && a <= n;
}

long long solve() {
    long long n, m; 
    cin >> n >> m;
    unordered_set<long long> rows, cols, diagonals1, diagonals2;
    for(long long i = 0; i < m; ++i) {
        long long x, y; 
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diagonals1.insert(x - y);
        diagonals2.insert(x + y);
    }
    
    long long total_empty_squares = n * n;
    long long occupied_by_rows = rows.size() * n;
    long long occupied_by_cols = cols.size() * n;
    long long occupied_by_diagonals1 = diagonals1.size() * n;
    long long occupied_by_diagonals2 = diagonals2.size() * n;
    
    long long counted_twice = (rows.size() * cols.size() +
                               diagonals1.size() * cols.size() +
                               diagonals2.size() * rows.size() -
                               rows.size() * diagonals1.size() -
                               rows.size() * diagonals2.size() -
                               cols.size() * diagonals1.size() -
                               cols.size() * diagonals2.size());
    
    long long answer = total_empty_squares - occupied_by_rows - occupied_by_cols - occupied_by_diagonals1 - occupied_by_diagonals2 + counted_twice;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long t = 1;
    while(t--) {
        cout << solve() << '\n';
    }
    return 0;
}