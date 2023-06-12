#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

struct dList
{
    int data;
    dList* prior;                     //ָ��ǰ����ָ��
    dList* next;                      //ָ���̵�ָ��
};


void dlistReverse(dList* head)                        //ѭ��˫����ĵ���
{
    dList* p = head->next,
        * q = head->prior;
    //p��q���غϲ��Ҳ�����
    while (q != p && p->prior != q)
    {
        //�������ڵ������Ԫ��
        int t; t = p->data;
        p->data = q->data;
        q->data = t;
        //pָ���ͷ��β������qָ���β��ͷ����
        p = p->next;
        q = q->prior;
    }
}

void add_dList(dList* head, int n)
{
    dList* p = head->next;
    dList* newNode = new dList{ n, nullptr, head };
    do
    {
        p = p->next;
    }while (p->next != head);

    p->next = newNode;
    newNode->prior = p;
    head->prior = newNode;
}

void printNode(dList* head)
{
    dList* p = head;
    while (p->next != head)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << p->data << ' ';
    cout << endl;
}

int main()
{
    dList* l = new dList;
    l->data = 0;
    l->next = l;
    l->prior = l;
    for (int i = 1; i < 6; i++)
        add_dList(l, i * 2);
   printNode(l);

   dlistReverse(l);

   printNode(l);
}
