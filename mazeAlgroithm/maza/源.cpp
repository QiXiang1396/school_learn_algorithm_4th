#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // ��ǰλ���ĸ������ƫ����
vector<pair<int, int>> path; // ���ҵ���·��
vector<vector<int>> maze = { 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


void mark(vector<vector<int>>& maze, pair<int, int> pos) { // ���Թ�maze��λ��pos��"2"��ʾ�������ˡ�
    maze[pos.first][pos.second] = 2;
}

bool passable(vector<vector<int>>& maze, pair<int, int> pos) { // ����Թ�maze��λ��pos�Ƿ��ͨ��
    return maze[pos.first][pos.second] == 0;
}

bool find_path_recursion(vector<vector<int>>& maze, pair<int, int> pos, pair<int, int> end) {
    mark(maze, pos);
    if (pos == end) {
        cout <<"(" << pos.first << " " << pos.second << ") ";
        path.push_back(pos);
        return true;
    }
    for (int i = 0; i < 4; i++) { // �����ĸ�����˳����
        pair<int, int> nextp = { pos.first + dirs[i].first, pos.second + dirs[i].second };
        // ������һ�����ܷ���
        if (passable(maze, nextp)) { // �����е�����λ�ò���
            if (find_path_recursion(maze, nextp, end)) { // �����nextp�ɴ���ڣ�������λ�ã��ɹ�����
                cout << "(" << pos.first << " " << pos.second << ") ";
                path.push_back(pos);
                return true;
            }
        }
    }
    return false;
}

/*
\033 �� ASCII ת���ַ��������ڿ�ʼһ��ת�����У��������������ն����ı�����ɫ���������ԡ�
����δ����У�\033 ������� [ ��һϵ���� ; �ָ������֣���Щ���ִ���ͬ�����ԡ�
0 ��������������ΪĬ��ֵ��
31 �Ὣǰ��ɫ����Ϊ��ɫ��
32 �Ὣǰ��ɫ����Ϊ��ɫ��
34 �Ὣǰ��ɫ����Ϊ��ɫ��
40 �Ὣ����ɫ����Ϊ��ɫ��
����ĩβ�� m ��ʾ����һ����ѡ��ͼ�����֡���SGR�����У�����������ʾ���ԣ�����ɫ���ı���ʽ��*/
void see_path(vector<vector<int>>& maze, vector<pair<int, int>> path) { // ʹѰ�ҵ���·�����ӻ�
    for (int i = 0; i < path.size(); i++) {
        if (i == 0) {
            maze[path[i].first][path[i].second] = 'E';
        }
        else if (i == path.size() - 1) {
            maze[path[i].first][path[i].second] = 'S';
        }
        else {
            maze[path[i].first][path[i].second] = 3;
        }
    }
    cout << "\n";
    for (auto r : maze) {
        for (auto c : r) {
            if (c == 3) {
                cout  << "\033[0;300m" << "*" << " " << '\033' << "[0m";
            }
            else if (c == 'S' || c == 'E') {
                cout <<  "\033[0;34m" << char(c) << " " << '\033' << "[0m";
            }
            else if (c == 2) {
                cout  << "\033[0;32m" << "#" << " " << '\033' << "[0m";
            }
            else if (c == 1) {
                cout  << "\033[1;43m" << "  " << '\033' << "[0m";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void print_path(pair<int, int> end, pair<int, int> start, pair<int, int> pos, stack<pair<pair<int, int>, int>> st) {

    cout << end.first << " " << end.second << endl;
    while (!st.empty()) {
        cout << st.top().first.first << " " << st.top().first.second << endl;
        maze[st.top().first.first][st.top().first.second] = 3;
        st.pop();
    }
    maze[pos.first][pos.second] = 3;
    maze[start.first][start.second] = 'S';
    maze[end.first][end.second] = 'E';
}

void find_path_back(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    if (start == end) {
        cout << start.first << " " << start.second << endl;
        return;
    }
    stack<pair<pair<int, int>, int>> st;
    mark(maze, start);
    st.push(make_pair(start, 0));
    while (!st.empty()) {
        pair<pair<int, int>, int> temp = st.top();
        pair<int, int> pos = temp.first;
        int nxt = temp.second;
        st.pop();
        for (int i = nxt;i < 4;i++) {
            pair<int, int> nextp = { pos.first + dirs[i].first,pos.second + dirs[i].second };
            if (nextp == end) {
                print_path(end, start, pos, st);
                return;
            }
            if (passable(maze, nextp)) {
                st.push(make_pair(pos, i + 1));
                mark(maze, nextp);
                st.push(make_pair(nextp, 0));
                break;
            }
        }
    }
    cout << "�Ҳ���·��" << endl;
}


void the_way_1() {
    pair<int, int> start{ 1,1 }, end{ 8,10 };
    find_path_recursion(maze, start, end);
    see_path(maze, path);
}
void the_way_2() {
    pair<int, int> start{ 1,1 }, end{ 8,10 };
    find_path_back(maze, start, end);
    see_path(maze, path);
}


int main() {
    the_way_1();
    return 0;
}