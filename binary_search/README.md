# Бинарный поиск (binary search)
## Задача: найти элемент в массиве

## Идея:
Пусть искомый элемент будет *key*. 
 - Сортируем массив
 - Находим его центральный элемент *v[mid]*
 - Если искомый элемент *key* > *v[mid]*, нужно искать его в отрезке правее от центра
 - Иначе в отрезке левее центра, включая его.
 - После перехода в эти меньшие отрезки, проделываем там то же самое, пока длина отрезка не станет равной единице. *То есть, пока не придём к одному элементу*
 - Если этот элемент равен искомому, то ответ найден
 - Если нет, то искомый элемент не присутствовал в массиве

## Сложность:  O(log n)

##  C++
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int key;
    cin >> key;

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        
        if (key >= v[mid]) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << (key == v[l] ? "Yes" : "No");

    return 0;
}
```

## Python
```python
n = int(input())
v = []

for i in range(n):
    a = int(input())
    v.append(a)

key = int(input())

l, r = 0, n
while r - l > 1:
    mid = (l + r) // 2
    if key >= v[mid]:
        l = mid
    else:
        r = mid

if key == v[l]:
    print("Yes")
else:
    print("No")
```
