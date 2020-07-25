#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

unordered_map<int, vector<int>> g;
//vector<int> dist;
int dist[100001];
vector<int> primes;

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool isPrime(int no) {
	for (int i = 2; i * i <= no; ++i) {
		if (no % i == 0)	return false;
	}

	return true;
}

bool isDiffByOneDigit(int a, int b) {
	int count = 0;

	while (a) {
		if (a % 10 != b % 10)	++count;
		a = a / 10;
		b = b / 10;
	}

	return (count == 1);
}

void buildGraph() {
	for (int i = 1000; i < 10000; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}

	// now create graph

	for (int i = 0; i < primes.size(); ++i) {
		for (int j = i + 1; j < primes.size(); ++j) {
			int src = primes[i];
			int dst = primes[j];

			if (isDiffByOneDigit(src, dst)) {
				g[src].push_back(dst);
				g[dst].push_back(src);
			}
		}
	}
}

void bfs(int src) {
	queue<int> q;

	q.push(src);
	dist[src] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto& neighbour : g[cur]) {
			if (dist[neighbour] == INT_MAX) {
				q.push(neighbour);
				dist[neighbour] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	init();

	int T;
	cin >> T;

	// build graph for all 4 digit prime nos which has only one digit difference
	buildGraph();

	while (T--) {
		int src, dst;
		cin >> src >> dst;

		//dist.clear();
		for (int i = 1000; i < 10000; ++i) {
			dist[i] = INT_MAX;
		}
		// dist.assign(10000 - 1000 + 1, INT_MAX);

		bfs(src);

		if (dist[dst] == INT_MAX) 	{ cout << "Impossible" << endl; }
		else						{ cout  << dist[dst] << endl; }

	}
	return 0;
}