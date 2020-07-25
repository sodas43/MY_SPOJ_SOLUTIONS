#include <bits/stdc++.h>
#define OJ

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

unordered_map<ll, vector<ll>> g;
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

void dfs(ll src) {
    visited[src] = true;

    for (auto neighbour : g[src]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

void bfs(ll src) {
    queue<ll> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        auto parent = q.front();
        q.pop();

        for (auto neighbour : g[parent]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main() {
    init();

    int T;
    cin >> T;

    while (T--) {

        ll peers, friends;
        cin >> peers >> friends;

        g.clear();
        visited.assign(peers, false);

        for (ll i = 0; i < friends; ++i) {
            ll src, dst;
            cin >> src >> dst;

            g[src].push_back(dst);
            g[dst].push_back(src);
        }

        ll connectedComponenets = 0;

        for (ll i = 0; i < peers; ++i) {
            if (!visited[i]) {
                bfs(i); // or dfs(i);
                ++connectedComponenets;
            }
        }

        cout << connectedComponenets << endl;

    }
    return 0;
}