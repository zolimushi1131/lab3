#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int size;
	int sum=0;
	

	ifstream inFile("file.in", ios::in);
    if(!inFile)
    {
        cerr<<"Failed opening."<<"\n";
    }

	inFile>>size;
	//read in the file
	vector<int> cow(size,0);
	for (int i = 0; i < size; ++i)
	{
		inFile>>cow[i];
	}
	
	int insert, moveItem;
	for(int next=1;next<size;++next)
	{
		insert = cow.at(next);
		moveItem = next;
		while((moveItem>0) && (cow.at(moveItem-1) > insert))
		{
			cow.at(moveItem) = cow.at(moveItem-1);
			--moveItem;
		}
		cow.at(moveItem) = insert;
	}
	for(int i=size-1; i>(size-6);i--)
	{
		sum+=cow[i];
	}
	cout<<sum;

return 0;
}
