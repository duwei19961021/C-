#pragma once
#include <cassert>
#include <cstring>
#include <cstddef>

namespace duwei
{
	template<class T>
	class vector
	{
	public: typedef T* iterator;
		vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endofstorage(nullptr)
		{}
		~vector() {
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}

		size_t size()
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if(n > capacity())
			{
				size_t old_size = size();

				T* tmp = new T[n];

				memcpy(tmp, _start, sizeof(T) * size());	

				delete[] _start;

				_start = tmp;

				_finish = _start + old_size;
				/*
				 * _finish = _start + size()
				 * 这么写时错误的，size()的计算方法是_finish-_start，
				 * 而上一步已经修改了_start的指向，因此size()计算出来的结果是错误的
				 */

				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if(n > capacity())
			{
				reserve(n);
			}
			
			if(n < size())
			{ _finish = _start + n;
			}
			else
			{
				while(_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		
		void check_capacity()
		{
			if(_finish == _endofstorage)
			{
				size_t new_capacity = capacity() == 0 ? 4:capacity()*2;
				reserve(new_capacity);
			}
		}
		void push_back(const T& x)
		{
			check_capacity();
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;	
		}
		
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			size_t i = pos - _start;
			/*
			 * 如果发生扩容，那么pos指向的还是之前的内存地址，
			 * 并没有指向新开辟空间的pos位置，会失效
			 */
			
			check_capacity();

			pos = _start + i;

			iterator end = _finish - 1;

			while(end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;

			++_finish;

			return _finish;
		}

		iterator erase(iterator pos)
		{
			/*
			 * 如果删除的是最后一个元素，
			 * _finish会往前挪动一个位置，
			 * 而pos的位置没有改变，
			 * 指向_finish之后的位置。
			 */
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while(it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}
