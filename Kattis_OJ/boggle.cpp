#include <bits/stdc++.h>

using namespace std;

char b[4][4];
bool visited[4][4];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int x, int y) {return x >= 0 && x < 4 && y >= 0 && y < 4;}

bool Try(int i, int j, int id, const string& s) {
    if (id == s.size()) return true;
    visited[i][j] = true;
    for (int k = 0; k < 8; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y) && !visited[x][y] && b[x][y] == s[id]) {
            if (Try(x, y, id + 1, s)) {
                visited[x][y] = false;
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];

    unordered_map<int, int> score;
    score[3] = 1;
    score[4] = 1;
    score[5] = 2;
    score[6] = 3;
    score[7] = 5;
    score[8] = 11;

    int TC;
    cin >> TC;
    while (TC--) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> b[i][j];

        int num_found = 0, sum_score = 0;
        string longest_word = "";

        for (int k = 0; k < words.size(); ++k) {
            bool found = false;
            memset(visited, false, sizeof(visited));
            for (int i = 0; i < 4 && !found; ++i) {
                for (int j = 0; j < 4 && !found; ++j) {
                    if (words[k][0] == b[i][j]) {
                        if (Try(i, j, 1, words[k])) {
                            found = true;
                            ++num_found;
                            sum_score += score[words[k].size()];
                            if (longest_word.size() < words[k].size()) {
                                longest_word = words[k];
                            } else if (longest_word.size() == words[k].size() && longest_word > words[k]) {
                                longest_word = words[k];
                            }                           
                        }
                    }
                }
            }
        }

        cout << sum_score << " " << longest_word << " " << num_found << endl;
    }
    return 0;
}