#include <iostream>
#include <sstream>
using namespace std;

template <class T> struct chainNode {
    // 数据成员
    T element;
    chainNode<T> *next;

    // 方法
    chainNode() : next(NULL) {}

    chainNode(const T &element) : element(element), next(NULL) {}

    chainNode(const T &element, chainNode<T> *next)
        : element(element), next(next) {}
};

template <class T> class chain {
  public:
    // 构造函数，复制构造函数和析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T> &);
    ~chain();

    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }

    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;
    void reverse(); // 原地反转

  protected:
    void checkIndex(int theIndex) const;
    // 如果索引无效，抛出异常

    chainNode<T> *firstNode; // 指向链表第一个节点的指针
    int listSize;            // 线性表的元素个数
};

template <class T> chain<T>::chain(int initialCapacity) { // 构造函数
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw s.str();
    }

    firstNode = NULL;
    listSize = 0;
}

template <class T> chain<T>::chain(const chain<T> &theList) { // 复制构造函数
    listSize = theList.listSize;

    if (listSize == 0) {
        // 链表 theList 为空
        firstNode = NULL;
        return;
    }

    // 链表 theList 为非空
    chainNode<T> *sourceNode = theList.firstNode;

    // 要复制链表 theList 的节点
    firstNode = new chainNode<T>(sourceNode->element);

    // 复制链表 theList 的首元素
    sourceNode = sourceNode->next;

    chainNode<T> *targetNode = firstNode;

    // 当前链表 *this 的最后一个节点
    while (sourceNode != NULL) {
        // 复制剩余元素
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }

    targetNode->next = NULL;
} // 链表结束

template <class T> chain<T>::~chain() {
    // 链表析构函数，删除链表的所有节点
    while (firstNode != NULL) {
        // 删除首节点
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T> void chain<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw s.str();
    }
}

template <class T> T &chain<T>::get(int theIndex) const {
    // 返回索引为 theIndex 的元素
    // 若该元素不存在，则抛出异常
    checkIndex(theIndex);

    // 移向所需要的节点
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}

template <class T> int chain<T>::indexOf(const T &theElement) const {
    // 返回元素 theElement 首次出现时的索引
    // 若该元素不存在，则返回 -1

    // 搜索链表寻找元素 theElement
    chainNode<T> *currentNode = firstNode;
    int index = 0; // 当前节点的索引

    while (currentNode != NULL && currentNode->element != theElement) {
        // 移向下一个节点
        currentNode = currentNode->next;
        index++;
    }

    // 确定是否找到所需的元素
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template <class T> void chain<T>::erase(int theIndex) {
    // 删除索引为 theIndex 的元素
    // 若该元素不存在，则抛出异常
    checkIndex(theIndex);

    // 索引有效，需找要删除的元素节点
    chainNode<T> *deleteNode;

    if (theIndex == 0) {
        // 删除链表的首节点
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        // 用指针 p 指向要删除节点的前驱节点
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next;
        // 删除 deleteNode 指向的节点
    }

    listSize--;
    delete deleteNode;
}

template <class T> void chain<T>::insert(int theIndex, const T &theElement) {
    // 在索引为 theIndex 的位置上插入元素 theElement
    if (theIndex < 0 || theIndex > listSize) {
        // 无效索引
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw s.str();
    }

    if (theIndex == 0) {
        // 在链表头插入
        firstNode = new chainNode<T>(theElement, firstNode);
    } else {
        // 寻找新元素的前驱
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // 在 p 之后插入
        p->next = new chainNode<T>(theElement, p->next);
    }

    listSize++;
}

template <class T> void chain<T>::output(ostream &out) const {
    // 把链表放入输出流
    for (chainNode<T> *currentNode = firstNode; currentNode != NULL;
         currentNode = currentNode->next) {
        out << currentNode->element << " ";
    }
}

// 重载 <<
template <class T> ostream &operator<<(ostream &out, const chain<T> &x) {
    x.output(out);
    return out;
}

template <class T> void chain<T>::reverse() {
    chainNode<T> *prev = NULL;         // 前驱指针
    chainNode<T> *current = firstNode; // 当前指针
    chainNode<T> *nextNode = NULL;     // 后继指针

    while (current != NULL) {
        nextNode = current->next; // 先保存后继，防止断链
        current->next = prev;     // 反转当前节点的指针方向
        prev = current;           // prev 后移
        current = nextNode;       // current 后移
    }

    firstNode = prev; // 更新头指针
    /*复杂度分析
      设链表长度为 n = listSize。
      时间复杂度：while 循环恰好执行 n 次，每次只做常数次指针操作，所以为 O(n)。
      空间复杂度：只使用了 prev、current、nextNode 三个指针变量，
      没有申请任何新节点，所以为 O(1)。*/
}

int main() {
    chain<int> c;
    for (int i = 0; i < 10; i++)
        c.insert(i, i);

    cout << "initial: " << c << endl;
    c.reverse();
    cout << "reversed: " << c << endl;

    return 0;
}