#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD  = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main(){
    set<int> st;
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int t; cin >> t;
            st.insert(t); // Corrected: Inserting 't' instead of 'x'
        } else if(x == 2){
            int t; cin >> t;
            st.erase(t); // Corrected: Erasing 't' instead of 'x'
        } else if(x == 3){
            cout << st.size() << "\n"; // No change needed here
        }
    }
    return 0;
}