#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using graph = vector<vector<int>>;

const int maxn = 1e5;
int component[maxn];

void dfs(int v, int num, const graph&g){
    component[v] = num;
    for(int u: g[v]){
        if(!component[u]){
            dfs(u,num,g);
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
	
	int num = 0;
    for (int v = 0; v < n; v++)
        if (!component[v])
            dfs(v, ++num,g);
            
    cout << "num = " << num;
	
}