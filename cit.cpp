#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool termbool = 0;
string prox, proy;
int nrmagic;
vector<string> nuvim = {"hello"};
vector<string> invim = {"hello world, merge"};

void help(){cout<<"info bla bla"<<endl;}
void ls(){
cout<<"help  vim  git  ";
for(int i = 0;i < nuvim.size();i++)cout<<nuvim[i]<<"  "; cout<<endl;
}
void vim(int nr){
  bool termbool = 0;
  bool vterb = 1;
  string vimadd , vimterm;
  cout << "\033[2J\033[1;1H";
  cout<<"\""<<nuvim[nr]<<"\"";
  if(nuvim[nr].size() > 0)cout<<"        prevous text:\n"<<invim[nr]<<endl<<"              copy and paste the text above if you want to edit it";  
  cout<<endl;
  cin>>vimadd;
  if(vimadd == ":wq!" or vimadd == ":q!"){cout << "\033[2J\033[1;1H";termbool = 1 ;vterb = 0;}
  while(vterb == 1){
    cout<<"type :wq! to save and exit or :q! to exit with no changes\n";
    cin>>vimterm;
    if(vimterm == ":wq!"){invim[nr] = vimadd; termbool = 1;cout << "\033[2J\033[1;1H"; vterb = 0;}
    else if(vimterm == ":q!"){termbool = 1;cout << "\033[2J\033[1;1H"; vterb = 0;}
    else{cout<<"error\n";}
  }

  }
//}
void sintax(){
int verificarevim = 0;
  if(prox == "vim"){
    for(int i = 0;i < nuvim.size();i++){
      if(proy == nuvim[i]){verificarevim = 1; vim(i);}}  
  if(verificarevim == 0){nuvim.push_back(proy);invim.push_back("");cout<<invim.back()<<endl;nrmagic = invim.size() - 1;vim(nrmagic);}
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
    