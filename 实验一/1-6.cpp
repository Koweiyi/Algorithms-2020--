#include <bits/stdc++.h>
using namespace std;

void solve(int start_x, int start_y, int target_x, int target_y, int size)
{
    if (size == 1)
        return;
    int div_size = size / 2;
    if (target_x < start_x + div_size && target_y < start_y + div_size)
    {
        cout << start_x + div_size << "\t" << start_y + div_size << "\t"
             << "3" << endl;
        solve(start_x, start_y, target_x, target_y, div_size);
    }
    else
        solve(start_x, start_y, start_x + div_size - 1, start_y + div_size - 1, div_size);

    if (target_x < start_x + div_size && target_y >= start_y + div_size)
    {
        cout << start_x + div_size << "\t" << start_y + div_size - 1 << "\t"
             << "1" << endl;
        solve(start_x, start_y + div_size, target_x, target_y, div_size);
    }
    else
        solve(start_x, start_y + div_size, start_x + div_size - 1, start_y + div_size, div_size);

    if (target_x >= start_x + div_size && target_y < start_y + div_size)
    {
        cout << start_x + div_size - 1 << "\t" << start_y + div_size << "\t"
             << "2" << endl;
        solve(start_x + div_size, start_y, target_x, target_y, div_size);
    }
    else
        solve(start_x + div_size, start_y, start_x + div_size, start_y + div_size - 1, div_size);

    if (target_x >= start_x + div_size && target_y >= start_y + div_size)
    {
        cout << start_x + div_size - 1 << "\t" << start_y + div_size - 1 << "\t"
             << "4" << endl;
        solve(start_x + div_size, start_y + div_size, target_x, target_y, div_size);
    }
    else
        solve(start_x + div_size, start_y + div_size, start_x + div_size, start_y + div_size, div_size);
}

int main(int argc, char const *argv[])
{
    int k, x, y;
    cin >> k >> x >> y;
    solve(0, 0, x, y, pow(2, k));
    return 0;
}