#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; ++i) {
        string line;
        getline(cin, line); // Read the entire line
        istringstream iss(line);
        int a;
        string temp;
        if (!(iss >> a >> temp)) {
            // Handle multi-query line
            while (iss >> a >> temp) {
                if (a == 1) {
                    st.insert(stoi(temp));
                } else if (a == 2) {
                    st.erase(stoi(temp));
                } else if (a == 3) {
                    cout << st.size() << endl;
                }
            }
        } else {
            // Handle single-query line
            if (a == 1) {
                st.insert(istringstream(temp) >> noskipws);
            } else if (a == 2) {
                st.erase(istringstream(temp) >> noskipws);
            } else if (a == 3) {
                cout << st.size() << endl;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}