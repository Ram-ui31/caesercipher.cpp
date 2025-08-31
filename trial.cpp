#include<iostream>
#include<cctype>
#include<string>
using namespace std;

string encrypt(string Message,string keyword){
    string message=Message;
    int l=message.length();
    int l0=keyword.length();
    for(int i=0; i<l; i++){
                if(message[i]>64 && message[i]<91){
                message[i]=((message[i]+keyword[i%l0]-130)%26+26)%26 + 65;
            }
            else if(message[i]>96 && message[i]<123){
                message[i]=((message[i]+keyword[i%l0]-162)%26+26)%26 + 97;
            }
            }
    return message;
}

string decrypt(string message,int shift){
    for(int i=0; i<message.length(); i++){
                if(message[i]>64 && message[i]<91){
                message[i]=((message[i]-65-shift)%26+26)%26 + 65;
            }
            else if(message[i]>96 && message[i]<123){
                message[i]=((message[i]-97-shift)%26+26)%26 + 97;
            }
            }
    return message;
}

string decrypt2(string Message,string keyword){
    string message=Message;
    int l=message.length();
    int l0=keyword.length();
    for(int i=0; i<l; i++){
                if(message[i]>64 && message[i]<91){
                message[i]=((message[i]-keyword[i%l0])%26+26)%26 + 65;
            }
            else if(message[i]>96 && message[i]<123){
                message[i]=((message[i]-keyword[i%l0]-32)%26+26)%26 + 97;
            }
            }
    return message;
}

void top(string s){
    int hash[26]={0};
    int largest=0;
    char letter='e';
    for(char c:s){
        if(isalpha(c)){
            hash[tolower(c)-'a']++;
            if(hash[tolower(c)-'a']>largest){
                largest=hash[tolower(c)-'a'];
                letter=tolower(c);
            }
        }
    }
    int n1=letter-'e';
    int n2=letter-'a';
    int n3=letter-'i';
    int n4=letter-'o';
    int n5=letter-'r';
    int n6=letter-'n';
    int n7=letter-'s';
    cout<<"these are the 7 most probable answers:\n";
    cout<<"shift "<<n1<<decrypt(s,n1)<<endl;
    cout<<"shift "<<n2<<decrypt(s,n2)<<endl;
    cout<<"shift "<<n3 <<decrypt(s,n3)<<endl;
    cout<<"shift "<<n4 <<decrypt(s,n4)<<endl;
    cout<<"shift "<<n5 <<decrypt(s,n5)<<endl;
    cout<<"shift "<<n6 <<decrypt(s,n6)<<endl;
    cout<<"shift "<<n7 <<decrypt(s,n7)<<endl; 
}

int result(string s){
    int c1=0;
    int c2=0;

    for(char c:s){
        if(c=='e' || c=='E' || c=='a' || c=='A' || c=='o' || c=='O' || c=='i' || c=='I' || c=='u' || c=='U'){
            c1++;
        }
        else if(c=='z' || c=='Z'){
            c2++;
        }
    }
    return c1-c2;
}


void backup(string Message){
    string original=Message;
            int greatest=0;
            
            int shift=0;
            for(int i=1; i<26; i++){
                string ok=decrypt(Message,i);
                int res=result(ok);
                
                if(res>greatest){
                    greatest=res;
                    original=ok;
                    shift=i;
                }
            }
            cout<<"shift maybe "<<shift<<endl;
            cout<<"decoded message: "<<original<<endl;

            cout<<"satisfied?(y or n) ";
            char satisfied;
            cin>>satisfied;
            if(satisfied=='y'){
                cout<<"great! have a nice day :)";
            }
            else{
                cout<<"alright. I will show you all the possible shifts and choose which one suits you.\n .\n .\n .\n .\n .\n .\n . ";
                for(int i=1; i<26; i++){
                    string k=Message;
                    
                    cout<<"shift "<<i<<": " << decrypt(k,i) <<endl;
                }
            }
}

int main(){
    cout<<"do you want to encode or decode a message?(e or d) ";
    char choice;
    cin>>choice;

    if(choice=='e'){
        cout<<"enter the message to encode ";
        string message;
        cin.ignore();
        getline(cin,message);
        cout<<"enter keyword ";
        string key;
        cin.ignore();
        getline(cin,key);

        cout<<encrypt(message,key);
    }
    else if(choice=='d'){
        cout<<"do you know the keyword?(y or n) ";
        char brain;
        cin>>brain;

        if(brain=='y'){         
            cout<<"enter the message to decode ";
            string message;
            cin.ignore();
            getline(cin,message);
            cout<<"enter the keyword ";
            string key;
            cin.ignore();
            getline(cin,key);
            cout<<"the decoded message is "<<decrypt2(message,key);
        }

        else if(brain=='n'){
            cout<<"enter message to decode ";
            string Message;
            cin.ignore();
            getline(cin,Message);
            cout<<"enter the keyword";
            string key;
            top(Message);
            cout<<"satisfied?(y or n) ";
            char saty;
            cin>>saty;
            if(saty=='y'){
                cout<<"great! have a nice day :)";
                return 0;
            }
            else{
                backup(Message);
            }
        }
}
}