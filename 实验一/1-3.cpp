#include <bits/stdc++.h>
using namespace std;

int box[10000];
int step = 0, x;

void print_step(int step)
{
    cout << "step " << step << ":    ";
    for (int i = 0; i < 2 * x + 2; i++)
        cout << box[i] << " ";
    cout << endl;
}

void move(int x, int y)
{
    swap(box[x], box[y]);
    swap(box[x + 1], box[y + 1]);
    step++;
    print_step(step);
}

void slove(int l, int r)
{
    if (r - l < 6)
    {
        move(1, 4);
        return;
    }
    move((r - 2) / 2, r - 1);
    move(r - 3, (r - 2) / 2);
    slove(l, r - 2);
}

int main(int argc, char const *argv[])
{
    cin >> x;
    memset(box, 0, sizeof(box) / sizeof(int));
    for (int i = 0; i < 2 * x; i++)
        i < x ? box[i] = 2 : box[i] = 1;
    print_step(step);
    slove(0, 2 * x + 1);
    system("pause");
    return 0;
}
