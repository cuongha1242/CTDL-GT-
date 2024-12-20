#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Node đại diện cho một mục trong cuốn sách
struct Node {
    string title;             // Tiêu đề của mục
    int pages;                // Số trang của mục
    vector<Node*> children;   // Danh sách các mục con

    // Constructor
    Node(string t, int p) : title(t), pages(p) {}
};

// Hàm đệ quy để đếm số chương (node gốc cấp 1)
int countChapters(Node* root) {
    if (!root) return 0;
    return root->children.size();
}

// Hàm đệ quy tìm chương dài nhất (dựa trên số trang)
Node* findLongestChapter(Node* root) {
    if (!root || root->children.empty()) return nullptr;

    Node* longestChapter = nullptr;
    int maxPages = 0;

    for (Node* child : root->children) {
        if (child->pages > maxPages) {
            maxPages = child->pages;
            longestChapter = child;
        }
    }
    return longestChapter;
}

// Hàm đệ quy tìm và xoá một mục trong cây
bool deleteNode(Node* root, const string& target) {
    if (!root) return false;

    // Duyệt qua các mục con
    for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        if ((*it)->title == target) {
            // Xoá node tìm thấy
            delete* it;
            root->children.erase(it);
            return true;
        }
        else {
            // Tiếp tục tìm trong các mục con
            if (deleteNode(*it, target)) {
                return true;
            }
        }
    }
    return false;
}

// Hàm hiển thị cây (dạng đệ quy)
void displayTree(Node* root, int level = 0) {
    if (!root) return;

    // In tiêu đề với thụt lề theo cấp độ
    cout << string(level * 2, ' ') << root->title << " (" << root->pages << " pages)" << endl;

    for (Node* child : root->children) {
        displayTree(child, level + 1);
    }
}

// Hàm xoá toàn bộ cây (đệ quy)
void deleteTree(Node* root) {
    if (!root) return;

    for (Node* child : root->children) {
        deleteTree(child);
    }
    delete root;
}

int main() {
    // Tạo cây mục lục
    Node* book = new Node("Book Title", 0);

    // Thêm chương
    Node* chapter1 = new Node("Chapter 1", 50);
    Node* chapter2 = new Node("Chapter 2", 30);
    Node* chapter3 = new Node("Chapter 3", 70);

    book->children.push_back(chapter1);
    book->children.push_back(chapter2);
    book->children.push_back(chapter3);

    // Thêm mục con vào chương 1
    chapter1->children.push_back(new Node("Section 1.1", 20));
    chapter1->children.push_back(new Node("Section 1.2", 30));

    // Hiển thị cây mục lục
    cout << "Book Structure:" << endl;
    displayTree(book);

    // Đếm số chương
    cout << "\nNumber of chapters: " << countChapters(book) << endl;

    // Tìm chương dài nhất
    Node* longestChapter = findLongestChapter(book);
    if (longestChapter) {
        cout << "Longest chapter: " << longestChapter->title << " (" << longestChapter->pages << " pages)" << endl;
    }

    // Xoá một mục
    string target = "Chapter 2";
    if (deleteNode(book, target)) {
        cout << "\nAfter deleting '" << target << "':" << endl;
        displayTree(book);
    }
    else {
        cout << "\nTarget '" << target << "' not found." << endl;
    }

    // Xoá toàn bộ cây
    deleteTree(book);
    return 0;
}
