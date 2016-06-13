// 设置ascii表的格式
// 用空格控制位置
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_LEN		8
#define COL_COUNT		6

void str_alloc(char * str[])
{
	int i;

	for(i = 0; i < COL_COUNT; i++)
		str[i] =(char *) malloc(128);
}

void str_free(char * str[])
{
	int i;

	for(i = 0; i < COL_COUNT; i++)
		free(str[i]);
}

void out_put(char * str[])
{	
	FILE * pf;
	FILE * pf_out;
	int i;
	int arr_len[COL_COUNT] = {8,5,5,5,0,26};

	pf = fopen("05-ascii.txt", "r");
	pf_out = fopen("05-ascii_format.txt", "w");

	while(!feof(pf))	
	{
		for(i = 0; i < COL_COUNT; i++)
		{
			fscanf(pf, "%s", str[i]);
			switch(i)
			{
				case 0:
				case 1:
				case 2:
				case 3:
					fprintf(pf_out,"%*s", arr_len[i], str[i]);
					break;
				case 4:
					// +2是为了在前面空出2个空格
					fprintf(pf_out,"%*s", (int)strlen(str[i])+2, str[i]);
					// 让第5列与第四列保持26个空格的距离
					arr_len[5] = 26-(int)strlen(str[i]);
					break;
				case 5:
					fprintf(pf_out,"%*s", (int)strlen(str[i])+arr_len[i], str[i]);
					break;
				default:
					break;
			}
		}
		fputc('\n', pf_out);
	}
	fclose(pf_out);
	fclose(pf);
}

int main(void)
{
	char * str[COL_COUNT];

	str_alloc(str);
	out_put(str);
	str_free(str);

	return 0;
}
