#include<iostream>
#include<queue>
using namespace std;

struct HuffmanNode {
    char symbol;
    unsigned int frequency;
    HuffmanNode *leftChild, *rightChild;

    HuffmanNode(char symbol, unsigned int frequency, HuffmanNode* leftChild = NULL, HuffmanNode* rightChild = NULL)
        : symbol(symbol), frequency(frequency), leftChild(leftChild), rightChild(rightChild) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* node1, HuffmanNode* node2) {
        return (node1->frequency > node2->frequency);
    }
};

void displayHuffmanCodes(HuffmanNode* rootNode, string code) {
    if (!rootNode)
        return;
    if (rootNode->symbol != '$')
        cout << code << " ";
    displayHuffmanCodes(rootNode->leftChild, code + "0");
    displayHuffmanCodes(rootNode->rightChild, code + "1");
}

void generateHuffmanCodes(char symbols[], int frequencies[], int arraySize) {
    HuffmanNode *leftNode, *rightNode, *topNode;
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> huffmanTree;

    for (int i = 0; i < arraySize; ++i)
        huffmanTree.push(new HuffmanNode(symbols[i], frequencies[i]));

    while (huffmanTree.size() != 1) {
        leftNode = huffmanTree.top();
        huffmanTree.pop();
        rightNode = huffmanTree.top();
        huffmanTree.pop();
        topNode = new HuffmanNode('$', leftNode->frequency + rightNode->frequency, leftNode, rightNode);
        huffmanTree.push(topNode);
    }
    displayHuffmanCodes(huffmanTree.top(), "");
}

int main() {
    char symbols[6];
    int frequencies[6];
    int size = sizeof(symbols) / sizeof(symbols[0]);

    cout << "Enter 6 characters: ";
    for(int i=0; i<6; i++) {
        cin >> symbols[i];
    }

    cout << "Enter their corresponding frequencies: ";
    for(int i=0; i<6; i++) {
        cin >> frequencies[i];
    }

    generateHuffmanCodes(symbols, frequencies, size);
    return 0;
}
