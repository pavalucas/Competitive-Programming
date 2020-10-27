#include <bits/stdc++.h>

using namespace std;

struct segmentTree {
  segmentTree* left, *right;
  int value, from, to;
  bool isXor;
  segmentTree(int from, int to) :
    from(from), to(to), left(nullptr), right(nullptr), value(0), isXor(false) {}
};

void makeOp(segmentTree* parent, segmentTree* child) {
  if(child != nullptr) {
    if(child->isXor) {
      parent->value ^= child->value;
    } else {
      parent->value |= child->value;
    }
    parent->isXor = !child->isXor;
  }
  return;
}

segmentTree* build(vector<int>& vec, int l, int r) {
  if(l > r) return nullptr;
  segmentTree* tree = new segmentTree(l, r);
  if(l == r) {
    tree->value = vec[l];
    return tree;
  }
  int mid = (l + r) / 2;
  tree->left = build(vec, l, mid);
  tree->right = build(vec, mid+1, r);
  tree->value = 0;
  makeOp(tree, tree->left);
  makeOp(tree, tree->right);
  return tree;
}

void update(int newVal, int index, segmentTree* tree) {
  if(tree == nullptr) return;
  if(index < tree->from) return;
  if(index > tree->to) return;
  if(tree->from == tree->to && index == tree->from) {
    tree->value = newVal;
    return;
  }
  update(newVal, index, tree->left);
  update(newVal, index, tree->right);
  tree->value = 0;
  makeOp(tree, tree->left);
  makeOp(tree, tree->right);
  return;
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int vecSize = 1 << n;
  vector<int> vec(vecSize);
  for(int i = 0; i < vecSize; i++) cin >> vec[i];
  segmentTree* segTree = build(vec, 0, vecSize-1);
  for(int i = 0; i < m; i++) {
    int p, b;
    cin >> p >> b;
    update(b, p-1, segTree);
    cout << segTree->value << '\n';
  }
}