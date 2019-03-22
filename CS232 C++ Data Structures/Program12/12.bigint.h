//***************************************************************************************
// Neal A. Dreher         Nov 29, 2000
// CMPSC232               Wednesday 6:00
// Program 12             Windows 2000 Pro, Visual Studios.NET 7.0.9037
//
// 12.bigint.h            BIGINT
//
//
//***************************************************************************************

#ifndef BIGINTH
#define BIGINTH

#include "12.main.h"

#define max_istream_amount 100
#define ul_max_length 11

class BigInt {

	protected:
		char* bigint;
		long count;

	public:
		BigInt();
		BigInt(const unsigned long n);
		BigInt(const char *string);
		BigInt(const BigInt &copy);
		~BigInt();

		void StoreInt(const char* string);
		int length() const;
		int compare(const BigInt& b) const;

		friend istream& operator>>(istream& is, BigInt& b);
		friend ostream& operator<<(ostream& os, const BigInt &b);
		const BigInt& operator=(const BigInt& b);
		BigInt operator+(const BigInt& b) const;
		BigInt operator+(const unsigned long n) const;
		friend BigInt operator+(const unsigned long n, const BigInt b);
		BigInt operator-(const BigInt& b) const;


};

#endif BIGINTH