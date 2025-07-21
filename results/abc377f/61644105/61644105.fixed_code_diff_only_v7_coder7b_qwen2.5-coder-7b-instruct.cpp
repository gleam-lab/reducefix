#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1e9 + 10;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<int> row(n+1), col(n+1), diag1(n+1), diag2(n+1);
    
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        row[a]++;
        col[b]++;
        diag1[a+b]++;
        diag2[a-b+n]++;
    }
    
    long long total_empty_squares = n*n;
    
    for(int i = 1; i <= n; ++i) {
        total_empty_squares -= row[i] + col[i] + diag1[i] + diag2[i];
        if(i <= m) {
            total_empty_squares += 1LL * (m-i+1) * (m-i+1);
        }
    }
    
    cout << total_empty_squares << endl;
    
    return 0;
}