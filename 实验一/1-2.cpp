#include <bits/stdc++.h>
using namespace std;

int a[1024 + 5][1024 + 5], k;

void Generate_Table()
{
    int n = pow(2, k);
    for (int i = 1; i <= n; i++)
        a[1][i] = i;
    int m = 1;
    for (int s = 1; s <= k; s++)
    {
        n /= 2;
        for (int t = 1; t <= n; t++)
        {
            for (int i = m + 1; i < 2 * m + 1; i++)
            {
                for (int j = m + 1; j < 2 * m + 1; j++)
                {
                    a[i][j + (t - 1) * m * 2] = a[i - m][j + (t - 1) * m * 2 - m];
                    a[i][j + (t - 1) * m * 2 - m] = a[i - m][j + (t - 1) * m * 2];
                }
            }
        }
        m *= 2;
    }
}

void Print_Table()
{
    int n = pow(2, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    cout << "输入k ，（比赛选手个数为2^k）:\t";
    cin >> k;

    Generate_Table();
    Print_Table();

    return 0;
}
