#include <bits/stdc++.h>
//#define OJ 


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

unordered_map<int, vector<int>> g;
vector<bool> visited;


void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef OJ
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
}

void dfs(int src) {
	visited[src] = true;

	for(auto& neighbour : g[src]) {
		if(!visited[neighbour]) {
			dfs(neighbour);
		}
	}
}

int main() {
	init();

	int nodes, edges;
	cin >> nodes >> edges;

	g.clear();
	visited.assign(nodes, false);

	for(int i = 1; i <= edges; ++i) {
		int src, dest;
		cin >> src >> dest;

		g[src].push_back(dest);
		g[dest].push_back(src);
	}

	int connectedComponents = 0;

	for(int i = 1; i <= nodes; ++i) {
		if(!visited[i]) {
			dfs(i);
			++connectedComponents;
		}
	}

	//A Tree has N nodes and N - 1 edges and connectedComponents == 1
	if(connectedComponents == 1 && edges == nodes - 1) 	{ cout << "YES\n"; }
	else		 										{ cout << "NO\n"; }
	
	return 0;
}