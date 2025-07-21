#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> H(N + 9);
	for (int i = 0; i < N; i++) cin >> H[i];
	long long T = 0;
	int index = 0;
	while (true) {
		bool found = false;
		for (; index < N; index++) {
			if (H[index] > 0) {
				found = true;
				break;
			}
		}
		if (!found) break;
		index++;
		T++;
		if (T % 3 == 0) H[index - 1] -= 3;
		else H[index - 1]--;
	}
	cout << T << endl;
	return 0;
}