
#include <iostream.h>

void main() {

	int num = 0, newnum = 0;
	int a = 1, b = 0, c = 0, d = 0;
	bool special = false;

	while (!special) {

		// this is what counts your number ABCD up as 
		// chars in counting format

		if (d != 9) d++;
		else { 
			d = 0;
			if (c!= 9) c++;
			else {
				c = 0;
				if (b != 9) b++;
				else { 
					b = 0;
					a = 1;
				}
			}
		}

		num = (a * 10000 + b * 1000 + 9 * 100 + c * 10 + d);
		newnum = num * 9;

		if ((newnum / 10000) == (num % 10)) {
			newnum = newnum - 10000 * (newnum / 10000);
			num = num - (num % 10);

			if ((newnum / 1000) == ((num % 100) / 10)) {
				newnum = newnum - 1000 * (newnum / 1000);
				num = num - (num % 100);

				if ((newnum / 100) == ((num % 1000) / 100)) {
					newnum = newnum - 100 * (newnum / 100);
					num = num - (num % 1000);

					if (newnum == (num / 10000)) {
						special = true;
					}
				}
			}
		}

	
	} // while end
		
	cout << "The special number = " << a << b << c << d << endl;	
	cout <<  "ab9cd = " << a << b << '9' << c << d << endl;
	cout <<  "dc9ba = " << d << c << '9' << b << a << endl;



} // main end
