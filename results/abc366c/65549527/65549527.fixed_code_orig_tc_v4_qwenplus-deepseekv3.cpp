#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> count;
    int unique_count = 0;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                unique_count++;
            }
            count[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            if (count[y] > 0) {
                count[y]--;
                if (count[y] == 0) {
                    unique_count--;
                }
            }
        } else if (a == 3) {
            cout << unique_count << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}