#include <iostream>
#include <stdexcept>
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

    void popToSorted() {
        // 删除最大元素，并把它放到数组末尾
        if (heapSize == 0) {
            throw underflow_error("堆为空");
        }

        T maximum = heap[1];
        T lastElement = heap[heapSize];
        heap[heapSize] = maximum;
        --heapSize;

        // 从根开始，为最后一个元素寻找位置
        int currentNode = 1, child = 2 * currentNode; // currentNode 的孩子
        while (child <= heapSize) {
            // heap[child] 应该是 currentNode 的较大孩子
            if (child < heapSize && heap[child] < heap[child + 1]) {
                child++;
            }

            // 可以把 lastElement 放在 heap[currentNode] 吗？
            if (lastElement >= heap[child]) {
                break; // 可以
            }

            // 不可以
            heap[currentNode] = heap[child]; // 把孩子 child 向上移动
            currentNode = child;             // 向下移动一层寻找位置
            child *= 2;
        }
        if (heapSize > 0) {
            heap[currentNode] = lastElement;
        }
    }
};

void printHeapArray(const int *heap, int totalSize, int heapSize);
void printTreeRow(const string &row);
void printTree(const int *heap, int totalSize, int heapSize);
void printState(const int *heap, int totalSize, int heapSize);

int main() {
    const int initialValues[] = {5, 7, 2, 9, 3, 8, 6, 1};
    const int initialSize = sizeof(initialValues) / sizeof(initialValues[0]);
    int *initialHeap = new int[initialSize + 1];
    for (int i = 1; i <= initialSize; ++i) {
        initialHeap[i] = initialValues[i - 1];
    }

    // 输出初始完全二叉树。
    printState(initialHeap, initialSize, initialSize);

    maxHeap<int> theHeap;
    // 按程序12-4的方法堆化，并输出大根堆。
    theHeap.initialize(initialHeap, initialSize);
    printState(theHeap.data(), initialSize, theHeap.size());

    // 依次删除大根堆的最大元素，输出每次删除后的堆排序状态。
    while (theHeap.size() > 0) {
        theHeap.popToSorted();
        printState(theHeap.data(), initialSize, theHeap.size());
    }

    return 0;
}

void printHeapArray(const int *heap, int totalSize, int heapSize) {
    cout << "[-";
    for (int i = 1; i <= totalSize; ++i) {
        cout << ", ";
        if (i > heapSize) {
            cout << '[' << heap[i] << ']';
        } else {
            cout << heap[i];
        }
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

void printTree(const int *heap, int totalSize, int heapSize) {
    if (totalSize == 0) {
        return;
    }

    int depth = 1;
    for (int levelStart = 1; levelStart * 2 <= totalSize; levelStart *= 2) {
        ++depth;
    }

    int maxValueWidth = 1;
    for (int i = 1; i <= totalSize; ++i) {
        int valueWidth = static_cast<int>(to_string(heap[i]).size());
        if (i > heapSize) {
            valueWidth += 2;
        }
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

        for (int index = levelStart; index < levelEnd && index <= totalSize;
             ++index) {
            const int positionInLevel = index - levelStart;
            const int center =
                (2 * positionInLevel + 1) * horizontalScale * gap;
            string value = to_string(heap[index]);
            if (index > heapSize) {
                value = '[' + value + ']';
            }
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
        for (int index = levelStart; index < levelEnd && index <= totalSize;
             ++index) {
            const int positionInLevel = index - levelStart;
            const int center =
                (2 * positionInLevel + 1) * horizontalScale * gap;
            const int leftChild = index * 2;
            const int rightChild = leftChild + 1;
            if (leftChild <= totalSize) {
                connectorRow[center - childOffset] = '/';
            }
            if (rightChild <= totalSize) {
                connectorRow[center + childOffset] = '\\';
            }
        }
        printTreeRow(connectorRow);
    }
}

void printState(const int *heap, int totalSize, int heapSize) {
    printHeapArray(heap, totalSize, heapSize);
    cout << '\n';
    printTree(heap, totalSize, heapSize);
    cout << '\n';
}