#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> tree, size, height;
map<int, vector<int>> children;

int dfs(int i, int h)
{
    size[i] = 1;
    height[i] = h;
    for (auto j: children[i]) size[i] += dfs(j, h + 1);
    return size[i];
}

int main()
{
    int n;
    cin >> n;
    tree.resize(n + 1);
    size.resize(n + 1);
    height.resize(n + 1);

    tree[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        cin >> tree[i];
        children[tree[i]].push_back(i);
    }

    dfs(1, 1);

    int i = 1;
    for (; i < n; i++)
    {
        cout << (n - size[i] - height[i] + 1)/2. + height[i] << ' ';
    }

    cout << (n - size[i] - height[i] + 1)/2. + height[i] << endl;
}
