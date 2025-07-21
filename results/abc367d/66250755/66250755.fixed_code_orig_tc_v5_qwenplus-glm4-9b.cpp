for(int i=1;i<2*n;i++)
{
	w[i+1]=(w[i]+a[i])%m;
	if(i>n)t[w[i-n]]--;
	if(i>=n)
	{
		an+=t[w[i]];
	}
	t[w[i]]++;
}