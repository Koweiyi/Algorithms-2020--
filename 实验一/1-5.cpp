#include <bits/stdc++.h>
using namespace std;

char Graps[4094 + 10][4094 + 10];

void draw(int x, int y, int size)
{
    if (size == 1)
    {
        Graps[x][y + 1] = Graps[x + 1][y] = '/';
        Graps[x][y + 2] = Graps[x + 1][y + 3] = '\\';
        Graps[x + 1][y + 1] = Graps[x + 1][y + 2] = '_';
        return;
    }
    int high = pow(2, size - 1);
    draw(x, y + high, size - 1);
    draw(x + high, y, size - 1);
    draw(x + high, y + 2 * high, size - 1);

}

int main()
{
    int size;
    memset(Graps, ' ', sizeof(Graps) / sizeof(char));
    cin >> size;
    int high = pow(2, size);
    draw(0, 0, size);

    for (int i = 0; i < high; i++)
        Graps[i][2*high]='\0';
    
    for (int i = 0; i < high; i++)
        cout << Graps[i] << endl;
}
