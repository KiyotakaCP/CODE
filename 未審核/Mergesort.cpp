#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
#define LL long long
#define int long long
#define WHY_NOT_AC ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<int> aarray;
void fmerge(int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
    vector<int> leftarray(subArrayOne), rightarray(subArrayTwo);
    for (int i = 0; i < subArrayOne; i++)
        leftarray[i] = aarray[left + i];
    for (int i = 0; i < subArrayTwo; i++)
        rightarray[i] = aarray[mid + i + 1];

    int indexone = 0,
        indextwo = 0;
    int indexMerge = left;

    while (indexone < subArrayOne && indextwo < subArrayTwo)
    {
        if (leftarray[indexone] <= rightarray[indextwo])
        {
            aarray[indexMerge] = leftarray[indexone];
            indexone++;
        }
        else
        {
            aarray[indexMerge] = rightarray[indextwo];
            indextwo++;
        }
        indexMerge++;
    }

    while (indexone < subArrayOne)
    {
        aarray[indexMerge] = leftarray[indexone];
        indexone++;
        indexMerge++;
    }
    while (indextwo < subArrayTwo)
    {
        aarray[indexMerge] = rightarray[indextwo];
        indextwo++;
        indexMerge++;
    }

}

void mergesort(int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergesort(begin, mid);
    mergesort(mid + 1, end);
    fmerge(begin, mid, end);
}

signed main()
{
    WHY_NOT_AC;
    int n;
    aarray.resize(n);
    for (int i = 0; i < n; i++)
        cin >> aarray[i];
    mergesort(0, n - 1);
}