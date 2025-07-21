#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_set<int> uniqueElements;
    map<int, int> elementFrequency;

    for(int i = 0; i < n; ++i) {
        int type; cin >> type;
        if(type == 1) {
            int x; cin >> x;
            if(elementFrequency[x] == 0) {
                uniqueElements.insert(x);
            }
            elementFrequency[x]++;
        } else if(type == 2) {
            int x; cin >> x;
            if(elementFrequency[x] > 0) {
                elementFrequency[x]--;
                if(elementFrequency[x] == 0) {
                    uniqueElements.erase(x);
                }
            }
        } else if(type == 3) {
            cout << uniqueElements.size() << endl;
        }
    }

    return 0;
}