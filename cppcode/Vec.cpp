#include<string>
#include<iostream>
#include<cstring>
#include<memory>
#include<algorithm>

using namespace std;
template <class T> class Vec{
	public:
	//需要的类型：iterator,const_iterator,size_type,value_type,difference_type,reference,const_reference 
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;
		
	//需要定义对象的创建，复制，赋值，销毁过程 
	//构造函数：对象的创建 
	Vec(){ create(); }//创建一个空的Vec;
	explicit Vec(size_type n,const T& t = T()){create(n,t);}//根据参数，vector(100),vector(100,1); 

	//复制构造函数 ：对象的复制
   	Vec(const Vec& v){
		create(v.begin(),v.end());
	} 
	//赋值操作符的定义：对象的赋值
	Vec& operator=(const Vec& rhs);
	//析构函数的定义：对象的销毁
	~Vec(){
		uncreate();
	}
	//push_back函数
	void push_back(const T& t)
	{
		if(avail==limit)
			grow();
		unchecked_append(t);
	} 
	//size函数
	size_t size() const{	return avail - data;	} 
	//根据索引来进行读写操作。操作符的重载 
	T& operator[](size_t i){return data[i];}
	const T& operator[](size_t i) const{return data[i];}
	
	iterator begin(){return data;}
	const_iterator begin() const{return data;}
	
	iterator end(){return avail;}
	const_iterator end() const{return avail;}
	
	private:
		iterator data;//第一个元素
		iterator avail;//已初始化元素的最后一个元素的下一个位置 
		iterator limit;//已分配内存的最后一个元素的下一个位置 
		
		allocator<T> alloc;
		/*
 		 *allocator是分配内存的一个类 
 		 *allocate 和deallocate 
 	     *construct 和 destory
 	 	 *uninitialized_copy
 	 	 *uninitialized_fill 
 		 */ 
		
		void create();//创建一个空对象的内存管理 
		void create(size_t,const T&);//对于用指定大小和值的对象创建的内存管理 
		void create(const_iterator,const_iterator);//对于复制时候，创建对象的内存管理 
		
		void uncreate();//销毁一个对象的内存管理 
		
		//对push_back的支持 
		void grow();
		void unchecked_append(const T&);
};

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs){
	if(this != &rhs){
		uncreate();
		create(rhs.begin(),rhs.end());
	}
	return *this;
}
template <class T> void Vec<T>::create(){
	data=limit = avail =0;
} 

template <class T> void Vec<T>::create(size_type n,const T& val){
	data = alloc.allocate(n);
	limit = avail = data+n;
	uninitialized_fill(data,avail,val); 
	
} 

template <class T> void Vec<T>::create(const T*i,const T*j){
	data = alloc.allocate(j-i);
	avail = limit = uninitialized_copy(i,j,data);
	/*avail = limit = data+(j-i);
	uninitialized_copy(i,j,data);*/
}

template <class T> void Vec<T>::uncreate(){
	if(data){
		iterator it = avail;
		while(it!=data) alloc.destroy(--it);
		alloc.deallocate(data,limit-data);
	}
	data=avail=limit=0;
}

template <class T> void Vec<T>::grow(){
	//如果是个空vec 
	size_type new_size = max(2*(limit-data),ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size*2);
	iterator new_avail = uninitialized_copy(data,limit,new_data);
	uncreate();
	data = new_data;
	avail = new_avail;
	limit = data+new_size;
}
template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++,val);
}

int main()
{
	//创建的测试 
	Vec<int> test1_empty;
	cout << test1_empty.size() << endl;
	Vec<int> test2(10);
	Vec<int> test3(10,1);
	//赋值的测试 
	test2 = test3;
	//复制的测试
	Vec<int> test4 = test3;
	//push_back的测试
	test4.push_back(101);
	cout << "test2 is " << endl;
	cout<< test2.size() << endl;
	cout << test2[0] << endl;
	cout << "test3 is " << endl;
	cout << test3.size() << endl;
	cout << test3[0] << endl;
	cout << "test4 is " << endl;
	cout << test4.size() << endl;
	cout << test4[10] << endl;
	 
	return 0;
} 
