#pragma once
#include <cstdlib>
#include <cstdio>


namespace CYT_DSA {
template <typename K, typename V>
bool Skiplist<K, V>::put(K key, V value) {
  Entry<K, V> e = Entry<K, V>(key, value);//插入的entry
  auto qpos = search(key);//最底层插入的qpos
  auto listq = this->last();//最底层的list, 是一个listnode
  auto base = listq->data->insert(e, qpos);//把e插入到qpos的右边，nullptr的上边，返回了base的位置

  while (rand() & 1) {//0.5的概率决定是否长高
      //不低于此高度的最近前驱，前驱存在，并且above为空，说明高度大于等于当前高度
    while (qpos->pred != nullptr && qpos->above == nullptr) {
      //printf("find up\r");
      qpos = qpos->pred;
    }

    //pos前驱是nullptr, 说明pos是list的header，也就是上面的while循环没有执行, 
    // pos->above是nullptr，说明已经到了最顶层
    if (qpos->pred == nullptr && qpos->above == nullptr) {
      this->push_front(new Quadlist<Entry<K, V>>);//新建一层
      // 新建一层的, header的below是下一层的header
      this->first()->data->qheader->below = listq->data->qheader;
      //下一层的header的above是新建一层的header
      listq->data->qheader->above = this->first()->data->qheader;
    }

    qpos = qpos->above;//qpos上升一层
    --listq;//listq上升一个结点
    base = listq->data->insert(e, qpos, base);//插入到qpos的右面，上一次base的上面
  }

  return true;
}
}