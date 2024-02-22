#pragma once

namespace CYT_DSA {
template <class T>
void RBTree<T>::solveDoubleRed(BinNodePosi<T> x) {
  if (IsRoot(x)) {
    this->_root->_color = RBcolor::black;
    this->_root->height++;
    return;
  }

  RBPtr<T> p = x->parent;
  if (IsBlack(p)) return;
  // double red,  g exists
  RBPtr<T> g = p->parent;
  RBPtr<T> u = Sibling(p);
  // now look at u , if u is black
  if (IsBlack(u)) {
    // paint color
    if (IsLChild(x) && IsLChild(p) || IsRChild(x) && IsRChild(p))
      p->_color = RBcolor::black;
    else
      x->_color = RBcolor::black;
    // g must be red
    g->_color = RBcolor::red;
    // then it is like AVL tree
    const auto gg = g->parent;

    /*error occurs again，the latter execute first, which
     * affects GParent
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     * * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     */
    auto& gg_ref = this->FromParentTo(g);
    auto r = (gg_ref = this->rotateAt(x));
    r->parent = gg;
    return;
  }
  // if u is red
  u->_color = RBcolor::black;
  p->_color = RBcolor::black;
  u->height++, p->height++;
  g->_color = RBcolor::red;
  solveDoubleRed(g);
}
}  // namespace CYT_DSA