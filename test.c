int main()
{
   	FILE *fp = fopen("good.c", "r");

	if (fp != NULL)
	{
		;//...
		
	}

	fclose(fp);
	fp=NULL;
   	return 0;
}
