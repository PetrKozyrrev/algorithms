#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using graph = vector<vector<int>>;

const int maxn = 1e5;
bool used[maxn];

void dfs(int v, const graph&g){
    used[v] = true;
    cout << v+1 << " " ;
    for(int u: g[v]){
        if(!used[u]){
            dfs(u,g);
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
	
	dfs(0,g);
	
}