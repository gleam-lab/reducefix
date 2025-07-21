#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<long long,long long>,bool> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    
    // Directions for capturing pieces
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    for(long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        
        // Check all possible capture positions
        for(int dir = 0; dir < 8; dir++) {
            long long x = a + dx[dir];
            long long y = b + dy[dir];
            
            // If the new position is within bounds and not already occupied
            if(x >= 1 && x <= n && y >= 1 && y <= n) {
                pair<long long, long long> p = make_pair(x, y);
                if(ex[p] == false) {
                    ans--;
                    ex[p] = true;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}