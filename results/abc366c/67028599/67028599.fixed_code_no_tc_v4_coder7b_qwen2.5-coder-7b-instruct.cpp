#include<bits/stdc++.h>

using namespace std;

int main() {

	int q;
	cin >> q;

	unordered_set<int> h; // Changed set to unordered_set for faster insert and erase operations
	int type, x;
	while( q-- ) {
		cin >> type;
		if ( type == 1 ) {
			cin >> x;
			h.insert(x); // Inserting the element directly
		} else if ( type == 2 ) {
			cin >> x;
			h.erase(h.find(x)); // Finding and erasing the element using find method
		} else {
			cout << h.size() << endl; // Printing the size of the unordered_set
		}
	}

	return 0;
}