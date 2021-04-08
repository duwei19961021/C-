#include <cstring>
#include <cassert>

namespace duwei
{
	class string
	{
		public:
			typedef char* iterator;

			typedef const char* const_iterator;

			iterator begin()
			{
				return _str;
			}

			iterator end()
			{
				return _str + _size;
			}

			const_iterator cbegin() const
			{
				return _str;
			}

			const_iterator cend() const
			{
				return _str + _size;
			}

			string(const char* str)
			:_str(new char[strlen(str) + 1])
			 ,_size(strlen(str))
			 ,_capacity(strlen(str))
			{
				strcpy(_str, str);
			}

			void swap(string& s)
			{
				std::swap(_size,s._size);

				std::swap(_capacity, s._capacity);

				std::swap(_str, s._str); // 交换_str成员的指向就行了
			}

			string(const string& s)
			:_str(NULL)
			,_size(0)
			,_capacity(0)
			{
				string tmp(s.c_str());
				swap(tmp);
			}

			/*
			string(const duwei::string& s)
			{
				_str = new char[s._size+1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._size;
			}
			*/

			string& operator=(string& s)
			{
					
			}

			~string()
			{
				delete[] _str;
			}

			size_t size()
			{
				return _size;
			}

			size_t capacity()
			{
				return _capacity;
			}

			char& operator[](size_t i)
			{
				assert(i < _size);
				return _str[i];
			}

			const char* c_str() const
			{
				return _str;
			}

			void reserve(size_t n)
			{
				if(n > _capacity)
				{
					char* tmp = new char[n];
					strncpy(tmp,_str,strlen(_str) + 1);	
					delete[] _str;
					_str = tmp;
					_capacity = n;
				}
			}

			void check_capacity()
			{
				if(_size == _capacity)
				{
					size_t n = _capacity == 0 ? 8:_capacity * 2;
					reserve(n);	
				}
			}

			void resize(size_t n, char ch = '\0')
			{
				if(n < _size)
				{
					_str[n] = '\0';
					_size = n;
				}
				else
				{
					if(n > _capacity)
					{
						reserve(n);
					}

					for(size_t i = _size; i < n; i++)
					{
						_str[i] = ch;
					}
					
					_str[n] = '\0';

					_size = n;
				}
			}

			void push_back(char c)
			{
				check_capacity();

				_str[_size] = c;

				_size++;	
			}
			void insert(size_t pos, char x)
			{
				assert(pos <= _size);

				if(_size == _capacity)
				{
					reserve(_capacity * 2);
				}

				size_t end = _size+1;

				while(end > pos)
				{
					_str[end] = _str[end-1];
					end--;
				}

				_str[pos] = x;

				_size++;	
			}
		private:
			char* _str;
			size_t _size;
			size_t _capacity;
	};
}
