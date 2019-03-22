//*************************************************************************************** 
// Neal A. Dreher         Nov 29, 2000
// CMPSC232               Wednesday 6:00
// Program 12             Windows 2000 Pro, Visual Studios.NET 7.0.9037
//
// 12.bigint.cpp          BIGINT
//
//
//***************************************************************************************

#include "12.main.h"

// default constructor
// syntax: BigInt a;
BigInt::BigInt() {
	count = 1;
	bigint = new char[1];
	bigint[0] = '0';
}

// constructor passed a long
// syntax: BigInt a(32489349ul);
BigInt::BigInt(const unsigned long n) {
	char msg[ul_max_length];
	ostrstream os(msg, sizeof(msg));
	os << n << ends;
	count = strlen(msg);
	StoreInt(msg);
}

// constructor passed a char string
// syntax: Bigint a("32409");
BigInt::BigInt(const char *string) {
	count = strlen(string);
	StoreInt(string);
}

// constructor passed another BigInt
// syntax: BigInt b(a);
BigInt::BigInt(const BigInt &copy) {
	count = copy.count;
	StoreInt(copy.bigint);
}

// destructor
BigInt::~BigInt() {
	if (bigint) delete [] bigint;
}

// this is an internal helper function that stops repetitiveness of storing char*
// note: 'int countpassed' defaults to -1 is the user passes nothing that way
//   StoreInt will determine the count, if the user wants to set the count for
//   then StoreInt will take the users word
// syntax: StoreInt(input, i), StoreInt(input)
void BigInt::StoreInt(const char* string) {
	
	bigint = new char[count];
	for (int i=0; i < count; i++) 
		bigint[i] = string[i] ;
	return;
}

// set one BigInt instance with the same values as another
// syntax: BigInt a = c;
const BigInt& BigInt::operator=(const BigInt& b) {
	if(this == &b) return b;
	delete [] bigint;
	count = b.count;
	bigint = new char[count];
	for (int i=0; i <= count; i++) 
		bigint[i] = b.bigint[i];
	return *this;
}

// input a bigint via istream and store it
// syntax: cout << a << endl << b << endl;
istream& operator>>(istream& is, BigInt& b) {
	delete [] b.bigint;
	b.bigint = new char[max_istream_amount];  // 100
	char nums;
	// get rid of ws and 0's
	is >> ws;
	nums = is.get();
	while (nums == 48) nums = is.get();
	// get the real numbers and store into b.bigint
	if (nums >= 49 && nums <= 57 && isdigit(nums)) {
		for(int i = 0; nums >= 48 && nums <= 57; i++) {
			b.bigint[i] = nums;
			b.count = i+1;
			nums = is.get();
		}
		is.putback(nums);
	}  // must have eaten all the zeros then inputed garbage
	else b.bigint[0] = '0';
	return is;
}

// output a bigint stored via ostream passed
// syntax: cout << a << endl << b << endl;
ostream& operator<<(ostream& os, const BigInt &b) {
	for(int i = 0; i < b.count; i++) 
		os << b.bigint[i];
	return os;
}

// return the users request for how many numbers are in the int
// syntax: int len = a.Length();
int BigInt::length() const {
	return count;
}

// checks two big int's to see if one is smaller, larger or they are =
// return: 0 if equal
//	1 if host is larger than the passed BigInt
//	-1 if host is smaller than the passed BigInt
// syntax: a.compare(b);
int BigInt::compare(const BigInt& b) const {
	if (count != b.count) return count > b.count ? 1 : -1;
	return strcmp(bigint, b.bigint);
}

// adds two BigInt's together 
// syntax:  BigInt x("1"), y("2");
//			BigInt z = x + y;
BigInt BigInt::operator+(const BigInt& b) const {
	int length = count > b.count ? count + 1 : b.count + 1;
	char* ansr = new char[length];
	int it = count -1;
	int ib = b.count -1; 
	int iansr = length -1;
	int carry = 0;
	while(ib >= 0 && it >= 0) {
		ansr[iansr] = bigint[it]-48 + b.bigint[ib]-48 + carry;
		if(ansr[iansr] > 9) {
			carry = 1;
			ansr[iansr] -= 10;
		}
		else carry = 0;
		ansr[iansr] += 48;
		ib--;
		it--;
		iansr--;
	}
	while(it >= 0) {
		ansr[iansr] = bigint[it]-48 + carry;
		if(ansr[iansr] > 9) {
			carry = 1;
			ansr[iansr] -= 10;
		}
		else carry = 0;
		ansr[iansr] += 48;
		it--;
		iansr--;
	}
	while(ib >= 0) {
		ansr[iansr] = b.bigint[ib]-48 + carry;
		if(ansr[iansr] > 9) {
			carry = 1;
			ansr[iansr] -= 10;
		}
		else carry = 0;
		ansr[iansr] += 48;
		ib--;
		iansr--;
	}
	if (carry == 1)	ansr[0] = carry + 48;
	else ansr[0] = 0;
	BigInt t;
	delete [] t.bigint;
	t.bigint = new char[length];
	t.count = length;
	for(int i = 0; i < length; i++) t.bigint[i] = ansr[i]; 

	delete [] ansr;
	return t;
}

// add a BigInt's and an int together 
// syntax:  BigInt x("1");
//			BigInt z = x + 20;
BigInt BigInt::operator+(const unsigned long n) const {
	BigInt s(n);
	BigInt t(bigint);
	t.count = count;  //change because passing a non-null-term string in t(bigint)
	return s + t;
}

// add an int together 
// syntax:  BigInt x("1");
//			BigInt z = 20 + x;
BigInt operator+(const unsigned long n, const BigInt b) {
	return b + n;
}

BigInt BigInt::operator-(const BigInt& b) const {
	int length = count > b.count ? count + 1 : b.count + 1;
	char* ansr = new char[length];
	int it = count -1;
	int ib = b.count -1; 
	int iansr = length -1;
	int borrow = 0;
	while(ib >= 0 && it >= 0) {
		ansr[iansr] = bigint[it] - b.bigint[ib] - borrow;
		if(ansr[iansr] < 0) {
			borrow = 1;
			ansr[iansr] += 10;
		}
		else borrow = 0;
		ansr[iansr] += 48;
		ib--;
		it--;
		iansr--;
	}
	while(it >= 0) {
		ansr[iansr] = bigint[it]-48 - borrow;
		if(ansr[iansr] < 0) {
			borrow = 1;
			ansr[iansr] += 10;
		}
		else borrow = 0;
		ansr[iansr] += 48;
		it--;
		iansr--;
	}
	while(ib >= 0) {
		ansr[iansr] = b.bigint[ib]-48 - borrow;
		if(ansr[iansr] < 0) {
			borrow = 1;
			ansr[iansr] += 10;
		}
		else borrow = 0;
		ansr[iansr] += 48;
		ib--;
		iansr--;
	}
	ansr[0] = borrow;
	BigInt t;
	delete [] t.bigint;
	t.bigint = new char[length];
	t.count = length;
	for(int i = 0; i <= length; i++) t.bigint[i] = ansr[i]; 
	delete [] ansr;
	return t;
}
