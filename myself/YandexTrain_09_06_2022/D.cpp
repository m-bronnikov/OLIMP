#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using graph = std::vector<std::vector<int>>;

int main()
{
    int n, m;
    std::cin >> n >> m;

    auto const clamp_x = [n](int i) {
        i = i < n ? i : 0;
        i = i < 0 ? n - 1 : i;
        return i;
    };

    auto const clamp_y = [m](int j) {
        j = j < m ? j : 0;
        j = j < 0 ? m - 1 : j;
        return j;
    };

    auto const to_idx = [&](int i, int j){
        return clamp_x(i)*m + clamp_y(j);
    };

    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;

    int s = to_idx(sx, sy);
    int e = to_idx(ex, ey);

    // read space
    std::vector<std::vector<int>> space(n, std::vector<int>(m));
    for(auto& line : space)
        for(auto& field : line)
            std::cin >> field;

    // start and end must exist
    if(space[sx][sy] || space[ex][ey])
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    // define graph
    graph g(n*m);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int idx = to_idx(i, j);

            if(!space[clamp_x(i - 1)][j])
                g[idx].push_back(to_idx(i - 1, j));
            if(!space[clamp_x(i + 1)][j])
                g[idx].push_back(to_idx(i + 1, j));
            if(!space[i][clamp_y(j - 1)])
                g[idx].push_back(to_idx(i, j - 1));
            if(!space[i][clamp_y(j + 1)])
                g[idx].push_back(to_idx(i, j + 1));
        }
    }
    space.clear();

    // start bfs and define path
    std::vector<int> backward_connection(n*m, -1);
    std::queue<int> q;

    q.push(s);
    backward_connection[s] = s; // redundant action

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int child : g[node])
        {
            // skip if visited
            if(backward_connection[child] != -1)
                continue;

            backward_connection[child] = node;
            
            // if end found break search
            if(child == e)
            {
                std::queue<int> empty_q;
                std::swap(q, empty_q);
                break;
            }

            q.push(child);
        }
    }

    if(backward_connection[e] == -1)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> order;
    for(int i = e; i != s; i = backward_connection[i])
        order.push_back(i);
    std::reverse(begin(order), end(order));
    backward_connection.clear();

    std::string result;
    int cur = s;
    for(int k = 0; k < order.size(); cur = order[k++])
    {
        int next = order[k];

        int i = cur / m;
        int j = cur % m;

        if(to_idx(i - 1, j) == next)
        {
            result.push_back('N');
            continue;
        }
        if(to_idx(i + 1, j) == next)
        {
            result.push_back('S');
            continue;
        }
        if(to_idx(i, j - 1) == next)
        {
            result.push_back('W');
            continue;
        }
        if(to_idx(i, j + 1) == next)
        {
            result.push_back('E');
            continue;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
