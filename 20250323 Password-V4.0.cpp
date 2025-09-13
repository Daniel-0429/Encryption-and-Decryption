#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1)
    {
        srand(time(0));
        int choice;
        cout<<"==============================================================="<<endl;
        cout<<"Choices:"<<endl;
        cout<<"1.Encryption a string"<<endl;
        cout<<"2.Decryption a string"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"4.about"<<endl;
        cout<<"Your choice:";
        cin>>choice;
        if(choice==3){
            break;
        }
        if(choice==1){
            cout<<"The string you want to encryption:";
            string s;
            cin>>s;
            ifstream keyin("public_key.pem");
            string public_key;
            string bin;
            getline(keyin,bin);
            getline(keyin,public_key);
            getline(keyin,bin);
            keyin.close();
            int private_key;
            private_key=rand()%10;
            for(int i=0;i<s.size();++i){
                s[i]=32+(s[i]-32+private_key)%(126-32+1);
            }
            s=s+to_string(private_key);
            cout<<s<<endl;
            for(int i=0;i<s.size();++i){
                int key=public_key[i%public_key.size()]-'0';
                s[i]=s[i]^key;
            }
            cout<<"The encrypted string is:"<<s<<endl;
            #ifdef _WIN32
                system("pause");
            #endif
        }
        if(choice==2){
            cout<<"The string you want to decryption:";
            string s;
            cin>>s;
            ifstream keyin("public_key.pem");
            string public_key;
            string bin;
            getline(keyin,bin);
            getline(keyin,public_key);
            getline(keyin,bin);
            keyin.close();
            for(int i=0;i<s.size();++i){
                int key=public_key[i%public_key.size()]-'0';
                s[i]=s[i]^key;
            }
            int private_key;
            private_key=s[s.size()-1]-'0';
            s=s.substr(0,s.size()-1);
            cout<<s<<' '<<private_key<<endl;
            for(int i=0;i<s.size();++i){
                s[i]=32+(s[i]-32+(126-32+1-private_key))%(126-32+1);
            }
            cout<<"The decrypted string is:"<<s<<endl;
            #ifdef _WIN32
                system("pause");
            #endif
        }
        if(choice==4){
            cout<<"Passwd_Tools V4"<<endl;
            cout<<"Copyright (C) 2025 Daniel,All right reserved."<<endl;
            cout<<"This program is free software,you can redistribute it or modify"<<endl;
            cout<<"This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;"<<endl;
            cout<<"without even the implied warranty ofMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."<<endl;
            cout<<"See the GNU General Public License for more details."<<endl;
            #ifdef _WIN32
                system("pause");
            #endif
        }
    }
    cout<<"Thanks for using!"<<endl;
    return 0;
}