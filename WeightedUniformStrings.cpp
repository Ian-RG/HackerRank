#include <bits/stdc++.h>

using namespace std;

unordered_set<int> getWeights(string s)
{
    unordered_set<int> result;
    int current = 0;
    for (int i = 0; i < s.length(); i++)
    {
        current += (int)s[i]-96;
        result.insert(current);
        if (i == s.length()-1 || s[i] != s[i+1])
                current = 0; 
    }
    return result;
}

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> result;
    unordered_set<int> weights = getWeights(s);

    for (int i = 0; i < queries.size(); i++)
    {
        if (weights.find(queries[i]) != weights.end())
            result.push_back("Yes");
        else
            result.push_back("No");
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
