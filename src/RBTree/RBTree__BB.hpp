#pragma once

namespace CYT_DSA {
template <class T>
void RBTree<T>::solveDoubleBlack(BinNodePosi<T> r) {
  // 根节点的特殊情况

  // r父亲
  auto p = r ? r->parent : this->_hot;
  if (p == nullptr) return;  // 根节点情况不用考虑
  //！！！！！！！！！！！！！！！！！！！！！！！
  //这里不能用sibling，因为r可以是空指针
  auto s = r == p->left ? p->right : p->left;

  // 以下分情况考虑,两大类,主要是根据s的颜色进行分类,最后红s会转化为黑s
  if (IsRed(s)) {
    s->_color = RBcolor ::black;
    p->_color = RBcolor ::red;
    auto t = IsLChild(s) ? s->left : s->right;
    auto& fromp_parent = this->FromParentTo(p);
    this->_hot = p;//记录_hot
    fromp_parent = this->rotateAt(t);
    solveDoubleBlack(r);
    return;
  }
  
  // 以下是黑s的情况
  RBPtr<T> t = nullptr;
  if (IsRed(s->left))
    t = s->left;
  else if (IsRed(s->right))
    t = s->right;
  if (t) {  // BB - 1有red孩子
    const auto colorp = p->_color;
    p->_color = RBcolor::black;

    // 旋转
    auto& fromp_parent = this->FromParentTo(p);
    auto b = (fromp_parent = this->rotateAt(t));

    // 对p和t染黑
    if (HasLChild(b)) {
      b->left->_color = RBcolor::black;
      this->updateHeight(b->left);
    }
    if (HasRChild(b)) {
      b->right->_color = RBcolor::black;
      this->updateHeight(b->right);
    }

    // 替代p的颜色
    b->_color = colorp;
    this->updateHeight(b);

  } else {
    // BB - 2 p = red
    if (IsRed(p)) {
      //std::swap(p->_color, s->_color);
      p->_color = RBcolor::black;
      s->_color = RBcolor::red;
      s->height--;  // 注意p->height不用++, 因为黑高度没变化
    } else {
      // BB - 2 p = black
      s->_color = RBcolor::red;
      s->height--;
      p->height--;
      solveDoubleBlack(p);// 此时_hot没有变化
    }
  }
}

}  // namespace CYT_DSA