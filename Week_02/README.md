学习笔记

一：数据结构
概述：这周学习的数据结构有哈希表、集合（基于hash函数）、树（用的少）、二叉树、二叉搜索树、堆、二叉堆和图。

1、哈希表map：hash是key-value对，其中key不重复，hash函数通过key值对应一个地址，hash函数的好坏决定了哈希表的性能，
通常不同的key值会映射到不同的地址，很小的概率会出现哈希冲突，通过链表的方式处理冲突；哈希表搜索、插入和删除的
时间复杂度为O(1)。
c++ map API如下：
 begin()         返回指向map头部的迭代器
 clear(）        删除所有元素
 count()         返回指定元素出现的次数
 empty()         如果map为空则返回true
 end()           返回指向map末尾的迭代器
 equal_range()   返回特殊条目的迭代器对
 erase()         删除一个元素
 find()          查找一个元素
 get_allocator() 返回map的配置器
 insert()        插入元素
 key_comp()      返回比较元素key的函数
 lower_bound()   返回键值>=给定元素的第一个位置
 max_size()      返回可以容纳的最大元素个数
 rbegin()        返回一个指向map尾部的逆向迭代器
 rend()          返回一个指向map头部的逆向迭代器
 size()          返回map中元素的个数
 swap()           交换两个map
 upper_bound()    返回键值>给定元素的第一个位置
 value_comp()     返回比较元素value的函数
 
2、集合set：是不重复的数据元素的集合，没有键-值对的概念，系统会自动根据值进行排序。
c++ set API如下：
begin()：返回set容器的第一个元素
end()：返回set容器的最后一个元素
clear()：删除set容器中的所有的元素
empty()：判断set容器是否为空
max_size()：返回set容器可能包含的元素最大个数
size()：返回当前set容器中的元素个数
rbegin()：返回的值和end()相同
rend():返回的值和begin()相同
count(key_value):用来查找set中某个某个键值出现的次数
find(key_value)：返回给定值值得定位器，如果没找到则返回end()。
equal_range(key_value):返回一对定位器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素
erase(index):删除指定位置或者范围指向的值
insert(key_value)：将key_value插入到set中 ，返回值是pair<set<int>::iterator,bool>，bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。
lower_bound(key_value)：返回第一个大于等于key_value的定位器
upper_bound(key_value)：返回最后一个大于key_value的定位器

3、二叉树：是特殊的树，其中每个节点最多只有两个子节点（左子树和右子树），二叉树遍历分为前中后序遍历，通常使用递归遍历，（由于树的定义，无法使用循环遍历）。
4、二叉搜索树：是特殊的二叉树，其中根节点大于左子树，小于右子树；左右子树都是二叉搜索树；其中中序遍历是升序排列；查询、插入和删除的时间复杂度都为O(log(N)），最差的时间复杂度退化为O(N），比如退化为
链表。
5、堆：可以迅速找到一堆数据中的最大或者最小值得数据结构。根节点最大的堆称为大顶堆或者大根堆，根节点最小的堆称为小顶堆或者小根堆，常见的堆有二叉堆、斐波那契堆等。对于大顶堆，搜索最大值是O(1)，插入
和删除的时间复杂度为O(log(N))。