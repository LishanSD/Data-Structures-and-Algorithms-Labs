#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    int day;

    if (year < 1918) {
        if (year % 4 == 0) {
            day = 12;
        }
        else {
            day = 13;
        }
    }
    else if (year == 1918) {
        day = 26;
    }
    else if (1918 < year) {
        if (year % 400 == 0) {
            day = 12;
        }
        else if (year % 4 == 0 && year % 100 != 0) {
            day = 12;
        }
        else {
            day = 13;
        }
    }

    return to_string(day) + ".09." + to_string(year);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
