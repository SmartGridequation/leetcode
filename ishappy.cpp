#include<math.h>
#include<stdio.h>
#include<iostream.h>
using namespace std;	
		
bool isHappy(int n) {
        int num = 0;
        int i = 100;
        while(i--) {
            while(n) {
                num += (n%10)*(n%10);
                n = n/10;
            }
            if(1 == num)
                return true;
            n = num, num = 0;
        }
        return false;       
    }


main(){
	cout<<isHappy(16)<<endl;
}