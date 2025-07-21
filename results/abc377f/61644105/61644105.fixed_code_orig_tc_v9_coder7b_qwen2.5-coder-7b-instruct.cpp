#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pieces(m);
    for(int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    sort(pieces.begin(), pieces.end());
    
    long long ans = n*n;
    for(int i = 0; i < m; ++i) {
        int x = pieces[i].first, y = pieces[i].second;
        
        if(i == 0 || x != pieces[i-1].first) {
            ans -= y;
        }
        if(i == 0 || y != pieces[i-1].second) {
            ans -= x;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}