#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using ll = int64_t;
const ll INF = 1e18;

struct wedge {
	int u, v;
	ll w;
};

using wgraph = vector<vector<wedge>>;

void dijkstra_slow(wgraph& g, const int u, vector<ll>& d, vector<int>& prev) {
	int n = g.size();
	d[u] = 0;
	prev[u] = u;
	vector<char> visited(n, false);
	for (int i = 0; i < n; i++) {
		int min_id = -1;
		ll val = INF;
		for (int j = 0; j < n; j++) {
			if (!visited[j] and d[j] < val) {
				min_id = j;
				val = d[j];
			}
		}
		int u = min_id;
		visited[u] = true;
		for (wedge el : g[u]) {
			int v = el.v;
			ll w = el.w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				prev[v] = u;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, start,finish;
	cin >> n >> m >> start>>finish;
	--start;
	--finish;
	wgraph g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		ll w;
		cin >> u >> v>>w;
		--u;
		--v;
		g[u].push_back({u,v,w});
	}
	vector<ll> d(n, INF);
	vector<int> prev(n, -1);
	dijkstra_slow(g, start, d, prev);

	vector<int> path;
	int u = finish;
	while (prev[u] != u) {
		path.push_back(u);
		u = prev[u];
	}
	path.push_back(u);
	reverse(path.begin(), path.end());

	for (int elem : path) {
		cout << elem+1 << " ";
	}

	/*
	for (int elem : d) {
		cout << elem << " ";
	}*/
}