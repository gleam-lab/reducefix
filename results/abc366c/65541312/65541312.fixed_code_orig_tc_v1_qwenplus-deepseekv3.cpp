#include<bits/stdc++.h>
using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    unordered_map<int, int> freq;
    int unique_count = 0;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                unique_count++;
            }
            freq[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            if (freq[x] > 0) {
                freq[x]--;
                if (freq[x] == 0) {
                    unique_count--;
                }
            }
        } else if (a == 3) {
            cout << unique_count << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}