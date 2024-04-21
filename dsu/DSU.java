public class DSU {
    private int[] parent;
    private int[] size;
    
    public DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return ;
        if (size[x] < size[y]) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        size[x] += size[y];
        parent[y] = x;
    }
}