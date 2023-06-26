#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include<iomanip>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
//������������Ͷ���
struct BinTreeNode
{
    char data;
    BinTreeNode* leftChild, * rightChild;
    BinTreeNode(char x = 0, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr) : 
        data(x), leftChild(l), rightChild(r) {}
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr), RefValue('#') {}
    BinaryTree(int value) : root(nullptr), RefValue(value) {}
    ~BinaryTree() { Destroy(root); }
    BinaryTree(BinaryTree& s) { root = Copy(s.getRoot()); }    //����������(ǰ�������Ӧ��)

    //ʹ�ù����������������'#'�ַ��������
    void CreateBinTree(const string& s);

    //ǰ���������������(ǰ�������Ӧ��)����#��ʾ�ս��
    void CreateBinTree_PreOrder(const string& s) { CreateBinTree_PreOrder(s,root); }
    void CreateBinTree_PreOrder(const string & s, BinTreeNode*& subTree);

    //ʹ����������������������������
    void CreateBinTreeBy_Pre_In(const char* pre, const char* in) 
    { CreateBinTreeBy_Pre_In(root, pre, in, strlen(pre)); };

    //ʹ�ú�������������������������
    void CreateBinTreeBy_Post_In(const char* post, const char* in) 
    { CreateBinTreeBy_Post_In(root, post, in, strlen(post)); };

    //�ݹ飺�������򣬺���
    void PreOrder() { PreOrder(root); }
    void InOrder() { InOrder(root); }
    void PostOrder() { PostOrder(root); }

    //�������(�ǵݹ�1)
    void PreOrder_NoRecurve1() { PreOrder_NoRecurve1(root); }
    //�������(�ǵݹ�2)
    void PreOrder_NoRecurve2() { PreOrder_NoRecurve2(root); }
    //�������(�ǵݹ�)
    void InOrder_NoRecurve() { InOrder_NoRecurve(root); }
    //�������(�ǵݹ�)
    void PostOrder_NoRecurve() { PostOrder_NoRecurve(root); }
    //��α���(�ǵݹ�)
    void LevelOrder() { LevelOrder(root); }

    //��ȡ�������ĸ��ڵ�
    BinTreeNode* getRoot() const 
    { return root; }

    //��ȡcurrent���ĸ��ڵ�
    BinTreeNode* Parent(BinTreeNode* current) 
    { return (root == nullptr || root == current) ? nullptr : Parent(root, current); } //���û�и��ڵ��current������root��㣬��û�и��ڵ�
    
    //��ȡcurrent��������
    BinTreeNode* LeftChild(BinTreeNode* current) 
    { return (current != nullptr) ? current->leftChild : nullptr; }
    
    //��ȡcurrent�����ҽ��
    BinTreeNode* RightChild(BinTreeNode* current) 
    { return (current != nullptr) ? current->rightChild : nullptr; }

    //���ٺ���
    void Destroy() { Destroy(root); };

    //�ж����Ŷ������Ƿ����(ǰ�������Ӧ��)
    bool operator==(BinaryTree& s) 
    { return (equal(this->getRoot(), s.getRoot())); }

    //����������Ľ��ĸ���(���������Ӧ��)
    int Size() { return Size(root); }

    //����������ĸ߶ȣ����������Ӧ�ã�
    int Height() { return Height(root); }

    //�ж϶������Ƿ�Ϊ��
    bool Empty() { return (root == nullptr) ? true : false; }

    //�Թ�������ʽ���������(ǰ�������Ӧ��)
    void PrintBinTree() { PrintBinTree(root); }

    //��ת������
    void InvertTree() { InvertTree(root); }

    //��΢���ӻ��Ĺۿ�
    void printTreeInP() 
    { printTreeInP(root); }
    void printTreeInP(BinTreeNode* root, int indent = 0) {
        if (root == nullptr) return;
        printTreeInP(root->rightChild, indent + 4);
        if (indent != 0) {
            cout << setw(indent) << " ";
            cout << "+---";
        }
        cout << root->data << endl;
        printTreeInP(root->leftChild, indent + 4);
    }

    //��ǿ�Ŀ��ӻ�
    std::vector<BinTreeNode*> inorderTraversal(BinTreeNode* root) {
        std::vector<BinTreeNode*> res;
        std::stack<BinTreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->leftChild;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root);
            root = root->rightChild;
        }
        return res;
    }
    void printTree()
    {
        printTree(root);
    }
    void printTree(BinTreeNode* root);









protected:
    void CreateBinTreeBy_Pre_In(BinTreeNode*& cur, const char* pre, const char* in, int n);
    void CreateBinTreeBy_Post_In(BinTreeNode*& cur, const char* post, const char* in, int n);
   
    void PreOrder(BinTreeNode*& subTree);
    void InOrder(BinTreeNode*& subTree);
    void PostOrder(BinTreeNode*& subTree);
    void PreOrder_NoRecurve1(BinTreeNode* p);
    void PreOrder_NoRecurve2(BinTreeNode* p);
    void InOrder_NoRecurve(BinTreeNode* p);
    void PostOrder_NoRecurve(BinTreeNode* p);
    void LevelOrder(BinTreeNode* p);


    BinTreeNode* Parent(BinTreeNode* subTree, BinTreeNode* current);
    void Destroy(BinTreeNode*& subTree);
    BinTreeNode* Copy(BinTreeNode* originNode);
    bool equal(BinTreeNode* a, BinTreeNode* b);
    int Size(BinTreeNode* subTree) const;
    int Height(BinTreeNode* subTree);

    //�Թ�������ʽ���������
    void PrintBinTree(BinTreeNode* BT);  
    void InvertTree(BinTreeNode* originNode);

 
private:
    BinTreeNode* root;
    int RefValue = 0;           //��������ֹͣ�ı�־����Ҫһ�����캯��
};

