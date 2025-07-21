#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int Q; cin >> Q;
    map<int, int> freq;
    
    while(Q--) {
        int type; cin >> type;
        
        if(type == 1) {
            int x; cin >> x;
            freq[x]++;
        } else if(type == 2) {
            int x; cin >> x;
            if(freq.find(x) != freq.end()) {
                freq[x]--;
                if(freq[x] == 0) {
                    freq.erase(x);
                }
            }
        } else if(type == 3) {
            cout << freq.size() << '\n';
        }
    }

    return 0;
}