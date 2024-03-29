#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using graph = vector<vector<int>>;

void bfs(int start, const graph& g, vector<int>& d, vector<int>& p) {
	queue<int> q;
	
	d[start] = 0;
	p[start] = start;
	
	q.push(start);
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				p[v] = u;
				q.push(v);
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	graph g(n);
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
	}
	
	int start = 0,finish=n-1;
	
	vector<int> d(n, -1);
	
	vector<int> p(n, -1);
	
	bfs(start, g, d, p);
	
	vector<int> path;
	
	int u = finish;
	
	// восстановление пути
	while (p[u] != u) {
		path.push_back(u);
		u = p[u];
	}
	path.push_back(u);
	reverse(path.begin(), path.end());
	
	cout << path.size() << endl;
	
	for (int elem : path) {
		cout << elem + 1 << " ";
	}
	cout << endl;
	
}