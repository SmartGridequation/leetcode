//腾讯2017暑期实习生招聘第一道题。做了一个世纪才做出来………………太菜了

/**
    题目：
    给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
    输出需要删除的字符个数。

    输入描述:    输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  
    输出描述:    对于每组数据，输出一个整数，代表最少需要删除的字符个数。

    输入例子:
        abcda
        google

    输出例子:
        2
        2
*/

/*
    看牛客网上的一个解题思路是：
    比较简单的想法就是求原字符串和其反串的最大公共子串的长度，然后用原字符串的长度减去这个最大公共子串的长度就得到了最小编辑长度。（注：最大公共子串并不一定要连续的，只要保证出现次序一致即可看作公共子串）
      可以使用   Needleman/Wunsch算法  牺牲内存换取简单的代码和CPU时间。
      算法解释可以参考博主“万仓一黍”总结的博文
           http://www.cnblogs.com/grenet/archive/2010/06/03/1750454.html

    于是去学习动态规划，和文本比较算法。然后回来做这个题。也是出了各种问题。
    慢慢学习提高吧
    */

#include<stdio.h>
#include<string.h>        //这里如果不是string.h而是string的话在VC6.0是可以编译通过的，但是在牛客网的oj平台不能通过。加上.h就好了
#include<iostream>
#define N 1000


                        //这个函数本来是为了获得字符串的倒序，但是因为空间不够了，所以没有使用
void reverse(char s1[], char s2[]){
    s2[strlen(s1)] = '\0';
    for(int i=0;i<strlen(s1);i++){
        s2[i] = s1[strlen(s1)-1-i];
    }
}

int max(int a, int b, int c){
    return (a>b?a:b)>c?(a>b?a:b):c;
}

int find(char s[]){
    int count[2][N];
    //int count[N][N];                        //原来是定义了一个N*N维的数组来存储动态规划的计算数组，但是使用空间太大，于是只使用了2*N维的数据。即只存储上一次的结果
    int len = strlen(s);
    int i,j;
    for(i=0;i<len+1;i++){
        //count[i][0] = count[0][i] =0;            
        count[0][i] = 0;
    }
    
    count[1][0] = 0;
    //char s0[N];
    //reverse(s,s0);
    for(i=1;i<len+1;i++){
        for(j=1;j<len+1;j++){
            if(s[i-1] == s[len-j]){                //这里原来写的是s[i]==s[len-j-1]，然后出现各种问题。有许多用例通不过
                count[1][j] = count[0][j-1]+1;
            } else {
                count[1][j] = max(count[0][j-1],count[1][j-1],count[0][j]);
            }
        }
        for(j=0;j<len+1;j++){
            count[0][j] = count[1][j];
        }
    }
    


       return (len-count[1][len]);    
}

int main(){
    char s[N];
    while(scanf("%s",s)!=EOF){
        int result = find(s);
        printf("%d\n",result);
    }
    return 0;
}