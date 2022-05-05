
#include <iostream>
using namespace std;

#include<climits>


int rowsum(int **input, int row, int col, int k){
    int sum = 0;
    for(int j=0;j<col;j++){
        sum+=input[k][j];
    }
    return sum;
}
int colsum1(int **input,int row, int col, int k){
    int colsum=0;
    for(int i=0;i<row;i++){
        colsum+=input[i][k];
    }
    return colsum;
}
void findLargest(int **input, int nRows, int mCols)
{
    int sumrow=INT_MIN;
    int colsum=INT_MIN;
    int rowidx;
    int colidx;
    
    int k=0;
    while(k<nRows){
        if(rowsum(input,nRows,mCols,k)>sumrow){
            sumrow = rowsum(input,nRows,mCols,k);
            rowidx = k;    
        }
        k++;
    }
    
    int j=0;
    while(j<mCols){
        if(colsum1(input,nRows,mCols,j)>colsum){
            colsum = colsum1(input,nRows,mCols,j);
            colidx = j;
        }
        j++;
    }
    
    if(colsum>sumrow){
        cout<<"column"<<" "<<colidx<<" "<<colsum;
    }else{
        cout<<"row"<<" "<<rowidx<<" "<<sumrow;
    }
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}