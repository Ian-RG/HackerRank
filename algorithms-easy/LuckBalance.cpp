#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int luckBalance(int k, vector<vector<int>> contests) {  
    int important = accumulate(contests.begin(), contests.end(), 0, 
                    [](int &i, vector<int> v){ if (v[1] == 1) return ++i; else return i;});
                    
    sort(contests.begin(), contests.end(), 
        [](vector<int> &v1, vector<int> &v2) {return v1[0] < v2[0];});

    auto acc = [&](int i, vector<int> vec) {
        if (important-k > 0 && vec[1] == 1)
        {
            important--;
            return i-vec[0];
        }
        return i+vec[0];             
    }; 
    return accumulate(contests.begin(), contests.end(), 0,  acc);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
