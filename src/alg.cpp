// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) return;
    std::string curWord;
    char ch;
    while (in.get(ch)) {
        if (ch >= 0 && ch <= 127 && std::isalpha(static_cast<unsigned char>(ch))) {
            curWord.push_back(std::tolower(static_cast<unsigned char>(ch)));
        } else {
            if (!curWord.empty()) {
                tree.add(curWord);
                curWord.clear();
            }
        }
    }
    if (!curWord.empty()) {
        tree.add(curWord);
    }
    in.close();
}

void printFreq(BST<std::string>& container) {
    auto items = container.getNodesByFrequency();
    std::ofstream out("freq.txt");
    for (auto* node : items) {
        std::string line = node->key + " " + std::to_string(node->freq);
        std::cout << line << '\n';
        if (out) out << line << '\n';
    }
    out.close();
}
