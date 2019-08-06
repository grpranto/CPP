#include<bits/stdc++.h>
#include<stdio.h>
#define lli long long int
using namespace std;

vector<lli>arr;

lli Max(lli a, lli b, lli c)
{
	if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    else
        return c;
}

lli MaxCrossingSum(lli low, lli mid, lli high)
{
	lli sum = 0;
	lli leftpartsum = -1;
	for (lli i = mid; i >= low; i--)
	{
		sum = sum + arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
	}
	sum = 0;
	lli rightpartsum = -1;
	for (lli i = mid+1; i <= high; i++)
	{
		sum = sum + arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
    }

	return leftpartsum + rightpartsum;
}

lli MaxSubArraySum(lli low, lli high)
{
	lli mid;
	if (low == high)
		return arr[low];

	mid = (low + high)/2;

    lli LS = MaxSubArraySum(low, mid);
    lli RS = MaxSubArraySum(mid+1, high);
    lli CS = MaxCrossingSum(low, mid, high);

    int M = Max(LS,RS,CS);

	return M;
}

int main()
{
    cout<<"\t\t********************************"<<endl
        <<"\t\t******MAXIMUM SUM INTERVAL******"<<endl
        <<"\t\t********************************"<<endl
        <<endl<<endl;
	lli n, i;
	FILE *p = fopen("MaximumSumIntervalInput.txt","r");
	fscanf(p,"%I64d",&n);
	//cout<<n<<endl;
	for(i=0;i<n;i++)
	{
	    lli k;
		fscanf(p,"%I64d",&k);
		//cout<<k<<endl;
		arr.push_back(k);
	}
	fclose(p);
	lli result = MaxSubArraySum(0, n-1);
    cout<<"Check the Maximum sum in the file 'Output.txt'..."<<endl;
	//cout<<"\nMaximum Sum Interval is: "<<MaxSubArraySum(0, n-1);
    FILE *q = fopen("output.txt","w");
    fprintf(q,"\t\t********************************\n");
    fprintf(q,"\t\t******MAXIMUM SUM INTERVAL******\n");
    fprintf(q,"\t\t********************************\n");
    fprintf(q,"\n\n");
    fprintf(q,"\t\tThe Maximum Sum Interval is: %I64d\n",result);
    fprintf(q,"\n\n");
    fprintf(q,"\t\t\tTHANK YOU!!... :)\n");
	return 0;
}
