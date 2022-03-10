#include <iostream>

using namespace std;

int dp[41] = { 0 , 1, 1 };

int main()
{
    int T, i, n;
    for (i = 3; i < 41; i++) dp[i] = dp[i - 1] + dp[i - 2];

    cin >> T;

    while (T--)
    {
        cin >> n;
        if (n == 0) cout << "1 0\n";
        else cout << dp[n - 1] << " " << dp[n] << "\n";

    }
}
