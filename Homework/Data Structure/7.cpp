#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class HuffmanTree {
  public:
    struct Node {
        int weight;
        int leftChild;
        int rightChild;

        Node(int theWeight, int left = -1, int right = -1)
            : weight(theWeight), leftChild(left), rightChild(right) {}

        bool isLeaf() const { return leftChild == -1 && rightChild == -1; }
    };

    struct QueueEntry {
        int weight;
        int nodeIndex;
    };

    struct CompareQueueEntry {
        bool operator()(const QueueEntry &left, const QueueEntry &right) const {
            if (left.weight != right.weight) {
                return left.weight > right.weight;
            }
            return left.nodeIndex > right.nodeIndex;
        }
    };

  private:
    vector<Node> nodes;
    vector<int> inputWeights;
    int root;

    void saveCode(int nodeIndex, const string &code,
                  vector<string> &codes) const {
        const Node &current = nodes[nodeIndex];
        if (current.isLeaf()) {
            for (int i = 0; i < static_cast<int>(inputWeights.size()); ++i) {
                if (inputWeights[i] == current.weight) {
                    codes[i] = code;
                    return;
                }
            }
            return;
        }

        saveCode(current.leftChild, code + '0', codes);
        saveCode(current.rightChild, code + '1', codes);
    }

  public:
    explicit HuffmanTree(const vector<int> &weights)
        : inputWeights(weights), root(-1) {
        for (int weight : weights) {
            nodes.push_back(Node(weight));
        }

        priority_queue<QueueEntry, vector<QueueEntry>, CompareQueueEntry>
            active;
        for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
            active.push(QueueEntry{nodes[i].weight, i});
        }

        while (active.size() > 1) {
            const int first = active.top().nodeIndex;
            active.pop();
            const int second = active.top().nodeIndex;
            active.pop();

            nodes.push_back(Node(nodes[first].weight + nodes[second].weight,
                                 first, second));
            const int parent = static_cast<int>(nodes.size()) - 1;
            active.push(QueueEntry{nodes[parent].weight, parent});
        }

        if (!active.empty()) {
            root = active.top().nodeIndex;
        }
    }

    int rootIndex() const { return root; }

    int nodeCount() const { return static_cast<int>(nodes.size()); }

    const Node &nodeAt(int index) const { return nodes[index]; }

    void printCodes() const {
        if (root == -1) {
            return;
        }

        vector<string> codes(inputWeights.size());
        saveCode(root, "", codes);
        for (int i = 0; i < static_cast<int>(inputWeights.size()); ++i) {
            cout << inputWeights[i] << ": " << codes[i] << '\n';
        }
    }
};

void printTreeRow(const string &row);
void assignPositions(const HuffmanTree &tree, int nodeIndex, int level,
                     int &nextLeaf, vector<int> &xPosition,
                     vector<int> &nodeLevel);
void printTree(const HuffmanTree &tree);

int main() {
    const vector<int> weights = {3, 7, 9, 12, 15, 20, 25};
    HuffmanTree tree(weights);

    // 输出霍夫曼树，边上的0、1分别表示左、右分支。
    printTree(tree);
    cout << '\n';

    // 输出每个权值对应的霍夫曼编码。
    tree.printCodes();

    return 0;
}

void printTreeRow(const string &row) {
    const string::size_type lastCharacter = row.find_last_not_of(' ');
    if (lastCharacter == string::npos) {
        cout << '\n';
    } else {
        cout << row.substr(0, lastCharacter + 1) << '\n';
    }
}

void assignPositions(const HuffmanTree &tree, int nodeIndex, int level,
                     int &nextLeaf, vector<int> &xPosition,
                     vector<int> &nodeLevel) {
    const HuffmanTree::Node &current = tree.nodeAt(nodeIndex);
    nodeLevel[nodeIndex] = level;

    if (current.isLeaf()) {
        xPosition[nodeIndex] = 3 + nextLeaf * 8;
        ++nextLeaf;
        return;
    }

    assignPositions(tree, current.leftChild, level + 1, nextLeaf, xPosition,
                    nodeLevel);
    assignPositions(tree, current.rightChild, level + 1, nextLeaf, xPosition,
                    nodeLevel);
    xPosition[nodeIndex] =
        (xPosition[current.leftChild] + xPosition[current.rightChild]) / 2;
}

void printTree(const HuffmanTree &tree) {
    if (tree.rootIndex() == -1) {
        return;
    }

    vector<int> xPosition(tree.nodeCount(), 0);
    vector<int> nodeLevel(tree.nodeCount(), 0);
    int nextLeaf = 0;
    assignPositions(tree, tree.rootIndex(), 0, nextLeaf, xPosition, nodeLevel);

    int depth = 0;
    for (int level : nodeLevel) {
        if (level > depth) {
            depth = level;
        }
    }

    const int rowWidth = 3 + (nextLeaf - 1) * 8 + 5;
    for (int level = 0; level <= depth; ++level) {
        string nodeRow(rowWidth, ' ');
        string connectorRow(rowWidth, ' ');

        for (int i = 0; i < tree.nodeCount(); ++i) {
            if (nodeLevel[i] != level) {
                continue;
            }

            const HuffmanTree::Node &node = tree.nodeAt(i);
            const string weight = to_string(node.weight);
            const int start =
                xPosition[i] - static_cast<int>(weight.size()) / 2;
            nodeRow.replace(start, weight.size(), weight);

            if (node.isLeaf()) {
                continue;
            }

            const int left = node.leftChild;
            const int right = node.rightChild;
            const int leftEdge = (xPosition[i] + xPosition[left]) / 2;
            const int rightEdge = (xPosition[i] + xPosition[right]) / 2;
            connectorRow[leftEdge - 1] = '0';
            connectorRow[leftEdge] = '/';
            connectorRow[rightEdge - 1] = '1';
            connectorRow[rightEdge] = '\\';
        }

        printTreeRow(nodeRow);
        if (level < depth) {
            printTreeRow(connectorRow);
        }
    }
}