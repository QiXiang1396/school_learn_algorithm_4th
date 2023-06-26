#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include "BinaryTree.h"
#include"testFunction.h"
using namespace std;

void TEST()
{
    BinaryTree tree;

    //ͨ���������������
     tree.CreateBinTree("A(B(C(D,E)),15,M(N,O(P(Q,R),S(T,),I(J(K,L)))),U(V,W(X,Y(Z))))#"); //input: A(B(D,E(G,)),C(,F))#
     tree.printTree();
     //tree.PrintBinTree();  //print: A(B(D,E(G,)),C(,F))
     //cout << endl;

    //ͨ��ǰ���������������
    //tree.CreateBinTree_PreOrder("ABD##EG###C#F##"); // input: ABD##EG###C#F##
    // tree.PrintBinTree();           // print: A(B(D,E(G,)),C(,F))

    //ʹ��ǰ������������������������
    //tree.CreateBinTreeBy_Pre_In("ABDEGCF", "DBGEACF");
    //tree.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))
    //cout << endl;

    ////ʹ�ú�������������������������
    //tree.CreateBinTreeBy_Post_In("DGEBFCA", "DBGEACF");
    //tree.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))
    // cout << endl;

    ////���������������(�ݹ�)
    // tree.PreOrder(); // print: A B D E G C F
    // cout << endl;

    ////���������������(�ݹ�)
    // tree.InOrder(); // print: D B G E A C F
    // cout << endl;

    ////�������ĺ������(�ݹ�)
    // tree.PostOrder(); // print: D G E B F C A
    // cout << endl;

    //�������������(�ǵݹ�1)
    // tree.PreOrder_NoRecurve1(); // print: A B D E G C F

    //�������������(�ǵݹ�2)
    // tree.PreOrder_NoRecurve2(); // print: A B D E G C F

    //�������(�ǵݹ�)
    // tree.InOrder_NoRecurve(); // print: D B G E A C F

    //�������ĺ������(�ǵݹ�)
    // tree.PostOrder_NoRecurve(); // print: D G E B F C A

    //�������Ĳ�α���(�ǵݹ�)
    // tree.LevelOrder(); // print: A B C D E F G

    //��������Size
    // cout << tree.Size() << endl; // print: 7

    //������������
    // tree.Destroy();
    // cout << tree.Size() << endl; // print: 0
    //�������Ƿ�Ϊ��
    // cout << tree.Empty() << endl; // print: 1

    //�������ĸ߶�
    // cout << tree.Height() << endl; // print: 4

    //����������
    // BinaryTree<char> tree2 = tree;
    // tree2.PrintBinTree(); // print: A(B(D,E(G,)),C(,F))

    //�ж����Ŷ������Ƿ����
    // cout << (tree2 == tree) << endl; // print: 1

    //��ת������
    // tree2.InvertTree();
    // tree2.PrintBinTree(); //print: A(C(F,),B(E(,G),D))
}

bool cmp(pair<BinTreeNode*, int>& l, pair<BinTreeNode*, int>& r)
{
    // ���value��ȣ��Ƚ�keyֵ
    if (l.second == r.second)
        return l.first->data < r.first->data;
    else
        // ����Ƚ�valueֵ
        return  l.second < r.second;
}


void test37_38_40()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    cout << "�ڵ����Ϊ��" << count_nodes(&tree) << endl;
    cout << "Ҷ�ӽڵ����Ϊ��" << count_leaf_nodes(&tree) << endl;
    cout << "���ĸ߶�Ϊ��" << tree_depth(&tree) << endl;
}
void test39()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    ListNode* ans = connect_leaf_nodes(&tree),
        * p=ans;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}
void test41()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    map<BinTreeNode*, int> a = node_levels1(&tree);
    vector<pair<BinTreeNode*, int>> vec{};
    for (auto& n : a)
        vec.emplace_back(n);

    sort(vec.begin(), vec.begin(), cmp);

    for (auto& n : vec)
        cout << n.first->data << ' ' << n.second << endl;

}
void test42()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    vector<vector<char>> ans = level_order_traversal(&tree);
    for (auto& a : ans)
    {
        for (auto& b : a)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
}
void test43()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();
    swap_subtrees(&tree);
    tree.printTree();
}
void test44()
{
    BinaryTree tree;
    tree.CreateBinTree("A(B(D(X,Y(,Z)),E(G,)),C(G(H,I(J(K,O),)),F))#");
    tree.printTree();

    vector<BinTreeNode*> ans = find_ancestors(&tree, 'O');
    vector<BinTreeNode*> ans1 = find_ancestors(&tree, 'K');
    cout << "O��������ڵ㣺";
    for (auto& n : ans)
    {
        cout << n->data << ' ';
    }
    cout << "\nk��������ڵ㣺";
    for (auto& n : ans1)
    {
        cout << n->data << ' ';
    }
    cout << endl;
}

int main()
{
    test44();

    return 0;
}
