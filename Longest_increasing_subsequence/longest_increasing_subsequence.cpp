#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e5;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    
    vector<int> d(n);
    vector<int> pos(n);
    vector<int> prev(n-1);
    
    int length = 0;
    
    pos[0] = -1;
    d[0] = -INF;
    
    for(int i=1; i<=n; ++i)
	    d[i] = INF;
 
    for(int i=0; i<n; i++){
	    int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
	    if(d[j-1] < a[i] && a[i] < d[j]){
	       d[j] = a[i];
	       pos[j] = i;
           prev[i] = pos[j - 1];
           length = max(length, j);
	    }
		   
    }
    
    cout << "LST len = " << length << endl;
    
    vector<int> path;
    int p = pos[length];
    while(p != -1){
        path.push_back(a[p]);
        p = prev[p];
    }
    
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for(int i=0; i<(int)path.size(); ++i)
        cout << path[i] << ' ';
    cout << endl;
}
