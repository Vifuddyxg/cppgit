#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool termbool = 0;
string prox, proy;
string vimadd , vimterm, vimbool;
vector<string> nuvim = {"hello"};
vector<string> invim = {"hello world, merge"};

void help(){cout<<"info bla bla"<<endl;}
void ls(){
cout<<"help  vim  git  ";
for(int i = 0;i < nuvim.size();i++)cout<<nuvim[i]<<"  "; cout<<endl;
}
void vim(int nr){
  termbool = 0;



}
void sintax(){
int verificarevim = 0;
  if(prox == "vim"){
    for(int i = 0;i < size(nuvim);i++){
      if(proy == nuvim[i]){verificarevim = 1; cout<<invim[i]<<endl;}}  
  if(verificarevim == 0){nuvim.push_back(proy);invim.push_back("merge ok");cout<<invim.back()<<endl;}
  }
}

void terminal(){
termbool = 1;
  while(termbool == 1){
    cout<< "username@hostname ~ $ ";
    cin>> prox ;
    if(prox == "exit"){ termbool = 0;break;}
    if(prox == "ls") {ls(); continue;}
    if(prox == "help"){help(); continue;}
    cin>> proy;
    sintax(); 
    }
}

int main(){

  terminal();

  return 0;
}
