//Rodrigo Alonso Torres Sotomayor
#include <iostream>
#include <string>

using namespace std;


char Cons[4] = {'<','>','=','!'};
char var[13] = {'A','B','C','1','2','3','4','5','6','7','8','9','0'};

bool Cons_comparacion(char v){
  for(int i=0; i<4;i++)
    if(v==Cons[i]) return true;
  return false;
}

bool Var_comparacion(char v){
  for(int i=0; i<13;i++)
    if(v==var[i]) return true;
  return false;
}


int main() {
  cout<<"¿Pertenece al lenguaje C++?"<<endl;

  string sentencia = "if(C!=3){}"; //ejemplos: "if A < B"   , "if((A<B)>C){}" , "if((A<B)>C;){}", "if(C!=3){}"
  //cin>>sentencia;
  cout<<sentencia<<endl;
  int tam = sentencia.length();

  //estructura inicial
  if(!(sentencia[0]=='i' && sentencia[1] == 'f' && sentencia[2] == '(' && sentencia[tam-3] == ')' && sentencia[tam-2] == '{' && sentencia[tam-1] == '}')) 
  {cout<<"No pertenece"<<endl;
   return 0;}

  for(int i=3;i<tam-3;i++){
    //colocacion de parentesis
    if(sentencia[i] == '('){
      int i_aux = i+1;
      for(;sentencia[i_aux] != ')' && i_aux < tam-3;i_aux++);
      if(i_aux<tam-1 && sentencia[i_aux] != ')'){
        cout<<"No pertenece"<<endl; return 0;
      }
      i++;
    }
    if(sentencia[i]== ')') i++;

    
    //confirmacion de variables
    if(!(Var_comparacion(sentencia[i]) || Cons_comparacion(sentencia[i]))){
      
      cout<<"No pertenece "<<endl; return 0;
    }
      
  }
  cout<<"si pertenece"<<endl;return 0;
    
}
