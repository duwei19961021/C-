#pragma once
#include <vector>
#include <cassert>

template<class T>
class Great
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};

template<class T>
class Less
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

namespace duwei
{
	template<class T, class Container = std::vector<T>, class Compare = Great<T> >
	class priority_queue
	{
	public:
		priority_queue() = default;

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		:_con(first, last)
		{
			for(int i = (_con.size() -1 -1)/2; i >= 0; i--)
			{
				AdJustUp(i);
			}

			/*
			for(int i = 1; i < _con.size(); i++)
			{
				AdJustDown(i);
			}
			*/	
		}

		void AdJustDown(int parent)
		{
			Compare com;
			int child = 2 * parent + 1;
			while(child < _con.size())
			{
				// if(child + 1 < _con.size() && _con[child + 1] > _con[child])
				if(child + 1 < _con.size() && com(_con[child], _con[child+1]))
				{
					child++;
				}

				// if(_con[child] > _con[parent])
				if(com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}

		void AdJustUp(int child)
		{
			Compare com;
			int parent = (child-1)/2;
			while(child > 0)
			{
				// if(_con[child] > _con[parent])
				if(com(_con[child], _con[parent]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1 -1)/2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);		
			AdJustUp(_con.size()-1);
		}
	
		void pop()
		{
			// assert(_con.size() > 0);
			std::swap(_con[0], _con[_con.size() -1]);
			_con.pop_back();
			AdJustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		int size()
		{
			return _con.size();
		}
		Container _con;
	};
}
