#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using graph = vector<vector<int>>;

const int maxn = 1e5;
bool used[maxn];

int dfs(int v,int p, const graph& g){
    if (used[v]) {
        cout << "Graph has a cycle, namely:" << endl;
        return v;
    }
    used[v] = true;
    for (int u : g[v]) {
        if (u != p) {
            int k = dfs(u, v,g);
            if (k != -1) {
                cout << v << endl;
                if (k == v)
                    exit(0);
                return k;
            }
        }
    }
    return -1;
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
	
	for (int v = 0; v < n; v++)
    if (!used[v])
        dfs(v,-1, g);
	
}