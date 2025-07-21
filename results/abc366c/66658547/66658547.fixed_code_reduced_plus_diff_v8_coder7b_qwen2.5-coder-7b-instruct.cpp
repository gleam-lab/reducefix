#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD  = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main(){
    unordered_set<int> st;
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            st.insert(x);
        } else if(op == 2){
            int x; cin >> x;
            st.erase(st.find(x));
        } else {
            cout << st.size() << "\n";
        }
    }
    return 0;
}