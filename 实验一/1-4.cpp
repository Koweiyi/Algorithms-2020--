#include <iostream>
using namespace std;

int A[50000 + 5], B, N, M;

bool bin_search(int target)
{
    int l = 0, r = N - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (A[mid] == target)
            return true;
        else if (A[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> B;
        if (bin_search(10000 - B))
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
