class sgTree{
    vector<int> seg;
    public:
    sgTree(int n){
        seg.resize(4*n + 1);
    }

        void buildTree(vector<int>& arr, int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        buildTree(arr, 2 * ind + 1, low, mid);
        buildTree(arr, 2 * ind + 2, mid + 1, high);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int rangeQuery(int ind, int low, int high, int l, int r) {
        if (high < l || low > r) {
            return INT_MAX;
        }
        if (low >= l && high <= r) {
            return seg[ind];
        }
        int mid = low + (high - low) / 2;
        int left = rangeQuery(2 * ind + 1, low, mid, l, r);
        int right = rangeQuery(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void pointUpdate(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid) {
            pointUpdate(2 * ind + 1, low, mid, i, val);
        } else {
            pointUpdate(2 * ind + 2, mid + 1, high, i, val);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
