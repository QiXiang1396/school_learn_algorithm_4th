#include "ChessBoard.h"
#include <iomanip>
ChessBoard::ChessBoard()
{
	m_board = vector<vector<int>> (10,vector<int>(9));
	initialization();
}

void ChessBoard::test_print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << std::setw(4) << m_board[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
}

/*
* y
* 11
* ...    ����Ϊx�ᣬyΪ���ᣬ����
* 2      ��0��1������
* 1
* 0  1  2  ... 11 x
*/
void ChessBoard::initialization()
{
	//��������˧12345
	for (int i{ 0 }; i < 5; ++i)
	{
		m_board[0][i] = i;//�������
		m_board[0][8 - static_cast<std::vector<int, std::allocator<int>>::size_type>(i)] = i;//�������
		m_board[9][i] = i * 2;//�����Ҳ�
		m_board[9][8 - static_cast<std::vector<int, std::allocator<int>>::size_type>(i)] = i * 2;//�����Ҳ�
	}

	//С�� = 7
	for (int i{ 0 }; i < 5; ++i)
	{
		m_board[3][static_cast<std::vector<int, std::allocator<int>>::size_type>(i) * 2] = 7;//����
		m_board[6][static_cast<std::vector<int, std::allocator<int>>::size_type>(i) * 2] = 7 * 2;  //����
	}

	//�� = 6
	m_board[2][1] = 6;
	m_board[7][1] = 6 * 2;
	m_board[2][7] = 6;
	m_board[7][7] = 6 * 2;
}
