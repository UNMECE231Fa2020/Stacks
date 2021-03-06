#include <iostream>

template <typename S>
class Stack {
	private:
		size_t _size;
		S *_data;
	public:
		Stack() : _size{0}, _data{nullptr} {

		}

		Stack(S value) : _size{1} {
			_data = new S(value);
		}

		Stack(const Stack &s) {
			if (s.empty()) {
				_size = 0;
				_data = nullptr;
			}
			else {
				size_t s_size = s.size();
				S *s_data_copy = new S[s_size];
				size_t i;
				for (i = 0; i < s_size; i++) {
					*(s_data_copy + i) = *(s._data + i);
				}
				if (s_size == 1) {
					_data = new S(*s_data_copy);

				}
				else {
					_data = new S[s_size];
					for (i = 0; i < s_size; i++) {
						*(_data + i) = *(s_data_copy + i);
					}
				}
				_size = s_size;
				delete [] s_data_copy;
			}
		}

		~Stack() {
			if ((size() < 2) && (_data != nullptr)) {
				delete _data;
			}
			else {
				delete [] _data;
			}
		}

		size_t size() const {
			return _size;
		}

		S top() const {
			return *(_data + size() - 1);
		}

		void push(S value) {
			if (empty()) {
				_data = new S(value);
				_size = 1;
			}
			else {
				size_t data_size = size();
				S *data_copy = new S[data_size];
				size_t i;
				for (i = 0; i < data_size; i++) {
					*(data_copy + i) = *(_data + i);
				}

				delete [] _data;
				_data = new S[data_size + 1];
				for (i = 0; i < data_size; i++) {
					*(_data + i) = *(data_copy + i);
				}
				*(_data + i) = value;
				_size += 1;
				delete [] data_copy;
			}
		}

		void pop() {
			if (empty()) {
				std::cout << "Stack is empty!\n";
				return;
			}
			else if (size() == 1) {
				_size = 0;
				delete _data;
				_data = nullptr;
			}
			else {
				size_t data_size = size();
				S *data_copy = new S[data_size-1];
				size_t i;
				for (i = 0; i < data_size-1; i++) {
					*(data_copy + i) = *(_data + i);
				}

				delete [] _data;
				_data = new S[data_size-1];

				for (i = 0; i < data_size - 1; i++) {
					*(_data + i) = *(data_copy + i);
				}
				_size -= 1;
				delete [] data_copy;
			}
		}

		void print() const {
			for (size_t i = 0; i < size(); i++) {
				std::cout << *(_data + i) << ' ';
			}
			std::cout << '\n';
		}

		bool empty() const {
			return ((_size == 0) && (_data == nullptr));
		}

		bool search(S value) const {
			for (size_t i = 0; i < size(); i++) {
				if (value == *(_data + i)) {
					return true;
				}
			}
			return false;
		}

		Stack<S> &operator=(const Stack<S> &s) {
			if (s.empty()) {
				if (size() == 1) {
					delete _data;
				}
				else {
					delete [] _data;
				}
				_size = 0;
				_data = nullptr;
				return *this;
			}

			if (s.size() == 1) {
				S s_value = *s._data;
				if (size() < 2) {
					delete _data;
				}
				else {
					delete [] _data;
				}
				_data = new S(s_value);
				_size = 1;
			}
			else {
				size_t s_size = s.size();
				S *s_data = new S[s_size];
				size_t i;
				for (i=0; i < s_size; i++) {
					*(s_data + i) = *(s._data + i);
				}

				if (size() < 2) {
					delete _data;
				}
				else {
					delete [] _data;
				}

				_data = new S[s_size];

				for (i=0; i < s_size; i++) {
					*(_data + i) = *(s_data + i);
				}

				_size = s_size;
				delete [] s_data;
			}
			return *this;
		}
		
		template <typename T>
		friend std::ostream &operator<<(std::ostream &out, const Stack<T> &s);

		template <typename T>
		friend bool operator==(const Stack<T> &a, const Stack<T> &b) {
			if (a.size() != b.size()) {
				return false;
			}

			for (size_t i = 0; i < a.size(); i++) {
				if ( (*(a._data + i)) != (*(b._data + i)) ) {
					return false;
				}
			}
			return true;
		}

		template <typename T>
		friend bool operator!=(const Stack<T> &a, const Stack<T> &b);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Stack<T> &s) {
	for(size_t i = 0; i < s.size(); i++) {
		out << *(s._data + i) << ' ';
	}
	return out;
}

template <typename T>
bool operator!=(const Stack<T> &a, const Stack<T> &b) {
	return !(a == b);
}
