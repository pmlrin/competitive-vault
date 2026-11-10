#include <iostream>
#include <string>

using namespace std;

template <class T> class maxHeap {
  private:
    T *heap;
    int arrayLength;
    int heapSize;

    void changeLength1D(T *&theHeap, int oldLength, int newLength) {
        T *newHeap = new T[newLength];
        int copyLength = oldLength < newLength ? oldLength : newLength;
        for (int i = 0; i < copyLength; ++i) {
            newHeap[i] = theHeap[i];
        }
        delete[] theHeap;
        theHeap = newHeap;
    }

  public:
    maxHeap() : heap(NULL), arrayLength(0), heapSize(0) {}

    ~maxHeap() { delete[] heap; }

    maxHeap(const maxHeap &) = delete;
    maxHeap &operator=(const maxHeap &) = delete;

    int size() const { return heapSize; }

    const T &operator[](int index) const { return heap[index]; }
    const T *data() const { return heap; }

    void initialize(T *theHeap, int theSize) {
        // 在数组 theHeap[1:theSize] 中建立大根堆
        delete[] heap;
        heap = theHeap;
        heapSize = theSize;
        arrayLength = theSize + 1;

        // 堆化
        for (int root = heapSize / 2; root >= 1; root--) {
            T rootElement = heap[root];

            // 为元素 rootElement 寻找位置
            int child = 2 * root; // 孩子 child 的双亲是元素 rootElement 的位置
            while (child <= heapSize) {
                // heap[child] 应该是兄弟中较大者
                if (child < heapSize && heap[child] < heap[child + 1]) {
                    child++;
                }

                // 可以把元素 rootElement 放在 heap[child/2] 吗
                if (rootElement >= heap[child]) {
                    break; // 可以
                }

                // 不可以
                heap[child / 2] = heap[child]; // 把孩子向上移
                child *= 2;                    // 移到下一层
            }
            heap[child / 2] = rootElement;
        }
    }

    void push(const T &theElement) {
        // 把元素 theElement 加入堆

        // 必要时增加数组长度
        if (heapSize == arrayLength - 1) {
            // 数组长度加倍
            changeLength1D(heap, arrayLength, 2 * arrayLength);
            arrayLength *= 2;
        }

        // 为元素 theElement 寻找插入位置
        // currentNode 从新叶子向上移动
        int currentNode = ++heapSize;
        while (currentNode != 1 && heap[currentNode / 2] < theElement) {
            // 不能把元素 theElement 插入在 heap[currentNode]
            heap[currentNode] = heap[currentNode / 2]; // 把元素向下移动
            currentNode /= 2;                          // currentNode 移向双亲
        }
        heap[currentNode] = theElement;
    }

    void pop() {
        // 删除最大元素

        // 如果堆为空，抛出异常
        if (heapSize == 0) {
            throw underflow_error("堆为空");
        }

        // 删除最大元素
        heap[1] = ~T();

        // 删除最后一个元素，然后重新堆化
        T lastElement = heap[heapSize--];

        // 从根开始，为最后一个元素寻找位置
        int currentNode = 1, child = 2 * currentNode; // currentNode的孩子
        while (child <= heapSize) {
            // heap[child] 应该是 currentNode 的更大的孩子
            if (child < heapSize && heap[child] < heap[child + 1]) {
                child++;
            }

            // 可以把 lastElement 放在 heap[currentNode] 吗？
            if (lastElement >= heap[child]) {
                break; // 可以
            }

            // 不可以
            heap[currentNode] = heap[child]; // 把孩子child向上移动
            currentNode = child;             // 向下移动一层寻找位置
            child *= 2;
        }
        heap[currentNode] = lastElement;
    }
};

void printHeapArray(const int *heap, int heapSize);
void printTreeRow(const string &row);
void printTree(const int *heap, int heapSize);
void printState(const maxHeap<int> &heap);

int main() {
    const int initialValues[] = {3, 5, 6, 7, 20, 8, 2, 9, 12, 15, 30, 17};
    const int initialSize = sizeof(initialValues) / sizeof(initialValues[0]);
    int *initialHeap = new int[initialSize + 1];
    for (int i = 1; i <= initialSize; ++i) {
        initialHeap[i] = initialValues[i - 1];
    }

    // 输出初始完全二叉树。
    printHeapArray(initialHeap, initialSize);
    cout << '\n';
    printTree(initialHeap, initialSize);
    cout << '\n';

    cout << "================================================================="
            "\n\n";

    maxHeap<int> theHeap;
    theHeap.initialize(initialHeap, initialSize);
    // 使用程序12-4建堆，并输出结果。
    printState(theHeap);

    cout << "================================================================="
            "\n\n";

    const int valuesToInsert[] = {15, 20, 45};
    for (int value : valuesToInsert) {
        // 使用程序12-2依次插入元素，并输出每次插入后的堆。
        theHeap.push(value);
        printState(theHeap);
    }

    cout << "================================================================="
            "\n\n";

    for (int count = 1; count <= 4; ++count) {
        // 使用程序12-3连续删除最大元素，并输出每次删除后的堆。
        theHeap.pop();
        printState(theHeap);
    }

    return 0;
}

void printHeapArray(const int *heap, int heapSize) {
    cout << "[-";
    for (int i = 1; i <= heapSize; ++i) {
        cout << ", " << heap[i];
    }
    cout << "]\n";
}

void printTreeRow(const string &row) {
    const string::size_type lastCharacter = row.find_last_not_of(' ');
    if (lastCharacter == string::npos) {
        cout << '\n';
    } else {
        cout << row.substr(0, lastCharacter + 1) << '\n';
    }
}

void printTree(const int *heap, int heapSize) {
    if (heapSize == 0) {
        return;
    }

    int depth = 1;
    for (int levelStart = 1; levelStart * 2 <= heapSize; levelStart *= 2) {
        ++depth;
    }

    int maxValueWidth = 1;
    for (int i = 1; i <= heapSize; ++i) {
        const int valueWidth = static_cast<int>(to_string(heap[i]).size());
        if (valueWidth > maxValueWidth) {
            maxValueWidth = valueWidth;
        }
    }

    const int gap = (maxValueWidth + 2) / 2;
    const int rowWidth = (1 << depth) * gap + 1;

    for (int level = 1; level <= depth; ++level) {
        const int levelStart = 1 << (level - 1);
        const int levelEnd = levelStart << 1;
        const int horizontalScale = 1 << (depth - level);
        string nodeRow(rowWidth, ' ');

        for (int index = levelStart; index < levelEnd && index <= heapSize;
             ++index) {
            const int positionInLevel = index - levelStart;
            const int center =
                (2 * positionInLevel + 1) * horizontalScale * gap;
            const string value = to_string(heap[index]);
            const int valueStart = center - static_cast<int>(value.size()) / 2;
            nodeRow.replace(valueStart, value.size(), value);
        }
        printTreeRow(nodeRow);

        if (level == depth) {
            continue;
        }

        string connectorRow(rowWidth, ' ');
        const int childOffset =
            horizontalScale * gap / 4 > 0 ? horizontalScale * gap / 4 : 1;
        for (int index = levelStart; index < levelEnd && index <= heapSize;
             ++index) {
            const int positionInLevel = index - levelStart;
            const int center =
                (2 * positionInLevel + 1) * horizontalScale * gap;
            const int leftChild = index * 2;
            const int rightChild = leftChild + 1;
            if (leftChild <= heapSize) {
                connectorRow[center - childOffset] = '/';
            }
            if (rightChild <= heapSize) {
                connectorRow[center + childOffset] = '\\';
            }
        }
        printTreeRow(connectorRow);
    }
}

void printState(const maxHeap<int> &heap) {
    printHeapArray(heap.data(), heap.size());
    cout << '\n';
    printTree(heap.data(), heap.size());
    cout << '\n';
}
