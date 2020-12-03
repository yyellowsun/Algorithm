#include<string>
#include<iostream>
#include<cstring>
#include<memory>
#include<algorithm>

using namespace std;
template <class T> class Vec{
	public:
	//��Ҫ�����ͣ�iterator,const_iterator,size_type,value_type,difference_type,reference,const_reference 
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;
		
	//��Ҫ�������Ĵ��������ƣ���ֵ�����ٹ��� 
	//���캯��������Ĵ��� 
	Vec(){ create(); }//����һ���յ�Vec;
	explicit Vec(size_type n,const T& t = T()){create(n,t);}//���ݲ�����vector(100),vector(100,1); 

	//���ƹ��캯�� ������ĸ���
   	Vec(const Vec& v){
		create(v.begin(),v.end());
	} 
	//��ֵ�������Ķ��壺����ĸ�ֵ
	Vec& operator=(const Vec& rhs);
	//���������Ķ��壺���������
	~Vec(){
		uncreate();
	}
	//push_back����
	void push_back(const T& t)
	{
		if(avail==limit)
			grow();
		unchecked_append(t);
	} 
	//size����
	size_t size() const{	return avail - data;	} 
	//�������������ж�д������������������ 
	T& operator[](size_t i){return data[i];}
	const T& operator[](size_t i) const{return data[i];}
	
	iterator begin(){return data;}
	const_iterator begin() const{return data;}
	
	iterator end(){return avail;}
	const_iterator end() const{return avail;}
	
	private:
		iterator data;//��һ��Ԫ��
		iterator avail;//�ѳ�ʼ��Ԫ�ص����һ��Ԫ�ص���һ��λ�� 
		iterator limit;//�ѷ����ڴ�����һ��Ԫ�ص���һ��λ�� 
		
		allocator<T> alloc;
		/*
 		 *allocator�Ƿ����ڴ��һ���� 
 		 *allocate ��deallocate 
 	     *construct �� destory
 	 	 *uninitialized_copy
 	 	 *uninitialized_fill 
 		 */ 
		
		void create();//����һ���ն�����ڴ���� 
		void create(size_t,const T&);//������ָ����С��ֵ�Ķ��󴴽����ڴ���� 
		void create(const_iterator,const_iterator);//���ڸ���ʱ�򣬴���������ڴ���� 
		
		void uncreate();//����һ��������ڴ���� 
		
		//��push_back��֧�� 
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
	//����Ǹ���vec 
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
	//�����Ĳ��� 
	Vec<int> test1_empty;
	cout << test1_empty.size() << endl;
	Vec<int> test2(10);
	Vec<int> test3(10,1);
	//��ֵ�Ĳ��� 
	test2 = test3;
	//���ƵĲ���
	Vec<int> test4 = test3;
	//push_back�Ĳ���
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
