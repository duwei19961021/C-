#include <iostream>
using namespace std;

// 电脑配件：cpu、gpu、内存、鼠标......
class CPU
{
public:
	virtual void calculate() = 0;
};

class GPU
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Mouse
{
public:
	virtual void move() = 0;
};

// 由厂商类去实现配件
class IntelCPU: public CPU
{
public:
	void calculate()
	{
		cout << "Intel CPU start work!" << endl;
	}
};

class AmdGpu: public GPU
{
public:
	void display()
	{
		cout << "AMD GPU start work!" << endl;
	}
};

class LenovoMemory: public Memory
{
public:
	void storage()
	{
		cout << "Lenovo Memory start work!" << endl;
	}
};

class LogitechMouse: public Mouse
{
public:
	void move()
	{
		cout << "Logitech Mouse start work!" << endl;
	}
};

// 实现电脑类
class Computer
{
public:
	Computer(CPU *cpu, GPU *gpu, Memory *mem, Mouse *mse)
	{
		this->cpu = cpu;
		this->gpu = gpu;
		this->mem = mem;
		this->mse = mse;
	}

	~Computer()
	{
		if(this->cpu!=NULL)
		{
			delete this->cpu;
			this->cpu = NULL;
		}

		if(this->gpu!=NULL)
		{
			delete this->gpu;
			this->gpu = NULL;
		}

		if(this->mem!=NULL)
		{
			delete this->mem;
			this->mem = NULL;
		}

		if(this->mse!=NULL)
		{
			delete this->mse;
			this->mse = NULL;
		}
	}

	void StartWork()
	{
		cpu->calculate();
		gpu->display();
		mem->storage();
		mse->move();
	}
// 电脑的私有配件
private:
	CPU *cpu;
	GPU *gpu;
	Memory *mem;
	Mouse *mse;
};

void test01()
{
	CPU * intelCpu = new IntelCPU;
	GPU * amdGpu = new AmdGpu;
	Memory *lenovoMemory = new LenovoMemory;
	Mouse *logitechMouse = new LogitechMouse;

	Computer *computer = new Computer(intelCpu,amdGpu,lenovoMemory,logitechMouse);
	computer->StartWork();
	delete computer;
}

int main()
{
	test01();
	return 0;
}
