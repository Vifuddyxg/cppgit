#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
bool termbool = 0;
string prox, proy;
int nrmagic = 0;
vector<string> nuvim = {"hello"};
vector<string> invim = {"hello world, merge"};
bool vimnou = 0;
void help(){cout<<"info bla bla"<<endl;}
void ls(){

for(int i = 0;i < nuvim.size();i++)cout<<nuvim[i]<<"  "; cout<<endl;
}
void vim(int nr){
  bool vterb = 1;
  
  string vimadd , vimterm;
  cout << "\033[2J\033[1;1H";
  cout<<"\""<<nuvim[nr]<<"\"";
  if(vimnou == 1){cout<<"        prevous text:\n"<<invim[nr]<<endl<<"              copy and paste the text above if you want to edit it";} 
  cout<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, vimadd);
  if(vimadd == ":wq!"){cout << "\033[2J\033[1;1H"; vterb = 0;}
  else if (vimadd == ":q!" && vimnou == 0){cout << "\033[2J\033[1;1H";nuvim.erase(nuvim.begin() + nr); invim.erase(invim.begin() + nr); vterb = 0;}
  else if(vimadd == ":q!"){cout << "\033[2J\033[1;1H"; vterb = 0;}
  while(vterb == 1){
    cout<<"type :wq! to save and exit or :q! to exit with no changes\n";
    cin>>vimterm;
    if(vimterm == ":wq!"){invim[nr] = vimadd; cout << "\033[2J\033[1;1H"; vterb = 0;}
    else if(vimterm == ":q!" and vimnou == 1){cout << "\033[2J\033[1;1H"; vterb = 0;}
    else if(vimterm == ":q!"){cout << "\033[2J\033[1;1H";nuvim.erase(nuvim.begin() + nr); invim.erase(invim.begin() + nr); ;vterb = 0; cout<<"fisierul e sters";}
    else{cout<<"error\n";}
    
  }

  }
//}
void sintaxvim(){
vimnou = 1;
int verificarevim = 0;
  if(prox == "vim"){
    for(int i = 0;i < nuvim.size();i++){
      if(proy == nuvim[i]){verificarevim = 1; vimnou = 1;vim(i);return;}}  
  if(verificarevim == 0){nuvim.push_back(proy);invim.push_back("");cout<<invim.back()<<endl;nrmagic = invim.size() - 1;vimnou = 0;vim(nrmagic);}
  
}}
void cat(){
    for(int i = 0;i < nuvim.size();i++){
      if(proy == nuvim[i]){cout<<invim[i]<<"\n";return;}  }
    cout<<"cit: "<<proy<<": No such file\n";

}
int main(){
termbool = 1;
  while(termbool == 1){
    cout<< "username@hostname ~ $ ";
    cin>> prox ;
    if(prox == "exit"){ termbool = 0;break;}
    else if(prox == "ls") {ls(); continue;}
    else if(prox == "help"){help(); continue;}
    else if(prox == "clear"){cout<<"\033[2J\033[1;1H"; continue;}
    else if(prox == "vim"){cin>>proy; sintaxvim(); }
    else if(prox == "cat"){cin>>proy; cat();}
    else{cout<<"cit: command not foundi: "<<prox<<"\n" ; continue;}
    }
  return 0;
}

