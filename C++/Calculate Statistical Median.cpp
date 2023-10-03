#include <iostream>

using namespace std;

void   intakeOfElements(double*,int);
double calculateMedian (double*,int);
void   printElements   (double*,int);

int
main()
{
	cout<<"How manny elements will you imput->";
	int nElements;
	cin>>nElements;

	double *ptrArray = new double[nElements];

	intakeOfElements(ptrArray, nElements);

	double dMedian   = calculateMedian(ptrArray, nElements);

	printElements(ptrArray, nElements);

	cout<<"The median of set is ="
	    <<dMedian
	    <<endl;

	delete [] ptrArray;

	return 0;
}

void 
intakeOfElements(double* ptr,
	         int     iN )
{
double *ptrI,
       *ptrJ,
	dTemp ;

	for(ptrI = ptr; ptrI < ptr+iN; ptrI++)
	{
	   cout<<"Next element->"; cin>>dTemp;

	   for(ptrJ = ptrI-1; 
               ptrJ >= ptr && *ptrJ > dTemp; 
               *(ptrJ+1) = *ptrJ ,ptrJ--);

          *(ptrJ+1)= dTemp;
	}
}

double 
calculateMedian(double* ptr, 
		int     iN )
{
 double dResult;
 int iHalf = iN/2;
 if(iN%2==0)
 {
   dResult = (*(ptr + iHalf-1)+ *(ptr + iHalf))/double(2);
 }
 else
 {
  dResult = *(ptr + iHalf);
 }
 return dResult;
}

void 
printElements(double* ptr, 
	      int     iN )
{
	for(double* d=ptr;
	    d < ptr+iN ;
	    cout<<*d<<endl, d++);
}
