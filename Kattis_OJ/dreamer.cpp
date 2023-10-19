#include <bits/stdc++.h>

using namespace std;

bool leapyear(int y) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        return true;
    return false;
}

bool valid(string s) {
    int day = 0;
    for (int i = 0; i < 2; ++i)
        day = day * 10 + s[i] - '0';
    int month = 0;
    for (int i = 2; i < 4; ++i)
        month = month * 10 + s[i] - '0';
    int year = 0;
    for (int i = 4; i < 8; ++i)
        year = year * 10 + s[i] - '0';

    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 2000)
        return false;
    
    if (month == 2) {
        if (leapyear(year)) return day <= 29;
        return day <= 28;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return day <= 31;
    else 
        return day <= 30;
}

bool isLessThan(string a, string b) {
    int day1 = 0;
    for (int i = 0; i < 2; ++i)
        day1 = day1 * 10 + a[i] - '0';
    int month1 = 0;
    for (int i = 2; i < 4; ++i)
        month1 = month1 * 10 + a[i] - '0';
    int year1 = 0;
    for (int i = 4; i < 8; ++i)
        year1 = year1 * 10 + a[i] - '0';

    int day2 = 0;
    for (int i = 0; i < 2; ++i)
        day2 = day2 * 10 + b[i] - '0';
    int month2 = 0;
    for (int i = 2; i < 4; ++i)
        month2 = month2 * 10 + b[i] - '0';
    int year2 = 0;
    for (int i = 4; i < 8; ++i)
        year2 = year2 * 10 + b[i] - '0';

    if (year1 != year2)
        return year1 < year2;
    else if (month1 != month2)
        return month1 < month2;
    else 
        return day1 < day2;
    return false;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        string date;
        string tmp;
        for (int i = 0; i < 3; ++i) {
            cin >> tmp;
            date += tmp;
        }
        
        int cnt = 0;
        string minDate = "99999999";
        sort(date.begin(), date.end());
        do {
            if (valid(date)) {
                ++cnt;
                if (isLessThan(date, minDate))
                    minDate = date;
            }
        } while (next_permutation(date.begin(), date.end()));
        if (cnt) {
            cout << cnt << " " << minDate[0] << minDate[1] << " " << minDate[2] << minDate[3] << " " <<
            minDate[4] << minDate[5] << minDate[6] << minDate[7] << endl;
        } else {
            cout << cnt << endl;
        }
    }
    return 0;
}