#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> rows(n+1, 0), cols(n+1, 0), diags1(n+n-1, 0), diags2(n+n-1, 0);
    
    for(int i=0; i<m; ++i){
        int r, c;
        cin >> r >> c;
        rows[r]++;
        cols[c]++;
        diags1[r+c-1]++;
        diags2[n+r-c]++;
    }
    
    long long ans = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(rows[i]==0 && cols[j]==0 && diags1[i+j-1]==0 && diags2[n+i-j]==0){
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}