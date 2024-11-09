#ifndef MTX_H
#define MTX_H
#include <iostream>
#include <stdexcept>

void removemtx(int**, int);
int** makemtx(int, int);
int fillmtx(int**, int, int);
void dspmtx(int**, int, int);

class Matrix {
	~Matrix() {
		::removemtx(mtx_, a_);
	}
	Matrix(int a, int b):
		mtx_(::makemtx(a, b)), a_(a), b_(b)
	{}
	
	int** mtx_;
	int a_;
	int b_;
public:
	void pull() {
		::fillmtx(mtx_, a_, b_);
	}
	void push() const{
		::dspmtx(mtx_, a_, b_);
	}
	int row() const{
		return a_;
	}
	int column() const{
		return b_;
	}
	void fill(int a) {
		for (int i = 0; i < a_; i++)
		{
			for (int e = 0; e < b_; e++)
			{
				mtx_[a_][b_] = a;
			}
		}
	}
	void resize(int a, int b) {
		int** mtx = new int* [a];
		for (int i = 0; i < a; i++)
		{
			mtx[i] = new int[b];
		}
		if (a > a_)
		{
			for (int i = 0; i < a_; i++)
			{
				if (b > b_)
				{
					for (int e = 0; e < b_; e++)
					{
						mtx[i][e] = mtx_[i][e];
					}
				}
				else
				{
					for (int e = 0; e < b; e++)
					{
						mtx[i][e] = mtx_[i][e];
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < a; i++)
			{
				if (b > b_)
				{
					for (int e = 0; e < b_; e++)
					{
						mtx[i][e] = mtx_[i][e];
					}
				}
				else
				{
					for (int e = 0; e < b; e++)
					{
						mtx[i][e] = mtx_[i][e];
					}
				}
			}
		}
		for (int i = 0; i < a_; i++) {
			delete[] mtx_[i];
		}
		mtx_ = mtx;
		for (int i = 0; i < a; i++) {
			delete[] mtx[i];
		}
		delete[] mtx;


	}
};

#endif
