// TODO -- NOT COMPELETD

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

vector<vector<char>> floors;
vector<pii> dirtyTiles;

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

void getDistance(int src) {
	vector<bool> visisted;



}

int main() {
	init();

	while (1) {
		int C, R;
		cin >> C >> R;

		if (C == 0 && R == 0)	break;

		floors.resize(R, vector<char>(C));
		floors.clear();

		pii startPos;

		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				char ch;
				cin >> ch;
				floors[r][c] = ch;

				if (ch == 'o') { startPos = {r, c}; }
				if (ch == '*') { dirtyTiles.push_back({r, c}); }
			}
		}

		dirtyTiles.insert(dirtyTiles.begin(), startPos);

		int limit = (1 << dirtyTiles.size()) - 1;

		for (int i = 0; i < dirtyTiles.size(); ++i) {
			getDistance(i);
		}
	}

	return 0;
}