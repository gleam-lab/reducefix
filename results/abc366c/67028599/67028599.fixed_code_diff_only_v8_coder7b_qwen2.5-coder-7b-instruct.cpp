#include<bits/stdc++.h>

using namespace std;

int main() {

	int q;
	cin >> q;

	unordered_set<int> h; // Use unordered_set for faster operations
	int type, x;
	while( q-- ) {
		cin >> type;
		if ( type == 1 ) {
			cin >> x;
			h.insert(x); // Insert operation is correct
		} else if ( type == 2 ) {
			cin >> x;
			h.erase(x); // Erase operation is correct
		} else {
			cout << h.size() << endl; // Size operation is correct
		}
	}

	return 0;
}