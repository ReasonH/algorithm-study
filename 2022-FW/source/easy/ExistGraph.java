package easy;

import java.util.*;

class ExistGraph {
    Map<Integer, List<Integer>> maps = new HashMap<>();
    boolean[] visited;
    boolean answer;

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        for (int i = 0; i < n; i++) {
            maps.put(i, new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) {
            maps.get(edges[i][0]).add(edges[i][1]);
            maps.get(edges[i][1]).add(edges[i][0]);
        }
        visited = new boolean[n];
        answer = false;
        dfs(source, destination);
        return answer;
    }

    public void dfs(int source, int destination) {
        if (answer || source == destination) {
            answer = true;
            return;
        }
        visited[source] = true;
        List<Integer> targets = maps.get(source);
        for (int i = 0; i < targets.size(); i++) {
            if (!answer && !visited[targets.get(i)]) {
                dfs(targets.get(i), destination);
            }
        }
    }

}
