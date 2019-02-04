//https://www.hackerrank.com/challenges/making-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1, string s2) {
    map<char, int> s1Map, s2Map;
    unordered_set<char> charSet;
    for (int i = 0; i < max(s1.length(), s2.length()); i++)
    {
        if (i < s1.length())
        {
            s1Map[s1[i]]++;
            charSet.insert(s1[i]);
        }
        if (i < s2.length())
        {
            s2Map[s2[i]]++;
            charSet.insert(s2[i]);
        }
    }
    return accumulate(charSet.begin(), charSet.end(), 0, 
                            [&](int i, char c) { return i += abs(s1Map[c]-s2Map[c]); });

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
