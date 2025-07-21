#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<string> queries(Q);
    set<int> balls;
    
    // Read all queries into the vector
    for (int i = 0; i < Q; i++) {
        cin >> queries[i];
    }
    
    // Process each query
    for (const string& query : queries) {
        istringstream iss(query);
        int type;
        iss >> type;
        
        if (type == 1) {
            int x;
            iss >> x;
            balls.insert(x);
        } else if (type == 2) {
            int x;
            iss >> x;
            balls.erase(x);
        } else if (type == 3) {
            cout << balls.size() << endl;
        }
    }
    
    return 0;
}