#include <iostream>
#include <fstream>
#include <stdio.h>
#include<cstring>
//#include <windows.h>
#include <string>

using namespace std;


int main(void){
	string line;
	string lline;
	string llline;
	int nn = 0;
    int tt = 0;
	int t = 0;
	int tc = 0;
	ifstream in("C:/Users/admin/CLionProjects/Lab2/1.txt");
	ofstream out("C:/Users/admin/CLionProjects/Lab2/2.txt", ios_base::out);
	if (in.is_open() && out.is_open()) {
		while(getline(in, line)) {
		  lline+=line;
		}
		for(int i = 0;i<lline.length();i++){
		  llline+=lline[i];
		  if(nn==0 && lline[i]=='>'){
		    out<<llline<<endl;
		    llline.erase();
		  }
		  if(lline[i]==';' || lline[i]=='(' || lline[i]=='{'){
		    nn=1;
		  }
		  if(nn==1 && lline[i]=='('){
		    t = 1;
		  }
		  if(nn==1 && lline[i]=='{'){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		    tc = tc+1;
		  }
		  if(nn==1 && lline[i]==';' && t==0 && tt==0){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		  }
      if(nn==1 && lline[i]==';' && t==0 && tt==1){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
        tc = tc-1;
        tt = 0;
		    out<<llline<<endl;
		    llline.erase();
		  }
		  if(nn==1 && lline[i]==')'){
        while(lline[i+1]==' '){
          lline.erase(i+1,1);
        }
		    t = 0;
		  }
		  if(nn==1 && lline[i]==')' && lline[i+1]!=';' && lline[i+1]!='{'){
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
        tt=1;
        tc=tc+1;
		  }
		  if(nn==1 && lline[i]=='}'){
		    tc=tc-1;
		    for(int y = 0;y<tc;y++){
			    out<<"    ";
		    }
		    out<<llline<<endl;
		    llline.erase();
		  }
    }
	}
	else
	cout<<"Error!"<<endl;

	in.close();
	out.close();
	return 0;
}
