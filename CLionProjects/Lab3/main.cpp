#include <iostream>
#include <fstream>
#include <vector>
//#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

struct IFF{
private:
    int pos;
    string cap;
    string body;
public:

    void ifcheck(string &s){
        char ss[s.length()];
        for (int i = 0; i<s.length();i++){
            ss[i] = s[i];
        }
        if (strchr(ss,'(')-ss>-1 && strchr(ss,')')-ss>-1) {
            int t = strchr(ss,'(')-ss+1;
            while (ss[t] != ')'){
                cap += ss[t];
                t++;
            }
            pos=t;
        }
    }

    void write(int &nn,string &s,int &ty){
        while(s[0]==' '){s.erase(0,1);}
        for(int t = 0; t<s.length();t++){
            if(s[t]=='\r'){s.erase(t,1);}
            if(s[t]=='\n'){s.erase(t,1);}
        }
        char ss[s.length()+1];
        for (int i = 0; i<s.length();i++){
            ss[i] = s[i];
        }
        if(nn == 3 && ty==1){
            for (int i = pos;i<s.length();i++){
                if(s[i]==';'){body+=s[i];nn=0;}
                if(nn==3){body+=s[i];}
            }
        }
        if(nn == 3 && ty==0){
            for (int i = 0;i<s.length();i++){
                if(s[i]==';'){body+=s[i];nn=0;}
                if(nn==3){body+=s[i];}
            }
        }
        if(nn == 4 && ty==1){
            for(int i = 0;i<s.length();i++){
                if(s[i]=='{'){pos=i;}
            }
            for(int i = pos+1;i<s.length();i++){
                if(nn==4 && s[i]=='}'){body+=s[i];nn=0;}
                if(nn==4){body+=s[i];}
            }
        }
        if(nn==4 && ty==0){
            for(int i = 0;i<s.length();i++){
                if(nn==4 && s[i]=='}'){nn=0;}
                if(nn==4){body+=s[i];}
            }
        }
    }

    string get(ofstream &out){
        cout<<cap<<endl;
        out<<"Условие if:   "+cap<<endl;
        cout<<body<<endl;
        out<<"Тело if:   "+body<<endl;
        return cap;
        return body;
    }
};

struct Forr{
private:
    int pos;
    string pre;
    string inn;
    string aft;
    string body;
public:

    void check(string &s){
        char ss[s.length()];
        for (int i = 0; i<s.length();i++){
            ss[i] = s[i];
        }
        if (strchr(ss,'(')-ss>-1 && strchr(ss,')')-ss>-1) {
            int i = strchr(ss,'(')-ss+1;
            while (ss[i] != ';' && ss[i] != '('){
                pre += ss[i];
                i++;
            }
            if (ss[i] == ';') {
                i++;
            }
            while (ss[i] != ';'){
                inn += ss[i];
                i++;
            }
            if (ss[i] == ';') {
                i++;
            }
            while (ss[i] != ')'){
                aft += ss[i];
                i++;
            }
            pos=i;
        }
    }

    void write(int &nn,string &s,int &ty){
        while(s[0]==' '){s.erase(0,1);}
        for(int t = 0; t<s.length();t++){
            if(s[t]=='\r'){s.erase(t,1);}
            if(s[t]=='\n'){s.erase(t,1);}
        }
        char ss[s.length()];
        for (int i = 0; i<s.length();i++){
            ss[i] = s[i];
        }
        if(nn == 1 && ty==1){
            for (int i = pos;i<s.length();i++){
                if(s[i]==';'){body+=s[i];nn=0;}
                if(nn==1){body+=s[i];}
            }
        }
        if(nn == 1 && ty==0){
            for (int i = 0;i<s.length();i++){
                if(s[i]==';'){body+=s[i];nn=0;}
                if(nn==1){body+=s[i];}
            }
        }
        if(nn == 2 && ty==1){
            for(int i = 0;i<s.length();i++){
                if(s[i]=='{'){pos=i;}
            }
            for(int i = pos+1;i<s.length();i++){
                if(nn==2 && s[i]=='}'){/*body+=s[i];*/nn=0;}
                if(nn==2 && s[i]!='}'){body+=s[i];}
            }
        }
        if(nn==2 && ty==0){
            for(int i = 0;i<s.length();i++){
                if(nn==2 && s[i]=='}'){nn=0;}
                if(nn==2 && s[i]!='}'){body+=s[i];}
            }
        }
    }

    string get(ofstream &out){
        cout<<pre<<endl;
        out<<"Первый блок for:   "+pre<<endl;
        cout<<inn<<endl;
        out<<"Второй блок for:   "+inn<<endl;
        cout<<aft<<endl;
        out<<"Третий блок for:   "+aft<<endl;
        cout<<body<<endl;
        out<<"Тело for:   "+body<<endl;
        return pre;
        return inn;
        return aft;
        return body;
    }
};

struct switt{
private:
    int pos;
    int t=0;
    string in;
    string prom;
    vector <string> cases;
    vector <string> incas;
public:
    void check(string &s){
        char ss[s.length()];
        for (int i = 0; i<s.length();i++){
            ss[i] = s[i];
        }
        if (strchr(ss,'(')-ss>-1 && strchr(ss,')')-ss>-1) {
            int t = strchr(ss,'(')-ss+1;
            while (ss[t] != ')'){
                in += ss[t];
                t++;
            }
            pos=t;
        }
    }
    void write(int &nn,string &s,int &ty){
        //while(s[0]==' '){s.erase(0,1);}
        for(int t = 0; t<s.length();t++){
            if(s[t]=='	'){while(s[t]=='	')s.erase(t,1);}
            if(s[t]=='\r'){s.erase(t,1);}
            if(s[t]=='\n'){s.erase(t,1);}
        }
        if(ty==1) {
            for (int i = 0; i < s.length(); i++) {
                if(s[i]=='{'){pos=i;}
            }
            for (int i = pos;i<s.length();i++) {
                if (t == 1 && s[i] == 'd' && s[i + 1] == 'e' && s[i + 2] == 'f' && s[i + 3] == 'a' && s[i + 4] == 'u' &&
                    s[i + 5] == 'l' && s[i + 6] == 't' && s[i + 7] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 2;
                    }
                }
                if (t == 1 && s[i] == 'd' && s[i + 1] == 'e' && s[i + 2] == 'f' && s[i + 3] == 'a' && s[i + 4] == 'u' &&
                    s[i + 5] == 'l' && s[i + 6] == 't' && s[i + 7] == ':') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 2;
                    }
                }
                if (t == 1 && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 's' && s[i + 3] == 'e' && s[i + 4] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 1;
                    }
                }
                if (t == 0 && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 's' && s[i + 3] == 'e' && s[i + 4] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 1;
                    }
                }
                if (t == 1 && s[i] != ':' && s[i] != '}') {
                    prom += s[i];
                }
                if (t == 2 && s[i] != ':' && s[i] != '}') {
                    prom += s[i];
                }
                if (t == 2 && s[i] == '}') {
                    t = 3;
                    incas.push_back(prom);
                    prom.erase();
                }
            }
        }
        if(ty==0){
            for(int i=0;i<s.length();i++){
                if (t == 1 && s[i] == 'd' && s[i + 1] == 'e' && s[i + 2] == 'f' && s[i + 3] == 'a' && s[i + 4] == 'u' &&
                    s[i + 5] == 'l' && s[i + 6] == 't' && s[i + 7] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 2;
                    }
                }
                if (t == 1 && s[i] == 'd' && s[i + 1] == 'e' && s[i + 2] == 'f' && s[i + 3] == 'a' && s[i + 4] == 'u' &&
                    s[i + 5] == 'l' && s[i + 6] == 't' && s[i + 7] == ':') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 2;
                    }
                }
                if (t == 1 && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 's' && s[i + 3] == 'e' && s[i + 4] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        incas.push_back(prom);
                        prom.erase();
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 1;
                    }
                }
                if (t == 0 && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 's' && s[i + 3] == 'e' && s[i + 4] == ' ') {
                    if (s[i - 1] == ' ' || s[i - 1] == '(' || s[i - 1] == '{' || s[i - 1] == ';' || s[i - 1] == ':' ||
                        s[i - 1] == '}' || s[i - 1] == ')' || s[i - 1] == '[' || s[i - 1] == ']' || s[i - 1] == '&' ||
                        s[i - 1] == '|' || s[i - 1] == '	') {
                        while (s[i] != ':') {
                            prom += s[i];
                            i++;
                        }
                        prom += ':';
                        cases.push_back(prom);
                        prom.erase();
                        t = 1;
                    }
                }
                if (t == 1 && s[i] != ':' && s[i] != '}') {
                    prom += s[i];
                }
                if (t == 2 && s[i] != ':' && s[i] != '}') {
                    prom += s[i];
                }
                if (t == 2 && s[i] == '}') {
                    t = 3;
                    incas.push_back(prom);
                    prom.erase();
                    nn=0;
                }
            }
        }
    }

    string get(ofstream &out){
        cout<<in<<endl;
        out<<"Условие switch:   "+in<<endl;
        for(int i=0;i<incas.size();i++) {
            cout << cases[i]<<endl;
            cout<< incas[i] << endl;
            out<<cases[i]+"  "+incas[i]<<endl;
        }
        return in;
    }
};

int main(void)
{
    string line;
    int nn = 0;
    int ty;
    IFF qq;
    Forr rew;
    switt dd;
    string lline = "  ";
    ifstream in("C:/Users/admin/CLionProjects/Lab3/1.txt");
    ofstream out("C:/Users/admin/CLionProjects/Lab3/2.txt", ios_base::out);
    if (in.is_open() && out.is_open()) {
        while(getline(in, line)){
            lline = "  ";
            //int i=0;
            //while(line[i]==' '){line.erase(i,1);}
            lline += line;

            for (int i = 0; i < lline.length(); i++) {
                if (nn!=5 && nn!=6 && lline[i-1]==' ' && lline[i]=='f' && lline[i+1]=='o' && lline[i+2]=='r' && lline[i+3]=='(') {
                    rew.check(lline);
                    //rew.get();
                    nn = 1;
                    ty = 1;
                }
                if (nn!=5 && nn!=6 && lline[i-1]==' ' && lline[i]=='f' && lline[i+1]=='o' && lline[i+2]=='r' && lline[i+3]==' ') {
                    rew.check(lline);
                    //string ret = rew.get();
                    nn = 1;
                    ty = 1;
                }
                if(nn == 1 && lline[i]=='{'){
                    nn = 2;
                    ty = 1;
                }
                if (lline[i-1]==' ' && lline[i]=='i' && lline[i+1]=='f' && lline[i+2]=='(') {
                    qq.ifcheck(lline);
                    //string ret = qq.get();
                    nn = 3;
                    ty = 1;
                }
                if (lline[i-1]==' ' && lline[i]=='i' && lline[i+1]=='f' && lline[i+2]==' ') {
                    qq.ifcheck(lline);
                    //string ret = qq.get();
                    nn = 3;
                    ty = 1;
                }
                if (nn == 3 && lline[i]=='{') {
                    nn = 4;
                    ty = 1;
                }
                if(lline[i-1]==' ' && lline[i]=='s' && lline[i+1]=='w' && lline[i+2]=='i' && lline[i+3]=='t' && lline[i+4]=='c' && lline[i+5]=='h' && lline[i+6]==' '){
                    dd.check(lline);
                    //dd.get();
                    nn = 5;
                    ty = 1;
                }
                if(lline[i-1]==' ' && lline[i]=='s' && lline[i+1]=='w' && lline[i+2]=='i' && lline[i+3]=='t' && lline[i+4]=='c' && lline[i+5]=='h' && lline[i+6]=='('){
                    dd.check(lline);
                    //dd.get();
                    nn = 5;
                    ty = 1;
                }
                if (nn == 5 && lline[i]=='{') {
                    nn = 6;
                    ty = 1;
                }
            }


            if (nn == 1 || nn == 2) {
                rew.write(nn,lline,ty);
                //string ter = rew.get();
            }
            if (nn == 3 || nn == 4) {
                qq.write(nn,lline,ty);
                //string ter = qq.get();
            }
            if (nn == 5 || nn == 6) {
                dd.write(nn,lline,ty);
                //dd.get();
            }
            cout<<line<<endl;
            out<<line<<endl;
            ty = 0;
        }
        rew.get(out);
        qq.get(out);
        dd.get(out);
    }
    else
        cout<<"Error!"<<endl;

    in.close();
    out.close();
    return 0;
}