#include <iostream>

template <typename Ta>
void subset(Ta *A, int n, int i)
{
	if(i == n)
	{
		for(int j = 0; j < n ;j++)
			std::cout << *(A+j);
		std::cout << std::endl;
	}
	else
	{
		A[i] = 0;
		subset(A, n, i+1);
		A[i] = 1;
		subset(A, n, i+1);
	}
}
int main()
{	
	int n = 3;		
	int A[n];		
	for (int i = 0; i<n; i++)
	{
		A[i] = 0;	
	}
	subset(A,n,0);

	return 0;
}