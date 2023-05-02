#include <iostream>
#include <queue>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (q.empty() || t > q.back())
            q.push(t);
    }
    cout << q.size() << "\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}