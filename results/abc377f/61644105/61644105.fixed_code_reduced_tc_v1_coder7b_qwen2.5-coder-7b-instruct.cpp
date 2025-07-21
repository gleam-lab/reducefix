#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<long long> rows, cols, diags1, diags2;
    
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x + y);
        diags2.insert(x - y);
    }
    
    long long valid_positions = 0;
    
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (rows.find(i) == rows.end() &&
                cols.find(j) == cols.end() &&
                diags1.find(i + j) == diags1.end() &&
                diags2.find(i - j) == diags2.end()) {
                ++valid_positions;
            }
        }
    }
    
    cout << valid_positions << endl;
    return 0;
}