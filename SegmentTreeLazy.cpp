class SegmentTree {
public:
    vector<ll> seg, lazy;
    int n;
 
    SegmentTree(int n) {
        seg.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
        this->n = n;
    }
 
    void propagate(int l, int r, int pos) {
        if (lazy[pos] != 0) {
            seg[pos] += lazy[pos] * (r - l + 1);
            if (l != r) {
                lazy[pos * 2] += lazy[pos];
                lazy[pos * 2 + 1] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }
 
    void update_(int l, int r, int tl, int tr, int pos, ll value) {
        propagate(l, r, pos);
        if (tr < l || tl > r) return;
        if (tl <= l && r <= tr) {
            lazy[pos] += value;
            propagate(l, r, pos);
            return;
        }
        ll mid = (l + r) / 2;
        update_(l, mid, tl, tr, pos * 2, value);
        update_(mid + 1, r, tl, tr, pos * 2 + 1, value);
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }
 
    ll calc_(int l, int r, int tl, int tr, int pos) {
        propagate(l, r, pos);
        if (tr < l || tl > r) return 0;
        if (tl <= l && r <= tr) return seg[pos];
        int mid = (l + r) / 2;
        return calc_(l, mid, tl, tr, pos * 2) + calc_(mid + 1, r, tl, tr, pos * 2 + 1);
    }
 
    void upd(int s, int e, ll value) {
        update_(0, n - 1, s, e, 1, value);
    }
 
    ll calc(int s, int e) {
        return calc_(0, n - 1, s, e, 1);
    }
};
