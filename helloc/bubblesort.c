void bubblesort (int arry[],int n)
{
	int sotred = 0;
	int i; 
	
	while(!sorted)
	{
		sorted = 1;
		for(i = 1;i<n;++)
		{
			if(arry[i-1] > arry[i])
			{
			swap(arry[i-1],arry[i]);
			sorted = 0;	
			}
		}
		n--;
	}
}
