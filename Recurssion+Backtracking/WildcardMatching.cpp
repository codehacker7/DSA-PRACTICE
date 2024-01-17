#include<iostream>
using namespace std;


bool checkEqualityUsingRegex(string s1,string s2,int i,int j){

    if( i < 0 && j < 0) return true;

    if(i < 0 && j >= 0) return false;//string s1 is exhausted but string s2 is not

    if(j < 0 && i >= 0){ //string s2 is exhaused but s1 is not
        for(int ii = i;ii>=0;ii--){
            if(s1[ii] != '*'){
                return false;
            }
        }
        return true;
    }


    if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
        return checkEqualityUsingRegex(s1,s2,i-1,j-1);
    }

    if(s1[i-1] == "*"){
        return checkEqualityUsingRegex(s1,s2,i-1,j) || checkEqualityUsingRegex(s1,s2,i,j-1);//check by equating * by 1 charahter
    }

    return false;

}




int main(){
    string s1;
    cin>>s1;

    string s2;
    cin>>s2;

    checkEqualityUsingRegex(s1,s2);
}
