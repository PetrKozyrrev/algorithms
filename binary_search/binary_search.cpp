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