迭代器适配器：返回迭代器的函数，迭代器的属性和参数相关。
copy(begin,end,back_inserter(container))
从back_inserter返回的迭代器的位置开始复制[begin,end)的序列。

remove(begin,end,element)
从[begin,end)删除满足element的元素，返回最后一个元素之后下一个的迭代器

remove_copy(begin,end,destenation(iterator),element)
从[begin,end)排除掉满足element的元素之后复制到destenation位置，返回原序列
最后一个被复制的元素的下一个位置的迭代器。

remove_copy_if(begin,end,destenation(ietrator),predicate)
从[begin,end)删除满足predicate函数的元素，并将删除后的元素复制到destenation的位置，返回原序列最后一个被复制的元素的下一个位置的迭代器。

partition(begin,end,predicate)
使得满足predicate的元素排在[begin,end)序列的前面
不满足的排在后面，返回指向第一个不满足的元素的迭代器。
会改变各区域元素原来的相对顺序。
stable_partition(begin,end,predicate)
不会改变各区域元素原来的相对顺序
对于算法库里面的算法的理解：算法作用在容器的元素上，而非作用于容器。

