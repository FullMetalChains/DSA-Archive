class SegTree {
private:
    int n, all = 0;
    vector<int> tree;

public:
    SegTree(int f) {
        n = f;
        tree.resize(4 * n, all);
    }

    void update(int node, int lo, int hi, int pos, int val) {
        if (lo == hi) {
            tree[node] += val;
            return;
        }

        int mid = (lo + hi) / 2;
        if (pos <= mid) update(2 * node, lo, mid, pos, val);
        else update(2 * node + 1, mid + 1, hi, pos, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int lo, int hi, int l, int r) {
        if (lo > r || hi < l) return all;
        if (lo >= l && hi <= r) return tree[node];

        int mid = (lo + hi) / 2;
        int left = query(2 * node, lo, mid, l, r);
        int right = query(2 * node + 1, mid + 1, hi, l, r);
        return merge(left, right);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int merge(int l, int r) {
        return l + r;
    }
};
 