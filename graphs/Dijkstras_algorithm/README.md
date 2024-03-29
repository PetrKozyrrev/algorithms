# Алгоритм Дейкстры

Алгоритм Дейкстры находит кратчайшие пути от заданной вершины s до всех остальных в графе без ребер отрицательного веса.

Заведём массив *d*, в котором для каждой вершины *v* будем хранить текущую длину $`d_{v}`$ кратчайшего пути из *s* в *v*. 
Изначально $`d_{s}=0`$, а для всех остальных вершин расстояние равно бесконечности (или любому числу, которое заведомо больше максимально возможного расстояния).
Во время работы алгоритма мы будем постепенно обновлять этот массив, находя более оптимальные пути к вершинам и уменьшая расстояние до них. Когда мы узнаем, что найденный путь до какой-то вершины *v* оптимальный, мы будем помечать эту вершину, поставив единицу ($`av=1`$) в специальном массиве *a*, изначально заполненном нулями.

Сам алгоритм состоит из n итераций, на каждой из которых выбирается вершина v с наименьшей величиной $`d_{v}`$ среди ещё не помеченных

Выбранная вершина отмечается в массиве a, после чего из из вершины v производятся релаксации: просматриваем все исходящие рёбра (v,u) и для каждой такой вершины 
u пытаемся улучшить значение $`d_{u}`$, выполнив присвоение $`d_{u}=min(d_{u},d_{v}+w)`$,где w — длина ребра (v,u).

На этом текущая итерация заканчивается, и алгоритм переходит к следующей: снова выбирается вершина с наименьшей величиной d, из неё производятся релаксации, и так далее. 
После n итераций, все вершины графа станут помеченными, и алгоритм завершает свою работу.

## Для плотных графов
Если $`m≈n^{2}`$
```cpp
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
```
## Сложность $`O(n^{2})`$

## Для разреженных графов
Если m≈n, то минимум можно искать быстрее. Вместо линейного прохода заведем структуру, в которую можно добавлять элементы и искать минимум — например std::set так умеет.

Будем поддерживать в этой структуре пары (dv,v), при релаксации удаляя старый (du,u) и добавляя новый (dv+w,u), а при нахождении оптимального v просто беря минимум (первый элемент).

```cpp
vector<int> dijkstra(int s) {
    vector<int> d(n, inf);
    d[root] = 0;
    set< pair<int, int> > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
    return d;
}
```

## Сложность O(mlogn)
