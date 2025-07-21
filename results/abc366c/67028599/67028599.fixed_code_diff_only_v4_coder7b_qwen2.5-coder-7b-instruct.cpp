#include<bits/stdc++.h>

using namespace std;

int main() {

	int q;
	cin >> q;

	unordered_set<int> h; // Using unordered_set for better average case time complexity
	int type, x;
	while( q-- ) {
		cin >> type;
		if ( type == 1 ) {
			cin >> x;
			h.insert(x); // Inserting element directly
		} else if ( type == 2 ) {
			cin >> x;
			h.erase(x); // Erasing element directly
		} else {
			cout << h.size() << endl; // Printing the size of set
		}
	}

	return 0;
}