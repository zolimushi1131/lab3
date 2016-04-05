#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

class Clock{

public:

Clock() { setStart(0); }

Clock(clock_t s) {
setStart(s);
}

void start() {
setStart(clock());
}

void setStart(clock_t ts) {
start_ts = (ts>0)?ts:clock();
}

clock_t getStart() {
return start_ts;
}

double getElapsedTime() {
return static_cast<double>(clock()-getStart())
/ CLOCKS_PER_SEC ;
 }

private:
	clock_t start_ts;

};


void insertion_sort(vector<int> & v)
{

	int insert, moveItem;

	for(int next=1;next<v.size();++next)
		{

			insert = v.at(next);

			moveItem = next;

			while((moveItem>0) &&(v.at(moveItem-1) > insert))
				{

					v.at(moveItem) = v.at(moveItem-1);
					--moveItem;

				}

			v.at(moveItem) = insert;
		}


}

int main()
{
Clock clk;
const int size = 1000;
vector<int> v1(size),v2;
srandom(time(NULL));
for(int i=0; i<size; ++i)
	v1.at(i) = random();

v2 = v1; clk.start();
sort(v1.begin(), v1.end());
cout << "sort(): " <<clk.getElapsedTime() << " seconds\n";
cout << "v1/v2 are "<<((v1==v2)?"the same.\n":"different.\n");
clk.start();
insertion_sort(v2);
cout << "insertion_sort(): " <<clk.getElapsedTime() << " seconds\n";
cout << "v1/v2 are "<<
((v1==v2)?"the same.\n":"different.\n");
return 0;
}
