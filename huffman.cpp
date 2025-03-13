#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // Leaf node condition
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCode);
    generateHuffmanCodes(root->right, code + "1", huffmanCode);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printHuffmanCodes(unordered_map<char, string>& huffmanCode, string& input) {
    cout << "Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << "\n";
    }

    cout << "\nEncoded string is:\n";
    for (char ch : input) {
        cout << huffmanCode[ch];
    }
    cout << "\n";
}

void huffmanCoding(string input) {
    if (input.empty()) {
        cout << "Input string is empty. No Huffman encoding possible.\n";
        return;
    }

    unordered_map<char, int> freqMap;
    for (char ch : input) {
        freqMap[ch]++;
    }

    cout << "Character Frequencies:\n";
    for (auto pair : freqMap) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);
    printHuffmanCodes(huffmanCode, input);

    deleteTree(root);
}

int main() {
    string input = "aaabbbccccddddeeeeeeee";
    huffmanCoding(input);
    return 0;
}
