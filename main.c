#include <stdio.h>
#include <ftw.h>
#include <fnmatch.h>

static char line[4096];

int countfileline(const char * fpath)
{
	int lc = 0;
	FILE *f=fopen(fpath,"r");
	if(f)
	{
		while(!feof(f))
		{
			fgets(line,4096,f);	
			lc ++;
		}		
		fclose(f);	
	}
	return lc;
}

static long total_line = 0;

int fn(const char* fpath,const struct stat * sb, int typeflag)
{
	if(!fnmatch("*.[ch]",fpath,FNM_NOESCAPE) || !fnmatch("*.cpp",fpath,FNM_NOESCAPE) )
	{			
		total_line += countfileline(fpath);		
	}
	return 0;
}
int main(int argc,char *argv[])
{
	ftw(argv[1],fn,1000);
	printf("%ld\n",total_line);
	return 0;
}
