#include<iostream>
#include<map>
using namespace std;
using ll = long long;

int main() {
    map<int, int> m;
    int q;
    cin >> q;
    
    int distinct = 0;
    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type;
        
        if (type == 1) {
            cin >> x;
            m[x]++;
            if (m[x] == 1) distinct++;
        } else if (type == 2) {
            cin >> x;
            if (m.find(x) != m.end()) {
                m[x]--;
                if (m[x] == 0) {
                    distinct--;
                    m.erase(x);
                }
            }
        } else {
            cout << distinct << endl;
        }
    }
    return 0;
}