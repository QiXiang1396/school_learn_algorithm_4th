#include "BinaryTree.h"

//ʹ�ù����������������, ��'#'�ַ��������
void BinaryTree::CreateBinTree(const string& str)
{
    stack<BinTreeNode*> s;
    BinTreeNode* BT = nullptr;
    BinTreeNode* p{}, * t{}; //p������ס��ǰ�����Ľڵ㣬t������סջ����Ԫ��
    int k = 0, i = 0;

    while (str[i] != RefValue)
    {
        switch (str[i])
        {
        case '(': 
            s.push(p);
            k = 1;
            break;

        case ')': 
            s.pop();
            break;

        case ',':
            k = 2;
            break;

        default:
            p = new BinTreeNode(str[i]); //����һ�����
            if (BT == nullptr)
            {
                BT = p;
            }
            else if (k == 1) //������
            {
                t = s.top();                
                t->leftChild = p;
            }
            else //���Һ���
            {
                t = s.top();
                t->rightChild = p;
            } 
        }
        ++i;
    }
    this->root = BT;
}

//����������(������֪�Ķ�������ǰ���������)��'#'��ʾ�ս��
void BinaryTree::CreateBinTree_PreOrder(const string& s, BinTreeNode*& subTree)
{
    static int i=-1;
    if (i < s.size() || i<0)
    ++i;
        if (s[i] != RefValue)
        {
            subTree = new BinTreeNode(s[i]); //������
            if (subTree == nullptr)
            {
                cout << "�ռ�������" << endl;
                exit(1);
            }
            CreateBinTree_PreOrder(s, subTree->leftChild);  //�ݹ鴴��������
            CreateBinTree_PreOrder(s, subTree->rightChild); //�ݹ鴴��������
        }
        else
        {
            subTree = nullptr;
        }
}

//ʹ����������������������������
void BinaryTree::CreateBinTreeBy_Pre_In(BinTreeNode*& cur, const char* pre, const char* in, int n)
{
    if (n <= 0)
    {
        cur = nullptr;
        return;
    }
    int k = 0;
    while (pre[0] != in[k]) //���������ҵ�pre[0]��ֵ
    {
        k++;
    }
    cur = new BinTreeNode(in[k]); //�������
    CreateBinTreeBy_Pre_In(cur->leftChild, pre + 1, in, k);
    CreateBinTreeBy_Pre_In(cur->rightChild, pre + k + 1, in + k + 1, n - k - 1);
}

//ʹ�ú�������������������������
void BinaryTree::CreateBinTreeBy_Post_In(BinTreeNode*& cur, const char* post, const char* in, int n)
{
    if (n == 0)
    {
        cur = nullptr;
        return;
    }

    char r = *(post + n - 1);    //�����ֵ
    cur = new BinTreeNode(r); //���쵱ǰ���

    int k = 0;
    const char* p = in;
    while (*p != r)
    {
        k++;
        p++;
    }
    CreateBinTreeBy_Post_In(cur->leftChild, post, in, k);
    CreateBinTreeBy_Post_In(cur->rightChild, post + k, p + 1, n - k - 1);
}

//�������ı���(�ݹ�)
void BinaryTree::PreOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        cout << subTree->data << " ";
        PreOrder(subTree->leftChild);
        PreOrder(subTree->rightChild);
    }
}
void BinaryTree::InOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        InOrder(subTree->leftChild);
        cout << subTree->data << " ";
        InOrder(subTree->rightChild);
    }
}
void BinaryTree::PostOrder(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        PostOrder(subTree->leftChild);
        PostOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

//�������������(�ǵݹ�1)
void BinaryTree::PreOrder_NoRecurve1(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    S.push(nullptr); //����pushһ��nullptr�������һ�����û����������ʱ��ջ��ֻ��һ��nullptr�ˣ���ָ��pָ�����nullptr�����жϾͻ����ѭ��
    while (p != nullptr)
    {
        cout << p->data << " ";
        if (p->rightChild != nullptr) //Ԥ��������ָ����ջ��
        {
            S.push(p->rightChild);
        }

        if (p->leftChild != nullptr) //��������
        {
            p = p->leftChild;
        }
        else //������Ϊ��
        {
            p = S.top();
            S.pop();
        }
    }
}

//�������������(�ǵݹ�2)
void BinaryTree::PreOrder_NoRecurve2(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    BinTreeNode* t;
    S.push(p);         //���ڵ��ջ
    while (!S.empty()) //��ջ��Ϊ��
    {
        t = S.top(); //p�ȼ�סջ��Ԫ�أ�Ȼ��ջ����ջ
        S.pop();
        cout << t->data << " ";    //����Ԫ��
        if (t->rightChild != nullptr) //�Һ��Ӳ�Ϊ�գ��Һ��ӽ�ջ
        {
            S.push(t->rightChild);
        }
        if (t->leftChild != nullptr) //���Ӳ�Ϊ�գ����ӽ�ջ
        {
            S.push(t->leftChild);
        }
    }
}

//���������������(�ǵݹ�)
void BinaryTree::InOrder_NoRecurve(BinTreeNode* p)
{
    stack<BinTreeNode*> S;
    do
    {
        while (p != nullptr)
        {
            S.push(p);
            p = p->leftChild;
        }
        if (!S.empty())
        {
            p = S.top();
            S.pop();
            cout << p->data << " ";
            p = p->rightChild;
        }
    } while (p != nullptr || !S.empty());
}

//�������ĺ������(�ǵݹ�)
void BinaryTree::PostOrder_NoRecurve(BinTreeNode* p)
{
    if (root == nullptr)
        return;
    stack<BinTreeNode*> s;
    s.push(p);
    BinTreeNode* lastPop = nullptr;
    while (!s.empty())
    {
        while (s.top()->leftChild != nullptr)
            s.push(s.top()->leftChild);
        while (!s.empty())
        {
            //��Ҷ�ӽ�� || û���ҽ��
            if (lastPop == s.top()->rightChild || s.top()->rightChild == nullptr)
            {
                cout << s.top()->data << " ";
                lastPop = s.top();
                s.pop();
            }
            else if (s.top()->rightChild != nullptr)
            {
                s.push(s.top()->rightChild);
                break;
            }
        }
    }
}

//�������Ĳ�α���(�ǵݹ����)
void BinaryTree::LevelOrder(BinTreeNode* p)
{
    queue<BinTreeNode*> Q;
    Q.push(p); //���ڵ����
    BinTreeNode* t;
    while (!Q.empty())
    {
        t = Q.front(); //t�ȼ�ס��ͷ,�ٽ���ͷ����
        Q.pop();
        cout << t->data << " "; //���ʶ�ͷԪ�ص�����

        if (t->leftChild != nullptr)
        {
            Q.push(t->leftChild);
        }

        if (t->rightChild != nullptr)
        {
            Q.push(t->rightChild);
        }
    }
}

//�ӽ��subTree��ʼ���������current�ĸ��ڵ�,�ҵ����ظ��ڵ�ĵ�ַ���Ҳ�������nullptr
BinTreeNode* BinaryTree::Parent(BinTreeNode* subTree, BinTreeNode* current)
{
    if (subTree == nullptr)
    {
        return nullptr;
    }
    if (subTree->leftChild == current || subTree->rightChild == current) //����ҵ������ظ��ڵ�subTree
    {
        return subTree;
    }
    BinTreeNode* p;
    if ((p = Parent(subTree->leftChild, current)) != nullptr) //�ݹ���������������
    {
        return p;
    }
    else
    {
        return Parent(subTree->rightChild, current); //�ݹ�������������
    }
}

//������������
void BinaryTree::Destroy(BinTreeNode*& subTree)
{
    if (subTree != nullptr)
    {
        Destroy(subTree->leftChild);
        Destroy(subTree->rightChild);
        delete subTree;
        subTree = nullptr;
    }
}

//���ƶ�����������һ��ָ�룬����һ����originNodeΪ�����ƵĶ������ĸ���
BinTreeNode* BinaryTree::Copy(BinTreeNode* originNode)
{
    if (originNode == nullptr)
    {
        return nullptr;
    }
    BinTreeNode* temp = new BinTreeNode; //���������
    temp->data = originNode->data;
    temp->leftChild = Copy(originNode->leftChild);
    temp->rightChild = Copy(originNode->rightChild);
    return temp;
}

//�ж����Ŷ������Ƿ����
bool BinaryTree::equal(BinTreeNode* a, BinTreeNode* b)
{
    if (a == nullptr && b == nullptr) //���߶�Ϊ��
    {
        return true;
    }
    if (a != nullptr && b != nullptr && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild)) //���߶���Ϊ�գ������ߵĽ��������ȣ������ߵ����������Ľ�㶼���
    {
        return true;
    }
    return false;
}

//�����������subTreeΪ���Ľ��ĸ���
int BinaryTree::Size(BinTreeNode* subTree) const
{
    if (subTree == nullptr) //�ݹ����������������Ϊ0
    {
        return 0;
    }
    return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

//�����������subTreeΪ���ĸ߶�
int BinaryTree::Height(BinTreeNode* subTree)
{
    if (subTree == nullptr) //�ݹ�����������߶�Ϊ0
    {
        return 0;
    }
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return i < j ? j + 1 : i + 1;
}


void BinaryTree::PrintBinTree(BinTreeNode* BT)
{
    if (BT != nullptr) //��Ϊ��ʱ�����ݹ�
    {
        cout << BT->data;
        if (BT->leftChild != nullptr || BT->rightChild != nullptr)
        {
            cout << '(';
            if (BT->leftChild != nullptr)
            {
                PrintBinTree(BT->leftChild);
            }
            cout << ',';
            if (BT->rightChild != nullptr)
            {
                PrintBinTree(BT->rightChild);
            }
            cout << ')';
        }
    }
}

//��ת������
void BinaryTree::InvertTree(BinTreeNode* originNode)
{
    if (originNode == nullptr)
        return;
    BinTreeNode* tempNode = originNode->leftChild;
    originNode->leftChild = originNode->rightChild;
    originNode->rightChild = tempNode;
    InvertTree(originNode->leftChild);
    InvertTree(originNode->rightChild);
}

void BinaryTree::printTree(BinTreeNode* root) {
    if (!root)return;
    auto tmp = root;
    std::vector<BinTreeNode*> intv = inorderTraversal(tmp);//��������ڵ�����
    std::string template_str;//ģ��string����ʾÿ�д�ӡstring�ĳ���
    int location = 0;
    std::unordered_map<BinTreeNode*, int> first_locations;//�洢�ڵ��Ӧ�ڱ���string�е���λ��
    for (auto& i : intv) {
        location = template_str.size();
        //template_str += std::to_string(i->data) + " ";
        template_str += i->data; template_str += " ";
        first_locations[i] = location;
    }
    for (auto& i : template_str)i = ' ';//��ģ��ȫ����Ϊ�ո񷽱����ʹ��
    //�������
    std::queue<BinTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        std::string tmp_str1 = template_str, tmp_str2 = template_str;//1Ϊ�ڵ������У�2Ϊ����һ��
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            cur_loc = first_locations[node];
            //std::string num_str = std::to_string(node->data);
            std::string num_str(1, node->data);
            //��ߣ�����������ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'/'���ڵ�һ�в���'_'
            if (node->leftChild) {
                q.push(node->leftChild);
                int first_loc = first_locations[node->leftChild] + 1;
                tmp_str2[first_loc++] = '/';
                while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

            }
            //�м�,��Ӧλ�ô�ӡ�ڵ�ֵ���п���Ϊ��λ����
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //�ұߣ���������Һ��ӣ���ô�ڵڶ��ж�Ӧλ�ô�ӡ'\'���ڵ�һ�в���'_'
            if (node->rightChild) {
                q.push(node->rightChild);
                int last_loc = first_locations[node->rightChild] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //��ӡ����
        std::cout << tmp_str1 << std::endl;
        std::cout << tmp_str2 << std::endl;
    }
}











