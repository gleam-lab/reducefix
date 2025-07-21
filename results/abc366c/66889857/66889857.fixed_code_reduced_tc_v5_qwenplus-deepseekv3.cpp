#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int Q; cin >> Q;
    unordered_map<int, int> freq;
    set<int> unique_numbers;

    rep(i, Q) {
        int query_type; cin >> query_type;
        if (query_type == 1) {
            int x; cin >> x;
            freq[x]++;
            if (freq[x] == 1) {
                unique_numbers.insert(x);
            }
        } else if (query_type == 2) {
            int x; cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                unique_numbers.erase(x);
            }
        } else if (query_type == 3) {
            cout << unique_numbers.size() << '\n';
        }
    }
    return 0;
}