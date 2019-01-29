#include <bits/stdc++.h>

using namespace std;

long strangeCounter(long t) {
    long limit = 3;  
    while (limit < t)
        limit = limit*2 +3;
    
    return limit-t+1;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
