#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

template <class T> struct binaryTreeNode {
    T element;
    binaryTreeNode<T> *leftChild;
    binaryTreeNode<T> *rightChild;

    binaryTreeNode() { leftChild = rightChild = NULL; }

    binaryTreeNode(const T &theElement) : element(theElement) {
        leftChild = rightChild = NULL;
    }

    binaryTreeNode(const T &theElement, binaryTreeNode<T> *theLeftChild,
                   binaryTreeNode<T> *theRightChild)
        : element(theElement) {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

template <class T> class BinaryTree {
  private:
    typedef binaryTreeNode<T> Node;
    Node *root;

    static Node *buildComplete(const std::vector<T> &elements,
                               std::size_t index) {
        if (index >= elements.size()) {
            return NULL;
        }

        Node *node = new Node(elements[index]);
        try {
            node->leftChild = buildComplete(elements, index * 2 + 1);
            node->rightChild = buildComplete(elements, index * 2 + 2);
        } catch (...) {
            destroy(node);
            throw;
        }
        return node;
    }

    static void mirror(Node *node) {
        if (node == NULL) {
            return;
        }
        std::swap(node->leftChild, node->rightChild);
        mirror(node->leftChild);
        mirror(node->rightChild);
    }

    static int levelOf(const Node *node, int value, int level) {
        if (node == NULL) {
            return -1;
        }
        if (node->element == value) {
            return level;
        }

        int leftLevel = levelOf(node->leftChild, value, level + 1);
        if (leftLevel != -1) {
            return leftLevel;
        }
        return levelOf(node->rightChild, value, level + 1);
    }

    static bool contains(const Node *node, int value) {
        return node != NULL &&
               (node->element == value || contains(node->leftChild, value) ||
                contains(node->rightChild, value));
    }

    static const Node *lowestCommonAncestor(const Node *node, int first,
                                            int second) {
        if (node == NULL || node->element == first || node->element == second) {
            return node;
        }

        const Node *left = lowestCommonAncestor(node->leftChild, first, second);
        const Node *right =
            lowestCommonAncestor(node->rightChild, first, second);
        if (left != NULL && right != NULL) {
            return node;
        }
        return left != NULL ? left : right;
    }

    static void printPreorder(const Node *node, std::ostream &out) {
        if (node == NULL) {
            return;
        }
        out << node->element << ' ';
        printPreorder(node->leftChild, out);
        printPreorder(node->rightChild, out);
    }

    static void destroy(Node *node) {
        if (node != NULL) {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
        }
    }

  public:
    BinaryTree() : root(NULL) {}

    ~BinaryTree() { destroy(root); }

    BinaryTree(const BinaryTree &) = delete;
    BinaryTree &operator=(const BinaryTree &) = delete;

    void readComplete(std::istream &in) {
        int count;
        if (!(in >> count) || count < 0) {
            throw std::runtime_error("Expected a non-negative node count.");
        }

        std::vector<T> elements(count);
        for (int i = 0; i < count; ++i) {
            if (!(in >> elements[i])) {
                throw std::runtime_error("Incomplete level-order sequence.");
            }
        }

        Node *newRoot = buildComplete(elements, 0);
        destroy(root);
        root = newRoot;
    }

    void mirror() { mirror(root); }

    int levelOf(int value) const { return levelOf(root, value, 1); }

    const T *lcaValue(int first, int second) const {
        if (!contains(root, first) || !contains(root, second)) {
            return NULL;
        }
        const Node *ancestor = lowestCommonAncestor(root, first, second);
        return ancestor == NULL ? NULL : &ancestor->element;
    }

    void printPreorder(std::ostream &out) const { printPreorder(root, out); }
};

int main() {
    try {
        BinaryTree<int> tree;
        std::cout << "Enter the node count, followed by level-order values:\n";
        tree.readComplete(std::cin);

        int first;
        int second;
        std::cout << "Enter two node values to query:\n";
        if (!(std::cin >> first >> second)) {
            std::cerr << "Expected two integer node values.\n";
            return 1;
        }

        std::cout << "Level of " << first << ": " << tree.levelOf(first)
                  << '\n';
        std::cout << "Level of " << second << ": " << tree.levelOf(second)
                  << '\n';

        const int *ancestor = tree.lcaValue(first, second);
        if (ancestor == NULL) {
            std::cout << "Lowest common ancestor: not found\n";
        } else {
            std::cout << "Lowest common ancestor: " << *ancestor << '\n';
        }

        std::cout << "Preorder before mirroring: ";
        tree.printPreorder(std::cout);
        std::cout << '\n';
        tree.mirror();
        std::cout << "Preorder after mirroring: ";
        tree.printPreorder(std::cout);
        std::cout << '\n';
    } catch (const std::exception &error) {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}