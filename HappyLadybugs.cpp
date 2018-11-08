#include <bits/stdc++.h>

using namespace std;

string happyLadybugs(string b) {
    map<char, int> charCount;
    bool isOrdered = true;
    
    for (int i = 0; i < b.length(); i++)
    {
        charCount[b[i]]++;
        if (i != 0 && b[i] != b[i-1] && charCount[b[i]] > 1)
            isOrdered = false;
    }
    
    if (charCount['_'] == 0 && !isOrdered)
        return "NO";    
    for (auto p : charCount)
        if (p.first != '_' && p.second == 1)
            return "NO";
    return "YES";
}        

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
