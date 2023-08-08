#include <stdio.h>

int min(int x, int y) { return (x <= y) ? x : y; }

int fibMonaccianSearch(int arr[], int x, int n)
{

	int fibMMm2 = 0;
	int fibMMm1 = 1;
	int fibM = fibMMm2 + fibMMm1;

	while (fibM < n) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}


	int offset = -1;


	while (fibM > 1) {

		int i = min(offset + fibMMm2, n - 1);


		if (arr[i] < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}


		else if (arr[i] > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else
			return i;
	}


	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;


	return -1;
}


int main(void)
{
	int n;
   int arr[20];
   printf("Enter number of elements to be inserted: ");
   scanf("%d",&n);
   printf("Enter elements: ");
   for(int i=0; i<n; i++)
   {
       scanf("%d",&arr[i]);
   }

	int x;
	printf("Enter the  number to be searched; ");
	scanf("%d",&x);
	int ind = fibMonaccianSearch(arr, x, n);
if(ind>=0)
	printf("Found at index: %d",ind);
else
	printf("%d isn't present in the array",x);
	return 0;
}
