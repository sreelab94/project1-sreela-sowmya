#include <stdio.h>
#define TRACE_LOG(fmt, args...) fprintf(stdout,fmt, ##args);

int main()
{
	int i=1;
	TRACE_LOG("%s", "Sample macro\n");
	TRACE_LOG("%d%s",i,"Sample macro\n");
	TRACE_LOG("\nbchdbcjdn\n");
	return 0;
}
