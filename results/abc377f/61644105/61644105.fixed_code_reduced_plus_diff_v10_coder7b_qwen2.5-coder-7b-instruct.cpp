#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<long long> rows(n+1), cols(n+1), diags(2*n+1), adiags(2*n+1);
    
    for(long long i = 0; i < m; ++i){
        long long a, b;
        cin >> a >> b;
        rows[a]++;
        cols[b]++;
        diags[a+b]++;
        adiags[a-b+n-1]++;
    }
    
    long long ans = n*n;
    for(long long i = 1; i <= n; ++i){
        ans -= rows[i] + cols[i] + diags[i] + adiags[i];
    }
    cout << ans/2 << endl;
    return 0;
}