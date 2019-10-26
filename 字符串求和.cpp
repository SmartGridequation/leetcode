class Solution {
public:
    string addBinary(string a, string b) {
      int len1=a.size();
      int len2=b.size();
        int num1[a.size()];
        int num2[b.size()];
        int num3[len1+len2];
        if(a>b){
            c=a;
        }
        else {
            c=b;
        }
        for(int i=0;i<=len1;i++){
            if(a[i]=='0'){
             num1[i]=0;   
            }
            else{
                num1[i]=1;
            }
        }
        
        
        for(int i=0;i<=len2;i++){
            if(b[i]=='0'){
             num2[i]=0;   
            }
            else{
                num2[i]=1;
            }
        }
        
        for(int i=0;i<=c;i++){
            num3[i]=num1[i]+num2[i];
        }
        
        
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
      int len1=a.size();
      int len2=b.size();
      int num1[a.size()];
      int num2[b.size()];
      char num3[len1+len2];
        int c;
        
        if(len1>len2){
            c=len2;
        }
        else {
            c=len1;
        }
        
        for(int i=0;i<c;i++){
       if(a[i]=='1'&&b[i]=='0'){
           num3[i]='1';
       }
        else if(a[i]=='0'&&b[i]=='1'){
           num3[i]='1';
       }
        else if(a[i]=='0'&&b[i]=='0'){
           num3[i]='0';
       }   
        else if(a[i]=='1'&&b[i]=='1'){
           num3[i]='0';
        num3[i+1]='1';
       }
    }
       return num3; 
    }
};