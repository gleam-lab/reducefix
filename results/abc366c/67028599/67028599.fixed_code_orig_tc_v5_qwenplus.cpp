#include<bits/stdc++.h>

using namespace std;

int main() {

	int q;
	cin >> q;

	set<int> h;
	int type, x;
	while( q-- ) {
		cin >> type;
		if ( type == 1 ) {
			cin >> x;
			h.insert(x);
		} else if ( type == 2 ) {
			cin >> x;
			auto it = h.find(x);
			if (it != h.end()) {
				h.erase(it);
			}
		} else {
			cout << h.size() << endl;
		}
	}

	return 0;
}