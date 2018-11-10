#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getExposedArea(int column, int neighbour)
{
    return column-neighbour > 0 ? column-neighbour : 0;
}

int surfaceArea(vector<vector<int>> A) {
    int result = 0;
    
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            if (A.size() == 1)
                result += A[i][j]*2;
            else if (i == 0)
            {
                result += A[i][j];
                result += getExposedArea(A[i][j], A[i+1][j]);
            }
            else if (i == A.size()-1)
            {
                result += A[i][j];
                result += getExposedArea(A[i][j], A[i-1][j]);
            }
            else
            {
                result += getExposedArea(A[i][j], A[i-1][j]);
                result += getExposedArea(A[i][j], A[i+1][j]);
            }
            if (A[0].size() == 1)
                result += A[i][j]*2;
            else if (j == 0)
            {
                result += A[i][j];
                result += getExposedArea(A[i][j], A[i][j+1]);
            }
            else if (j == A[0].size()-1)
            {
                result += A[i][j];
                result += getExposedArea(A[i][j], A[i][j-1]);
            }
            else
            {
                result += getExposedArea(A[i][j], A[i][j-1]);
                result += getExposedArea(A[i][j], A[i][j+1]);
            }
        }
    }
    result += A.size()*A[0].size()*2;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

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
