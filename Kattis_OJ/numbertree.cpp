#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (int i = 0; i < s.length(); ++i) 
        ans = ans * 2 + (s[i] == 'R');
    cout <<  ((1 << (n + 1)) - ans) << endl;
    return 0;
}