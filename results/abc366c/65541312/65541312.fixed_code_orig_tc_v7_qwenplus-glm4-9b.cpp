#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    scanf("%d", &q);
    set<int> st;
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int x;
            scanf("%d", &x);
            st.insert(x);
        } else if (a == 2) {
            int y;
            scanf("%d", &y);
            st.erase(y);
        } else if (a == 3) {
            printf("%d\n", st.size());
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}