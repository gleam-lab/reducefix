#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MAXN = 400005;

int n, m, q;
vector<int> h_cnt(MAXN), v_cnt(MAXN);

int main() {
    cin >> n >> m >> q;
    
    for(int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        
        r--; c--;
        
        if(h_cnt[r] == 0 && v_cnt[c] == 0) {
            h_cnt[r]++;
            v_cnt[c]++;
        }
        else if(h_cnt[r] == 0 || v_cnt[c] == 0) {
            if(h_cnt[r] == 0) {
                h_cnt[r]++;
                v_cnt[c]--;
            }
            else {
                h_cnt[r]--;
                v_cnt[c]++;
            }
        }
    }

    int ans = n*m;
    for(int i = 0; i < n; i++) {
        ans -= h_cnt[i];
    }
    for(int i = 0; i < m; i++) {
        ans -= v_cnt[i];
    }
    cout << ans << endl;
    return 0;
}