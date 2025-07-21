#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    set<int> st;
    map<int, int> countMap;

    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            auto it = st.find(x);
            if (it != st.end()) {
                countMap[*it]--;
                if (countMap[*it] == 0) {
                    countMap.erase(*it);
                }
            }
            st.insert(x);
            countMap[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            auto it = st.find(x);
            if (it != st.end()) {
                countMap[*it]--;
                if (countMap[*it] == 0) {
                    countMap.erase(*it);
                }
                st.erase(it);
            }
        } else if (a == 3) {
            cout << countMap.size() << endl;
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