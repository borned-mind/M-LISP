template <typename T, std::size_t size>
	std::size_t getArraySize( T (&n)[size] ) noexcept{
		return size;
	}
template <typename T> 
	std::size_t getArraySize( T * n ){
			std::size_t r=0;
			while(*(n++))r++;
			return r;
	}
