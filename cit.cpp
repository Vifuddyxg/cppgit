#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
bool termbool = 0;
string prox, proy;
int nrmagic = 0;
vector<string> nuvim = {"hello", "buna"};
vector<string> invim = {"hello world, merge", "bin"};
vector<int>       fl = {2 , 1};  // locatia fisieruui
int ccd = 2;          //  0       1     2      3         
vector<string> nmlc = {"hidden", "/" , "~" , "bin" , "documents", "home"};
vector<int>    lclc = {0   ,      0 ,   5  ,   1    ,    2  ,        1  };
bool vimnou = 0;
void help(){cout<<"help\nls\ncat\ncd\nrn\nvim"<<endl;}
void ls(){


for(int i = 0;i < nmlc.size();i++){
if(lclc[i] == ccd){
	cout<<nmlc[i]<<"  ";}}

for(int i = 0;i < nuvim.size();i++){
if(fl[i] == ccd){
	cout<<nuvim[i]<<"  ";}}

cout<<"\n";
}
void vim(int nr){
  bool vterb = 1;
  
  string vimadd , vimterm;
  cout << "\033[2J\033[1;1H";
  cout<<"\""<<nuvim[nr]<<"\"";
  if(vimnou == 1){cout<<"        prevous text:\n"<<invim[nr]<<endl<<"              copy and paste the text above if you want to edit it";} 
  else{cout<<"  [new]";}
  cout<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, vimadd);
  if(vimadd == ":wq!"){cout << "\033[2J\033[1;1H"; vterb = 0;}
  else if (vimadd == ":q!" && vimnou == 0){cout << "\033[2J\033[1;1H";nuvim.erase(nuvim.begin() + nr);fl.erase(fl.begin() + nr); invim.erase(invim.begin() + nr); vterb = 0;}
  else if(vimadd == ":q!"){cout << "\033[2J\033[1;1H"; vterb = 0;}
  while(vterb == 1){
    cout<<"type :wq! to save and exit or :q! to exit with no changes\n";
    cin>>vimterm;
    if(vimterm == ":wq!"){invim[nr] = vimadd; cout << "\033[2J\033[1;1H"; vterb = 0;}
    else if(vimterm == ":q!" and vimnou == 1){cout << "\033[2J\033[1;1H"; vterb = 0;}
    else if(vimterm == ":q!"){cout << "\033[2J\033[1;1H";nuvim.erase(nuvim.begin() + nr);fl.erase(fl.begin() + nr); invim.erase(invim.begin() + nr); ;vterb = 0; cout<<"fisierul e sters";}
    else{cout<<"error\n";}
    
  }

  }
//}
void sintaxvim(){
vimnou = 1;
int verificarevim = 0;
  if(prox == "vim"){
    for(int i = 0;i < nuvim.size();i++){
     if(fl[i] == ccd){ if(proy == nuvim[i]){verificarevim = 1; vimnou = 1;vim(i);return;}}}  
  if(verificarevim == 0){nuvim.push_back(proy);fl.push_back(ccd);invim.push_back("");cout<<invim.back()<<endl;nrmagic = invim.size() - 1;vimnou = 0;vim(nrmagic);}
  
}}
void cat(){
    for(int i = 0;i < nuvim.size();i++){
     if(fl[i] == ccd){ if(proy == nuvim[i]){cout<<invim[i]<<"\n";return;} } }
    cout<<"cit: "<<proy<<": No such file\n";

}
void rm(){
    for(int i = 0;i < nuvim.size();i++){
      if(fl[i] == ccd){if(proy == nuvim[i]){nuvim.erase(nuvim.begin() + i);fl.erase(fl.begin() + i); invim.erase(invim.begin() + i) ;return;}}  }
    cout<<"rm: cannot remove '"<<proy<<"': No such file\n";

}
void cd(string n){
	if(n == "/"){ccd = 1; return;}
	else if(n == "~"){ccd = 2; return;}
	else if(n == ".." && ccd == 1){return;}
	else if(n == ".."){ccd = lclc[ccd];return;}
  for(int i = 0;i < nmlc.size();i++){
	if(nmlc[i] == n && lclc[i] == ccd){ccd = i; return;}}
cout<<"cd: no such file or directory: "<<n<<"\n";
}
void mkdir(){
if(proy == "/"){cout<<"mkdir: cannot create directory ‘/’: File exists\n"; return ;}
if(proy == "~"){cout<<"mkdir: cannot create directory ‘/home/username’: File exists\n"; return ;}
for(int i = 0;i < nmlc.size();i++){
if(nmlc[i] == proy && lclc[i] == ccd){
	cout<<nmlc[i]<<"mkdir: cannot create directory ‘"<<nmlc[i]<<"’: File exists\n";return;}}
nmlc.push_back(proy);lclc.push_back(ccd);


}

int main(){
termbool = 1;
  while(termbool == 1){
    cout<< "username@hostname "<<nmlc[ccd]<<" $ ";
    cin>> prox ;
    if(prox == "exit"){ termbool = 0;break;}
    else if(prox == "ls") {ls(); continue;}
    else if(prox == "help"){help(); continue;}
    else if(prox == "clear"){cout<<"\033[2J\033[1;1H"; continue;}
    else if(prox == "vim"){cin>>proy; sintaxvim(); }
    else if(prox == "cat"){cin>>proy; cat();}
    else if(prox == "rm"){cin>>proy; rm();}
    else if(prox == "cd"){cin>>proy; cd(proy);}
    else if(prox == "mkdir"){cin>>proy; mkdir();}
    else{cout<<"cit: command not foundi: "<<prox<<"\n" ; continue;}
    }
  return 0;
}

