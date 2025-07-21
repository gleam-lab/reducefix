#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    unordered_map<int, int> freq;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            st.insert(x);
            freq[x]++;
        }
        else if (a == 2) {
            int y;
            cin >> y;
            if (freq[y] > 0) {
                freq[y]--;
                if (freq[y] == 0) {
                    st.erase(y);
                }
            }
        }
        else if (a == 3) {
            cout << st.size() << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}