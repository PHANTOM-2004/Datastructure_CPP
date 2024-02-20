#pragma once

namespace CYT_DSA {

template <typename K, typename V>
QPtr<Entry<K, V>> Skiplist<K, V>::search(K key) const {
  auto p = this->first()->data->qheader;
  while (true) {
    if (p->succ->succ && p->succ->entry.key <= key)
      p = p->succ;
    else if (p->below)
      p = p->below;
    else
      break;
  }
  return p;
}

template <typename K, typename V>
V* Skiplist<K, V>::get(K key) {
  auto p = search(key);  // 无论是否命中，search()都不会返回nullptr, 可能返回qheader，
                       // 但不会qtrailer
  return (p->pred && p->entry.key == key)
             ? &(p->entry.value)
             : nullptr;  // 前者说明不是header， 后者说明恰好是这个值
}

}  // namespace CYT_DSA