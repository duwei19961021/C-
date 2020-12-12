#include <iostream>
using namespace std;

class Cube
{
public:
	void setCube(int length,int width,int heigh)
	{
		m_L = length;
		m_W = width;
		m_H = heigh;
	}

	int getL()
	{
		return m_L;
	}

	int getW()
	{
		return m_W;
	}

	int getH()
	{
		return m_H;
	}

	int calculateArea()
	{
		return 2*(m_H*m_L + m_H*m_W + m_L*m_W);
	}

	int calculateVolume()
	{
		return m_H * m_L * m_W;
	}
private:
	int m_L;
	int m_W;
	int m_H;
};

int main()
{
	Cube c1;
	c1.setCube(10,10,10);
	
	cout << "面积 = " << c1.calculateArea() << endl;
	cout << "体积 = " << c1.calculateVolume() << endl;
	return 0;
}
