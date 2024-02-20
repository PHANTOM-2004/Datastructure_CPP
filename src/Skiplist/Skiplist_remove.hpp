#pragma once

namespace CYT_DSA {
template <typename K, typename V>
bool Skiplist<K, V>::remove(K key) {
  auto pos = search(key);
  if (pos->pred == nullptr || pos->entry.key != key) return false;
    
  auto qlist = this->last();//获取塔底部
  while (pos->above != nullptr) {
    pos = pos->above;//一直往上走，走到最上面的结点
    --qlist;//列表也从last往前走
  }
  /*开始删除塔*/
  do {
    auto next = pos->below;
    qlist->data->remove(pos);
    pos = next;//提前记录，否则pos释放之后就不能到达next了
    ++qlist;
  } while (qlist->succ != nullptr);//下一个qlist不是trailer
  /*开始删除空的表*/

  while (height() > 1 && this->first()->data->size() < 1) {
    this->pop_front();
    //呼应put部分的插入,设置了顶层表的above与below
    this->first()->data->qheader->above = nullptr;
  }
  return true;
}
}  // namespace CYT_DSA