#pragma once

#include "Vector.h"
#include <ctime>
template<class T>
class TMatrix : public TVector<TVector <T>>
{
protected:
	int width;
public:
	TMatrix();
	TMatrix(int l);
	TMatrix(const TMatrix<T>& p);
	TMatrix(int w,int l);
	~TMatrix();
	int GetWidth();
	TMatrix <T> operator + (const TMatrix <T>& p);
	TMatrix <T> operator - (const TMatrix <T>&p);
	TMatrix <T> operator * (const TMatrix <T>&p);
	TVector<T> operator * (TVector<T>& p);
	TMatrix <T>& operator = (const TMatrix <T>&p);
	TVector<T>& operator [] (const int i);
	template<class T>
	friend std::ostream& operator <<(std::ostream& k, TMatrix<T>& m);
	template<class T>
	friend std::istream& operator >>(std::istream& k, TMatrix<T>& m);
	bool operator == (const TMatrix <T>&p);
	bool operator != (const TMatrix <T>& p);
	void Resize(int w,int l);

};

template<class T>
inline TMatrix<T>::TMatrix()
{
	width = 0;
	this->len = 0;
	this->data = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int l)
{
	if (l < 0)
		throw "Err";
	this->len = l;
	width = l;
	this->data = new TVector<T>[width];
	for (int i = 0; i < len; i++) 
	{
		this->data[i].Resize(len);
	}
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
	this->len = p.len;
	width = p.width;
	if (p.data == 0) 
	{
		this->data = 0;
	}
	else 
	{
		this ->data = new TVector<T>[width];
		for (int i = 0; i < width; i++) 
		{
			this->data[i] = p.data[i];
		}
	}
}

template<class T>
inline TMatrix<T>::TMatrix(int w, int l)
{
	if ((l < 0) ||(w < 0))
		throw "Err";
	this ->len = l;
	width = w;
	this ->data = new TVector<T>[width];
	for (int i = 0; i < width; i++)
	{
		this->data[i].Resize(len);
	}
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	width = 0;
}

template<class T>
inline int TMatrix<T>::GetWidth()
{
	return width;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p)
{
	TMatrix res(*this);
	if ((this->len != p.len) || (this->width != p.width))
		throw "Err";
	for (int i = 0; i < width; i++) 
	{
		res.data[i] = this->data[i] + p.data[i];
	}
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p)
{
	TMatrix res(*this);
	if ((this->len != p.len) || (this->width != p.width))
		throw "Err";
	for (int i = 0; i < width; i++)
	{
		res.data[i] = this->data[i] - p.data[i];
	}
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
	if ((this->len != p.len) || (this->width != p.width))
		throw "Err";
	TMatrix res(width, p.len);
	for (int i = 0; i < width; i++)
		for (int j = 0; j < p.len; j++) 
		{
			res[i][j] = 0;
			for (int n = 0; n < len; n++) 
			{
				res[i][j] *= this->data[i][n] + p.data[i][n];
			}
		}
	return res;
}

template<class T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& p)
{
	if (this->len != p.GetLen()) 
		throw "Err";
	TVector<T> res(width, 0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			res[i] += this->data[i][j] * p[j];
		}
	}
	return res;
}

template<class T>
TMatrix<T> operator*(TVector<T>& vector, TMatrix<T>& matrix)
{
	if (matrix.GetWidth() != 1) 
		throw "Error";
	TMatrix<T> res(vector.GetLen(), matrix.GetLen());
	for (int i = 0; i < vector.GetLen(); i++)
	{
		for (int j = 0; j < matrix.GetLen(); j++)
		{
			res[i][j] = vector[i] * matrix[0][j];
		}
	}
	return res;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& p)
{
	this->len = p.len;
	this->width = p.width;
	if (this == &p)
		return *this;
	if (this->data != 0) 
		delete[] data;
	if (p.data == 0)
		data = 0;
	else
	{
		data = new TVector<T>[p.width];
		for (int i = 0; i < p.width; i++) 
		{
			data[i] = p.data[i];
		}
	}
	return*this;
}

template<class T>
inline TVector<T>& TMatrix<T>::operator[](const int i)
{
	if (i < 0 || i >= this->width) 
		throw "Error";
	return this->data[i];
}

template<class T>
inline std::ostream& operator<<(std::ostream& k, TMatrix<T>& m)
{
	for (int i = 0; i < m.width; i++)
	{
		for (int j = 0; j < m.len; j++)
			k << m[i][j] << "\t";
		k << "\n";
	}
	return k;
}

template<class T>
inline std::istream& operator>>(std::istream& k, TMatrix<T>& m)
{
	cout << "¬ведите кол - во строк: " << std::endl;
	k >> m.width;
	cout << "¬ведите кол-во столбцов: ";
	k >> m.len;
	TMatrix<T> temp(m.width, m.len);
	for (int i = 0; i < m.width; i++)
		for (int j = 0; j < m.len; j++)
			k >> temp[i][j];
	m = temp;
	return k;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
	if ((len != p.len) || (width != p.width))
		return false;
	for (int i = 0; i < width; i++) 
	{
		for (int j = 0; j < len; j++) 
		{
			if (this->data[i][j] != p.data[i][j])
				return false;
		}
	}
	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& p)
{
	if ((len != p.len) || (width != p.width))
		return true;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (this->data[i][j] != p.data[i][j])
				return true;
		}
	}
	return false;
}

template<class T>
inline void TMatrix<T>::Resize(int w, int l)
{
	TVector<T>* data1 = new TVector<T>[w];
	if (this->data != nullptr)
	{
		int minW, minL;
		if (width > w) 
			minW = w;
		else 
			minW = width;
		if (this->len > l) 
			minL = l;
		else 
			minL = this->len;
		for (int i = 0; i < minW; i++)
		{
			data1[i].Resize(l);
			for (int j = 0; j < minL; j++)
				data1[i][j] = this->data[i][j];
		}
		delete[] data;
	}
	this->data = data1;
	this->len = l;
	width = w;

}

