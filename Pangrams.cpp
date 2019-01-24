#include <bits/stdc++.h>
#include <functional>

using namespace std;
using namespace std::placeholders;

string pangrams(string s) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for_each(s.begin(), s.end(), 
            [&alpha] (char c) 
            {alpha.erase(remove(alpha.begin(), alpha.end(), tolower(c)), alpha.end());}
            );

    return alpha.length() == 0 ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
