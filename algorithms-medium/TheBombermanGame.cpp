#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void detonate (int i, int j, vector<vector<int>> &timer)
{
    if (i > 0)            
        timer[i-1][j] = 0;
    if (i < timer.size()-1)
        timer[i+1][j] = 0;
    if (j > 0)
        timer[i][j-1] = 0;
    if (j < timer[0].size()-1)
        timer[i][j+1] = 0;  
    timer[i][j] = 0;
}

vector<string> bomberMan(int n, vector<string> grid) {
    vector<vector<int>> timer (grid.size(), vector<int>(grid[0].size(), 0));
    vector<pair<int, int>> toDetonate;
    
    //If n is even, the grid will be filled with bombs
    if (n%2 == 0)
        return vector<string> (grid.size(), string(grid[0].size(), 'O'));
    //If n is equal to 1, do nothing
    if (n == 1)
        return grid;    
    
    //Board state at 3 is the same as board state at 7, 11, etc. Same for 5, 9, 13...
    while (n > 5)
        n -= 4;

    int count = 1;        
    while (count < n)
    {        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (count == 1 && grid[i][j] == 'O')
                    timer[i][j] = 2;
                timer[i][j] += 2;
                if (timer[i][j] > 2)
                    toDetonate.push_back({i, j});
            }

        for (int i = toDetonate.size()-1; i >= 0; i--)
        {
            detonate(toDetonate[i].first, toDetonate[i].second, timer);
            toDetonate.pop_back();
        }
        //Increment to keep count in odd cases. Even cases have already returned.
        count += 2;                
    }
    
    vector<string> result (timer.size());
    for (int i = 0; i < timer.size(); i++)
        for (int j = 0; j < timer[0].size(); j++)
            result[i].push_back(timer[i][j] > 0 ? 'O' : '.'); 
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
