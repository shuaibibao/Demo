#include <stdio.h>
#include <stdlib.h>

/*数独二维数组*/
int g_s[9][9] = {    
	    5,0,2,0,0,0,4,0,9,
		0,9,0,0,2,3,0,1,0,
		1,0,0,0,7,0,0,0,5,
		0,2,0,8,0,4,0,0,0,
		0,4,5,0,0,0,8,9,0,
		0,0,0,7,0,5,0,2,0,
		8,0,0,0,6,0,0,0,3,
		0,5,0,3,4,0,0,7,0,
		7,0,3,0,0,0,1,0,2,
};

/*打印当前数独状态*/
void prt()
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 9;i++)
    {
        for(j = 0;j < 9;j++)
        {
            printf("%d ",g_s[i][j]);
        }
        printf("\n");
    }
    getchar();
}

/*获取一个位置当前所有可能的解*/
int get_all_num(int i,int j,int a[9])
{
    int s[9] = {1,2,3,4,5,6,7,8,9};
    int row,col,k;

    /*删除当前行中已出现的值*/
    for(col = 0;col < 9;col++)
    {
        k = g_s[i][col];
        if(k != 0)
        {
            s[k-1] = 0;
        }
    }

    /*删除当前列中已出现的值*/
    for(row = 0;row < 9;row++)
    {
        k = g_s[row][j];
        if(k != 0)
        {
            s[k-1] = 0;
        }
    }

    /*删除当前九宫格中已出现的值*/
    row = (i/3)*3;
    col = (j/3)*3;
    for(i = row;i < (row+3);i++)
    {
        for(j = col;j < (col+3);j++)
        {
            k = g_s[i][j];
            if(k != 0)
            {
                s[k-1] = 0;
            }
        }
    }
    i = 0;
    for(k = 0;k < 9;k++)
    {
        if(s[k] != 0)
        {
            a[i] = s[k];
            i++;
        }
    } 
    return i;
}

/*判断当前行是否合法*/
int check_row(int i,int num)
{
    int j = 0;
    for(j = 0;j < 9;j++)
    {
        if(g_s[i][j] == num)
        {
            return 0;
        }
    }
    return 1;
}

/*判断当前列是否合法*/
int check_col(int j,int num)
{
    int i = 0;
    for(i = 0;i < 9;i++)
    {
        if(g_s[i][j] == num)
        {
            return 0;
        }
    }

    return 1;
        
}

/*判断当前九宫格是否合法*/
int check_block(int i,int j,int num)
{
    int row = (i/3)*3;
    int col = (j/3)*3;
    int k = 0;
    int l = 0;
    
    for(k = row;k < (row+3);k++)
    {
        for(l = col;l < (col+3);l++)
        {
            if(g_s[k][l] == num)
            {
                return 0;
            }
        }
    }
    

    return 1;
}

/*尝试一个解*/
int try_one(int i,int j,int num)
{
    if(check_row(i,num) && check_col(j,num) &&
        check_block(i,j,num))
    {
        g_s[i][j] = num;
        //prt();
        return 1;
    }

    return 0;
}

/*获取下一个要填空的位置*/
int get_next(int *pi,int *pj)
{
    int i = *pi;
    int j = *pj;
    int r = i;
    int c = 0;
    j++;

    for(;r < 9;r++)
    {
        for(c = j;c < 9;c++)
        {
            if(g_s[r][c] == 0)
            {
                *pi = r;
                *pj = c;
                return 1;
            }
        }
        j = 0;
    }

    if(r == 9)
    {
        return 0;
    }

    *pi = r;
    *pj = c;
    return 1;

}

/*找到一个解*/
void finish()
{
    printf("\n find a solution: \n");
    prt();
}

/*处理一个位置*/
int do_one(int i,int j)
{
    int row = i;
    int col = j;
    int n = 0;
    int k = 0;
    int a[9] = {0};
    
    /*当前位置有解,下一个位置*/
    if(g_s[row][col] != 0) 
    {
        /*获取下一个无解的位置*/
        if(get_next(&row,&col))
        {
            /*对一下个位置递归操作*/
            do_one(row,col);
        }
        /*都有解了,成功*/
        else
        {
            finish();
        }

        /*当前位置有解，直接回溯*/
        return 1;
    }

    /*当前位置无解*/
    else 
    {
        /*获取当前位置的所有可能解*/
        n = get_all_num(i,j,a); 
        
        for(k = 0;k < n;k++)
        {
            /*尝试所有可能的解，这里是重复操作，就不改了*/
            if(try_one(i,j,a[k]))
            {
                row = i;
                col = j;
                /*此位置找到合适的了，下一个*/
                if(get_next(&row,&col))
                {    
                    do_one(row,col);
                }
                /*当前位置已有解且没有下一个了,结束*/
                else
                {
                    finish();
                }
            }
        }

        /*要向前回溯,则这个位置找到的解无效,回溯前清0*/
        g_s[i][j] = 0;
        //prt();
        return 1;
    } 
}

int main()
{
    do_one(0,0);

    return 0;

}
