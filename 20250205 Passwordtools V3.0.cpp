#include <bits/stdc++.h>
using namespace std;
auto isFileEmpty() {
    std::ifstream ifs("key.pem");
    string a;
    if (!ifs) {
        return 1;
    }
    getline(ifs,a);
    if(a!="-----BEGIN CERTIFICATE-----"){
        return 2;
    }
    getline(ifs,a);
    if(a!="362279327400467793808645840313885617266263300763475354411872996874051355682240786357829330"){
        return 3;
    }
    getline(ifs,a);
    if(a!="-----END CERTIFICATE-----"){
        return 2;
    }
    ifs.close();
    return 4;
}
auto reserve(string pwd){
    string npwd;
    for(int i=pwd.size()-1;i>=0;--i){
        npwd=npwd+pwd[i];
    }
    return npwd;
}
auto Key(){
    std::ifstream ifs("key.pem");
    string a;
    getline(ifs,a);
    getline(ifs,a);
    return a;
}
int main(){
    std::srand(time(0));
    cout<<"Passwd_Tools V3.0"<<endl;
    cout<<"Copyright (C) 2025 Daniel,All right reserved."<<endl;
    cout<<"This program is free software,you can redistribute it or modify"<<endl;
    cout<<"This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY;"<<endl;
    cout<<"without even the implied warranty ofMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."<<endl;
    cout<<"See the GNU General Public License for more details."<<endl;
    cout<<"============================================================\n";
    cout<<"TIPS:If you have not been distributed a legitimate private key file, you are not allowed to see the decryption results. Contact your distributor to distribute the private key file for you."<<endl;
    cout<<"============================================================\n";
    auto y=isFileEmpty();
    if(y==1){
        cout<<"Failed to open private key file!"<<endl;
        system("pause");
        return 0;
    }else if(y==2){
        cout<<"Private key file format error!"<<endl;
        system("pause");
        return 0;
    }
    auto pk=Key();
    while(1){
        string pwd;
        cout<<"The password or the original string:";
        cin>>pwd;
        string s;
        cout<<"Encryption or Decryption?[E/D]:";
        cin>>s;
        cout<<"Caesar or Virginia Algorithm?[C/V]:";
        string swi;
        cin>>swi;
        if(s=="E"){
            if(swi=="C"){
                int key=rand();
                for(int i=0;i<pwd.size();++i){
                    if(pwd[i]>='A'&&pwd[i]<='Z'){
                        pwd[i]=((pwd[i]%' ')+key%10+pk[i]-'0')%26+'A';
                    }else if(pwd[i]>='a'&&pwd[i]<='z'){
                        pwd[i]=((pwd[i]%' ')+key%10+pk[i]-'0')%26+'a';
                    }else if(pwd[i]>0&&pwd[i]<128){
                        pwd[i]-=key%10;
                    }else{
                        pwd[i]+=key%10;
                    }
                }
                cout<<"Key:"<<key<<endl;
            }else if(swi=="V"){
                string keya;
                for(int i=0;i<pwd.size();++i){
                    int key=rand()%10;
                    keya=keya+static_cast<char>(key+'0');
                    if(pwd[i]>='A'&&pwd[i]<='Z'){
                        pwd[i]=((pwd[i]%' ')+i+key*2+pk[i]-'0')%26+'A';
                    }else if(pwd[i]>='a'&&pwd[i]<='z'){
                        pwd[i]=((pwd[i]%' ')+i+key*2+pk[i]-'0')%26+'a';
                    }else if(pwd[i]>='0'&&pwd[i]<='9'){
                        pwd[i]+=key;
                    }
                }
                cout<<"Key:"<<keya<<endl;
            }
            cout<<"Passwd:"<<pwd<<endl;
            pwd=reserve(pwd);
        }else if(s=="D"){
            if(swi=="C"){
                int key;
                cout<<"Key:";
                cin>>key;
                for(int i=0;i<pwd.size();++i){
                    if(pwd[i]>='A'&&pwd[i]<='Z'){
                        pwd[i]=((pwd[i]%' ')+24-key%10+26-pk[i]+'0')%26+'A';
                    }else if(pwd[i]>='a'&&pwd[i]<='z'){
                        pwd[i]=((pwd[i]%' ')+24-key%10+26-pk[i]+'0')%26+'a';
                    }else if(pwd[i]>0&&pwd[i]<128){
                        pwd[i]+=key%10;
                    }else{
                        pwd[i]-=key%10;
                    }
                }
            }else if(swi=="V"){
                string keya;
                cout<<"Key:";
                cin>>keya;
                for(int i=0;i<pwd.size();++i){
                    if(pwd[i]>='A'&&pwd[i]<='Z'){
                        pwd[i]=((pwd[i]%' ')+(26-i-2-(keya[i]-'0')*2)+26-pk[i]+'0')%26+'A';
                    }else if(pwd[i]>='a'&&pwd[i]<='z'){
                        pwd[i]=((pwd[i]%' ')+(26-i-2-(keya[i]-'0')*2)+26-pk[i]+'0')%26+'a';
                    }else if(pwd[i]>='0'&&pwd[i]<='9'){
                        pwd[i]-=(keya[i]-'0');
                    }
                }
            }
            cout<<((y==3)?("***"):(pwd))<<endl;
        }else{
            cout<<"We can't do this,please type again."<<endl;
            continue;
        }
        cout<<"Are you keep doing?[Y/n]:";
        string ans;
        cin>>ans;
        if(ans=="Y"){
            continue;
        }else if(ans=="n"){
            break;
        }else{
            cout<<"Your input is invalid. You have been automatically logged out of this tool."<<endl;
            break;
        }
    }
    return 0;
}