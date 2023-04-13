#include <iostream>
using namespace std;

#include <vector>
#include <string_view>

class Solution {
public:
    int largestPathValue(string_view colors, const vector<vector<int>>& edges) {
        auto const node2color = [colors](int node) -> int { return colors[node] - 'a'; };

        // step 1: define reversed graph as adjacency list and count incoming edges for each node
        std::vector<int> incoming_edges(colors.size(), 0);
        std::vector<vector<int>> graph(colors.size());

        for(const auto& edge : edges) {
            ++incoming_edges[edge.front()];
            graph[edge.back()].push_back(edge.front());
        }

        // table of colors for each node
        int largest_color = 0;
        std::vector<std::vector<int>> dp(colors.size(), std::vector<int>(26, 0));

        // stack of available nodes: nodes with processed predaccessors
        std::vector<int> available_stack;
        for(int node = 0; node < incoming_edges.size(); ++node) {
            if(incoming_edges[node] == 0) {
                available_stack.push_back(node);
            }
        }

        int processed_nodes = 0;
        while(!available_stack.empty()) {
            // take another node to process
            int node = available_stack.back();
            available_stack.pop_back();

            ++processed_nodes;

            // add color to path and update largest
            largest_color = max(largest_color, ++dp[node][node2color(node)]);

            // process next nodes
            for(int next_node : graph[node]) {
                // add node to available if processing last predaccessor
                if(--incoming_edges[next_node] == 0) {
                    available_stack.push_back(next_node);
                }

                // update dp array of next node with max value
                for(int color_idx = 0; color_idx < 26; ++color_idx) {
                    dp[next_node][color_idx] = max(dp[next_node][color_idx], dp[node][color_idx]);
                }
            }
        }

        // if some node was not processed - it means graph contains cycle
        return processed_nodes == graph.size() ? largest_color : -1;
    }
};


int main() 
{
    string_view s = "zaazazwlqqwaazlalwqaaqllzzzwzqlazqaazqlaqlllzqzzalqzwalwlzwzqwzqzaqzwllzlqwlqwwqawqzlqzallwlqaqq";
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{6,8},{7,9},{8,9},{4,9},{8,10},{9,10},{5,10},{6,11},{10,11},{11,12},{12,13},{9,13},{10,13},{13,14},{10,14},{13,15},{9,15},{14,15},{15,16},{11,16},{12,17},{16,17},{17,18},{8,18},{15,18},{14,18},{10,19},{17,19},{18,19},{18,20},{17,21},{15,21},{18,21},{21,22},{20,22},{17,23},{21,23},{20,23},{22,23},{19,24},{22,24},{24,25},{23,25},{20,25},{22,26},{16,27},{18,27},{22,28},{27,29},{18,29},{20,29},{10,29},{29,30},{28,30},{28,31},{29,32},{17,32},{30,32},{27,33},{31,34},{34,35},{35,36},{27,36},{31,37},{36,37},{35,38},{38,39},{32,39},{39,40},{40,41},{33,41},{39,41},{36,41},{26,42},{39,42},{34,42},{29,42},{36,42},{41,43},{42,43},{37,43},{42,44},{40,44},{43,44},{23,44},{29,45},{35,46},{28,46},{44,46},{41,47},{44,47},{45,47},{42,48},{44,49},{39,49},{37,49},{45,49},{32,49},{46,50},{47,50},{36,50},{48,50},{49,50},{46,51},{50,51},{50,52},{37,52},{31,53},{37,54},{49,54},{52,54},{40,55},{52,55},{41,55},{54,55},{45,56},{53,56},{55,57},{54,57},{50,57},{47,57},{31,58},{56,58},{56,59},{59,60},{52,60},{50,60},{58,60},{52,61},{50,61},{58,61},{56,61},{61,62},{54,63},{34,63},{28,64},{11,64},{61,64},{52,64},{41,64},{36,65},{33,65},{62,65},{52,65},{65,66},{61,67},{65,67},{59,67},{60,67},{67,68},{66,68},{56,68},{64,68},{65,69},{64,69},{65,70},{70,71},{42,71},{52,72},{53,72},{55,72},{70,73},{65,74},{68,74},{73,74},{72,74},{15,74},{60,75},{69,75},{73,75},{70,75},{72,76},{54,76},{53,76},{74,76},{68,77},{75,77},{71,77},{76,77},{69,77},{72,78},{55,78},{76,78},{60,78},{77,78},{69,79},{74,79},{75,79},{77,79},{78,80},{52,81},{74,81},{78,81},{47,82},{79,82},{81,82},{66,82},{78,83},{81,83},{75,84},{80,84},{38,84},{77,84},{75,85},{80,85},{59,85},{78,86},{84,86},{68,86},{86,87},{85,87},{57,88},{86,88},{77,88},{62,88},{36,89},{89,90},{88,90},{85,91},{88,91},{89,91},{91,92},{82,92},{76,92},{86,92},{71,92},{91,93},{69,93},{82,93},{86,94},{39,94},{83,94},{87,94},{76,95},{94,95},{67,95}};
    cout << Solution().largestPathValue(s, edges) << endl;
    return 0;
}