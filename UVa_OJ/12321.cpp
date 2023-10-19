#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int L, G;
    while (std::cin >> L >> G) {
        if (L == 0 && G == 0)
            break;
        std::vector<std::pair<int, int>> segment;
        for (int i = 0; i < G; ++i) {
            int x, r;
            std::cin >> x >> r;
            segment.push_back({x - r, x + r});
        }
        std::sort(segment.begin(), segment.end());
        int open_station = 0;
        int covered = 0;
        bool possible = true;
        for (int i = 0; i < G; ++i) {
            if (segment[i].second > covered) {
                if (segment[i].first > covered) {
                    possible = false;
                    break;
                }
                int most_right = -1;
                int idx;
                for (int j = i; j < G && segment[j].first <= covered; ++j) {
                    if (segment[j].second > most_right) {
                        most_right = segment[j].second;
                        idx = j;
                    }
                }
                ++open_station;
                covered = most_right;
                i = idx - 1;
                if (covered >= L)
                    break;
            }
        }
        if (!possible || covered < L) {
            std::cout << "-1\n";
        } else {
            std::cout << G - open_station << '\n';
        }
    }
    return 0;
}