#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    bool has[M] = {false};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if (c == '$') has[j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < M; ++i)
        if (has[i] == false) ++ans;
    cout << ans + 1 << endl;
    return 0;
}