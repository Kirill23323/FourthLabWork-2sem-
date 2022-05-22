#pragma once
#include<iostream>
#include<ostream>
#include<istream>
using namespace std;

template<class T>

class TVector 
{
protected:
	T* data;
	int len;

public:
	TVector(int n);
	TVector();
	TVector(const TVector<T> & p);
	TVector(int c, T d);
	~TVector();
	TVector <T> operator + (const TVector <T>& p);
	TVector <T> operator - (const TVector <T>&p);
	TVector <T> operator * (const TVector <T>&p);
	TVector <T> operator / (const TVector <T>&p);
	TVector <T>& operator = (const TVector <T>&p);
	bool operator == (const TVector <T>&p);
	bool operator != (const TVector <T>& p);
	T& operator[] (int n);
	template<class T>
	friend std::ostream & operator <<(std::ostream& k, TVector<T>& m);
	template<class T>
	friend std::istream&  operator >>(std::istream& k, TVector<T>& m);
	int GetLen();
	void Resize(int newlen);
};

template<class T>
inline TVector<T>::TVector(int n)
{
	if (n > 0) {
		data = new int[n];
		len = n;
	}
	else
		throw "Err";
}

template<class T>
inline TVector<T>::TVector()
{
	len = 0;
	data = 0;
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
	if (p.data == 0) 
	{
		data = 0;
		len = 0;
	}
	else 
	{
		len = p.len;
		data = new T[len];
		for (int i = 0; i < len; i++) 
		{
			data[i] = p.data[i];
		}
	}
}

template<class T>
inline TVector<T>::TVector(int c, T d)
{
	if (c > 0)
	{
		data = new T[c];
		len = c;
		for (int i = 0; i < len; i++)
			data[i] = d;
	}
	else 
		throw "Error";
}

template<class T>
inline TVector<T>::~TVector()
{
	if (data != 0)
	{
		delete[] data;
		data = 0;
	}
	len = 0;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
	if (len == 0)
		throw "Err";
	if (len != p.len)
		throw "Err";
	TVector<T> A(len);
	for (int i = 0; i < len; i++) 
	{
		A[i] = data[i] + p.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
	if (len == 0)
		throw "Err";
	if (len != p.len)
		throw "Err";
	TVector<T> A(*this);
	for (int i = 0; i < len; i++)
	{
		A.data[i] -= p.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
	if (len == 0)
		throw "Err";
	if (len != p.len)
		throw "Err";
	TVector<T> A(*this);
	for (int i = 0; i < len; i++)
	{
		A.data[i] *= p.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
	if (len == 0)
		throw "Err";
	if (len != p.len)
		throw "Err";
	TVector<T> A(len);
	for (int i = 0; i < len; i++)
	{
		A[i] = data[i] / p.data[i];
	}
	return A;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
	if (this == &p) 
	{
		return *this;
	}
	if (data != 0)
		delete[] data;
	if (p.data == 0)
		data = 0;
	else 
	{
		data = new T[p.len];
		len = p.len;
		for (int i = 0; i < len; i++) 
		{
			data[i] = p.data[i];
		}
	}
	return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
	if (len != p.len)
		return false;
	for (int i = 0; i < len; i++) 
	{
		if (data[i] != p.data[i])
			return false;
	}
	return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
	if (len != p.len)
		return true;
	for (int i = 0; i < len; i++)
	{
		if (data[i] != p.data[i])
			return true;
	}
	return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
	if (data == 0)
		throw "Err";
	if ((i < 0) || (i >= len))
		throw "Err";
	return this ->data[i];
}

template<class T>
inline std::ostream& operator <<(std::ostream& k, TVector<T>& m)
{
	for (int i = 0; i < m.GetLen(); i++) 
	{
		k << m[i] << "\t";
	}
	return k;
}


template<class T>
 inline std::istream& operator >>(std::istream& k, TVector<T>& m)
{
	int l = 0;
	std::cout << "¬ведите кол-во координат вектора" << std::endl;
	k >> l;
	m.Resize(l);
	for (int i = 0; i < l; i++) 
	{
		k >> m[i];
	}
	return k;
}


template<class T>
inline int TVector<T>::GetLen()
{
	return len;
}

template<class T>
inline void TVector<T>::Resize(int newlen)
{
	if (newlen <= 0)
		throw "Err";
	T* mass = new T[newlen];
	for (int i = 0; i < min(len, newlen); i++) 
	{
		mass[i] = data[i];
	}
	delete[] data;
	len = newlen;
	data = mass;
}
