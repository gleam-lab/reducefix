#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 N, M;
	cin >> N >> M;
	vector<array<int,2>> g(M);
	vector<i64> A, B, C, D;
	for (int i = 0; i < M; i ++) {
		i64 a, b;
		cin >> a >> b;
		g[i] = {a, b};
		A.push_back(a + b);
		B.push_back(a - b);
		C.push_back(a);
		D.push_back(b);
	}
	sort(begin(A), end(A));A.erase(unique(begin(A), end(A)), end(A));
	sort(begin(B), end(B));B.erase(unique(begin(B), end(B)), end(B));
	sort(begin(C), end(C));C.erase(unique(begin(C), end(C)), end(C));
	sort(begin(D), end(D));D.erase(unique(begin(D), end(D)), end(D));
	auto check = [&](int a, int b, int c, int d) -> int {
		i64 res = 0;
		for (int x = 1; x <= N; x ++) {
			for (int y = 1; y <= N; y ++) {
				int ok = 0;
				for (auto line : A) {
					for (auto line2 : B) {
						for (auto line3 : C) {
							for (auto line4 : D) {
								if (a and x + y == line) ok = 1;
								if (b and x - y == line2) ok = 1;
								if (c and x == line3) ok = 1;
								if (d and y == line4) ok = 1;
							}
						}
					}
				}
				res += ok;
			}
		}
		return res;
	};
	auto check2 = [&](int a, int b, int c, int d) -> int {
		i64 res = 0;
		for (int x = 1; x <= N; x ++) {
			for (int y = 1; y <= N; y ++) {
				int ok = 1;
				if (a) {
					int okk = 0;
					for (auto line : A) if (x + y == line) okk = 1;
					ok &= okk;
				}
				if (b) {
					int okk = 0;
					for (auto line : B) if (x - y == line) okk = 1;
					ok &= okk;
				}
				if (c) {
					int okk = 0;
					for (auto line : C) if (x == line) okk = 1;
					ok &= okk;
				}
				if (d) {
					int okk = 0;
					for (auto line : D) if (y == line) okk = 1;
					ok &= okk;
				}
				res += ok;
			}
		}
		return res;
	};

	i64 ans = 0;
	i64 res = 0;

	ans = 0;
	res = 0;
	for (auto line : B) {
		i64 L = line + 1, R = line + N;
		L = max(1LL, min(L, N));
		R = max(1LL, min(R, N));
		ans -= R - L + 1;
	}

	for (int x = 1; x <= N; x ++) {
		for (int y = 1; y <= N; y ++) {
			for (auto line : B) {
				if (x - y == line) {
					res ++;
				}
			}
		}
	}
	// printf("check1: %d %d\n", abs(ans), check(0, 1, 0, 0));

	res = 0;
	for (auto line : A) {
		i64 L = line - 1, R = line - N;
		if (R >= 0 and R <= N) {
			ans -= N - R + 1;
		} else {
			ans -= L;
		}
		for (auto line2 : B) {
			// x + y = line, x - y = line2
			// y = (line - line2) / 2
			if ((line - line2) % 2 == 0) {
				i64 y = (line - line2) / 2;
				i64 x = line - y;
				if (x >= 1 and y >= 1 and x <= N and y <= N) {
					ans += 1;
				}	
			}
		}
	}

	// printf("check2: %d %d\n", abs(ans), check(1, 1, 0, 0));




	map<int,int> checkx, checky;
	for (auto line : A) {
		for (auto line1 : B) {
			if ((line + line1) % 2 == 0) {
				int x = (line + line1) / 2;
				int y = line - x;
				if (x >= 1 and x <= N and y >= 1 and y <= N) {
					checkx[x] += 1;
				}	
			}
			if ((line - line1) % 2 == 0) {
				int y = (line - line1) / 2;
				int x = line - y;
				if (x >= 1 and x <= N and y >= 1 and y <= N) {
					checky[y] += 1;
				}
			}
			
		}
	}

	for (auto line : C) {
		ans -= N;
		for (auto lineA : A) {
			// x = line, x + y = lineA
			// y = lineA - line
			i64 y = lineA - line;
			if (y >= 1 and y <= N) {
				ans += 1;
			}
		}
		for (auto lineB : B) {
			// x - y = lineB
			i64 y = line - lineB;
			if (y >= 1 and y <= N) {
				ans += 1;
			}
		}
		// x = line, x + y = A, x-y = B
		// -> A == B
		if (checkx.count(line)) {
			ans -= checkx[line];
		}
	}
	// printf("check3: %d %d\n", abs(ans), check(1,1,1,0));

	for (auto line : D) {
		ans -= N;
		for (auto lineA : A) {
			// y = line, x + y = lineA
			// x = lineA - line
			i64 x = lineA - line;
			if (x >= 1 and x <= N) {
				ans += 1;
			}
		}
		for (auto lineB : B) {
			// x - y = lineB, y = line
			i64 x = line + lineB;
			if (x >= 1 and x <= N) {
				// cout << line << ' ' << lineB << ' ' << x << "\n";
				ans += 1;
			}	
		}
		// // 横竖
		for (auto line : C) {
			ans += 1;
		}

		// // 3 
		for (auto line1 : C) {
			int v = line + line1;
			int p = lower_bound(begin(A), end(A), v) - begin(A);
			if (p < size(A) and A[p] == v) {
				ans -= 1;
			}
		}


		for (auto line1 : C) {
			int v = line1 - line;
			int p = lower_bound(begin(B), end(B), v) - begin(B);
			if (p < size(B) and B[p] == v) {
				ans -= 1;
			}
		}

		if (checky.count(line)) {
			ans -= checky[line];
		}
	}
	// printf("check4: %d %d\n", abs(ans), check(1,1,1,1) + check2(1,1,1,1) - check2(1,1,0,1));

	set<array<i64,2>> SS;
	for (auto x : A) {
		for (auto y : B) {
			SS.insert({x, y});
		}
	}

	i64 sss = 0;
	for (auto x : C) {
		for (auto y : D) {
			if (SS.count({x + y, x - y})) {
				ans += 1;
			}
		}
	}


	cout << N * N + ans << "\n";


	return 0;
}