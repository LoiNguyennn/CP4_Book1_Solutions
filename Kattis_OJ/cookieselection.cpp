#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
	string s;
	ost T;
    while (cin >> s){
        if (s != "#"){
            T.insert(stoll(s));
        }
        else{
            int n = T.size();
            auto it = T.find_by_order(n / 2); 
            cout << *it << endl;
        	T.erase(it);
        }
    }
    return 0; 
}