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
template <typename T, std::size_t size>
	bool findInArr( T (&n)[size], T what ) noexcept{
		for(auto x : n) 
			if(x == what) return true;
		return false;
	}


template <typename T> 
	bool findInArr( T * n, T what ){
			std::size_t r=0;
			while( *n ) if(*(n++) == what) return true;  
			return false;
	}


