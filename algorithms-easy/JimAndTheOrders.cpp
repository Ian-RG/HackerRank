//https://www.hackerrank.com/challenges/jim-and-the-orders/problem
#include <bits/stdc++.h>

using namespace std;

vector<int> jimOrders(vector<vector<int>> orders) {
    auto f = [](vector<int> v1, vector<int> v2){return v1[1]+v1[2] < v2[1]+v2[2];};    
    stable_sort(orders.begin(), orders.end(), f);
    vector<int> result;
    for_each(orders.begin(), orders.end(), [&](vector<int> v){result.push_back(v[0]);});
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(3);
        orders[i][0] = i+1;
        for (int j = 1; j < 3; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
