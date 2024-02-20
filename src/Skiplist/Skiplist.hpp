#pragma once
#include "../Dictionary/Dictionary.hpp"
#include "../Dictionary/Entry.hpp"
#include "../List/List.hpp"
#include "Quadlist.hpp"

#define __SKIPLIST_DEBUG__
#ifdef __SKIPLIST_DEBUG__
#include <iostream>
#include <string>
#endif

namespace CYT_DSA {
template <typename K, typename V>  // key、value
// 符合Dictionary接口的Skiplist模板类（隐含假设元素之间可比较大小）
class Skiplist : public Dictionary<K, V>,
                 private List<Quadlist<Entry<K, V> >*> {
 public:
  Skiplist() {
    this->push_front(new Quadlist<Entry<K, V> >);
  };  // 即便为空，也有一层空列表
      // 词条总数
  int size() const {
    return List<Quadlist<Entry<K, V> >*>::empty()
               ? 0
               : List<Quadlist<Entry<K, V> >*>::last()->data->size();
  }

  int height() {
    return List<Quadlist<Entry<K, V> >*>::size();
  }                // 层高 == #Quadlist
  V* get(K);       // 读取
  bool put(K, V);  // 插入（Skiplist允许词条重复，故必然成功）
  bool remove(K) ;  // 删除
  using List<Quadlist<Entry<K, V> >*>::first;
  using List<Quadlist<Entry<K, V> >*>::last;

#ifdef __SKIPLIST_DEBUG__
  void show() const {
    const auto& l = *this;
    auto iter = l.first();
    int cnt = 0, i = 0;
    const int MAXL = this->last()->data->size();
    constexpr int STEP = 17;
    do {
      const auto& quadlist = **iter;
      i = 0;
      std::cout << "level : " << cnt++ << '\n';
      std::string tmp;
      for (auto p = quadlist.qheader->succ; p != quadlist.qtrailer;
           p = p->succ) {
        tmp = "key: " + std::to_string(p->entry.key) +
              " value: " + std::to_string(p->entry.value) + "--";
        std::cout.width(STEP);
        std::cout << tmp;
        i++;
      }
      //++iter;
      std::cout << "\n";
    } while (iter++ != l.last());
    std::cout << "______________________________\n";
  }
#endif

 protected:
  QNodePosi<Entry<K, V> > search(K) const;  // 由关键码查询词条
};
}  // namespace CYT_DSA

#include "Skiplist_impl.hpp"