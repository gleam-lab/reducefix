#include <bits/stdc++.h>
using ll = long long;

#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define rep(i, n) for(int i = 0; i < (n); i++)

using namespace std;

// --------------------------------------------------------
int main(){
    int q;cin >> q;
    vector<int>bac(1e6+7,0);
    set<int>st;
    rep(i,q){
        int op;cin >> op;
        if(op == 1){
            int x;cin>>x;
            st.insert(x);
            bac[x]++;
        }else if(op == 2){
            int x;cin >> x;
            bac[x]--;
            if(!bac[x])st.erase(x);
        }else{
            cout << st.size() << endl;
        }
    }
}
