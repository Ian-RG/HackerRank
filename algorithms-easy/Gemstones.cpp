#include <bits/stdc++.h>

using namespace std;

int gemstones(vector<string> arr) {
    map<char, int> charMap;
    for(auto s: arr)
    {
        sort(s.begin(), s.end());
        for (auto i = 0; i < s.length(); i++)
            if (s[i] != s[i+1] || (i == s.length()-1 && s[i] != s[i-1]))
                charMap[s[i]]++;
    }

    int result = 0;
    for(auto p : charMap)
    {
        cout << p.first << " " << p.second << endl;
        if (p.second == arr.size()) result++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
