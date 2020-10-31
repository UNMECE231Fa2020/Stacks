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
			if (s.size() == 0) {
				_size = 0;
				_data = nullptr;
			}
			else {
				size_t s_size = s.size();
				S *s_data_copy = new S[s_size];
				for (auto i = 0; i < s_size; i++) {
					*(s_data_copy + i) = *(s._data + i);
				}
				if (s_size == 1) {
					_data = new S(*s_data_copy);

				}
				else {
					_data = new S[s_size];
					for (auto i = 0; i < s_size; i++) {
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
