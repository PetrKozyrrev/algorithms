# Нахождение цикла

Циклом в графе G называется ненулевой путь, ведущий из вершины v в саму себя. 
Граф называют ацикличным, если в нем нет циклов.

## Задача:
Определить есть ли в графе цикл и если он есть вывести путь

```cpp
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
```
