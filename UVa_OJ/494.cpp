#include <bits/stdc++.h>

using namespace std;

bool isCharacter(char c) {
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z') return true;
    return false;
}

int main() {
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); ++i)
            if (!isCharacter(line[i]))
                line[i] = ' ';
        stringstream sin(line);
        int ans = 0;
        while (sin >> line) ++ans;
        cout << ans << endl;
    }
    return 0;
}