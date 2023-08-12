// You are using GCC
#include<iostream>
using namespace std;
enum class LetterType{
    vowel,
    consonant,
    invalid
};
class LetterAnalyzer{
    public:
    static LetterType analyze(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            c=tolower(c);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                return LetterType :: vowel;
            }
            else{
                return LetterType :: consonant;
            }
        }
        return LetterType :: invalid;
    }
};
int main(){
    char input;
    cin>>input;
    LetterType result=LetterAnalyzer::analyze(input);
    
    switch(result){
        case LetterType::vowel:
        cout<<"vowel"<<endl;
        break;
        case LetterType::consonant:
        cout<<"consonant"<<endl;
        break;
        case LetterType::invalid:
        cout<<"invalid input"<<endl;
        break;
    }
return 0;
}