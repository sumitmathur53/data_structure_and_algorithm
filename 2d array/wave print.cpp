#include <iostream>
using namespace std;

void wavePrint(int **input, int nRows, int mCols)
{   
    // if col is even index print in downward order
    // if in odd index print in reverse order.
    for(int i=0;i<mCols;i++){
        if(i%2==0){
            for(int j=0;j<nRows;j++){
                cout<<input[j][i]<<" ";
            }
        }else{
            for(int k=nRows-1;k>=0;k--){
                cout<<input[k][i]<<" ";
            }
        }
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
		wavePrint(input, row, col);
		cout << endl;
	}
}