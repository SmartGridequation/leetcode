class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       int i=0; bool w;
        for(i=0;i<bits.size();i++){
            if(bits[i]==1&&bits[i+1]==0){
                i+=2;
        }
             if(bits[i]==1&&bits[i+1]==1){
                i+=2;
        }
              if(bits[i]==0&&i==bits.size()){
                //return true; 
                  w=true;
        }
            else{
                w=false;
            }
                
        }
        return w; 
    }
};



class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       int i=0; bool w=false;
        for(i=0;i<bits.size();i++){
            if(bits[i]==1){
                i+=2;
        }
        else if(bits[i]==0){
                ;
        }
            
        if(i==bits.size()-1&&bits[i]==0){
            w=true;
        }
        else{
                w=false;
        }
            
    }
        return w;
    }
};