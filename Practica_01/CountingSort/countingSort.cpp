#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

int getMax(int a[],int b)
{
   int max = a[0];
   for(int i = 1; i<b; i++)
   {
      if(a[i] > max) max = a[i];
   }
   return max;
}


void countSort(int a[],int b)
{
    int size = b;
    int output[size];
    int max = getMax(a,size);
    int count[max+1];

    for(int i = 0; i<max+1; i++) count[i] = 0;
    for(int i = 0; i <size; i++) count[a[i]]++;
    for(int i = 1; i<max+1; i++) count[i] += count[i-1];

    for(int i = size-1; i>=0; i--)
    {
        output[count[a[i]]] = a[i];
        count[a[i]] -= 1;
    }

    for(int i = 0; i<size; i++)
    {
        a[i] = output[i];
    }
}
void agregar_valor(int a[],int carga)
{
    fstream texto("../valores_10_5.txt");
    int aux;
    for (int i = 0; i < carga; i++)
    {
        texto >> aux;
        a[i] = aux;
    }
    texto.close();
}
/*
int getMax(const vector<int> &a)
{
   int max = a[0];
   for(int i = 1; i<a.size(); i++)
   {
      if(a[i] > max) max = a[i];
   }
   return max;
}


void countSort(vector<int> &a)
{
    int size = a.size();
    int output[size];
    int max = getMax(a);
    int count[max+1];

    for(int i = 0; i<max+1; i++) count[i] = 0;
    for(int i = 0; i <size; i++) count[a[i]]++;
    for(int i = 1; i<max+1; i++) count[i] += count[i-1];

    for(int i = size-1; i>=0; i--)
    {
        output[count[a[i]]] = a[i];
        count[a[i]] -= 1;
    }

    for(int i = 0; i<size; i++)
    {
        a[i] = output[i];
    }
}

void agregar_valor(vector<int> &a,int carga)
{
    fstream texto("../valores_10_5.txt");
    int aux;
    for (int i = 0; i < carga; i++)
    {
        texto >> aux;
        a.push_back(aux);
    }
    texto.close();
}
*/
void set_data(int tamanho,float tiempo)
{
  fstream helper;
  helper.open("valores_C++_2.txt");
  helper.seekg (0,helper.end);
  helper << tamanho << " , ";
  helper<<fixed<<setprecision(5)<<tiempo<<endl;
  helper.close();
}



int main()
{
  //vector<int> valores;
  int valores[100000];
  int val = 10;
  float t0,t1;
  for(int i= 10; i < 100000;i += val)
  {
    agregar_valor(valores,i);
    t0 = clock();
	  countSort(valores,i);
    t1 = clock();
    float tiempo = ((t1-t0)/CLOCKS_PER_SEC);
    set_data(i,tiempo);
    //valores.clear();
    val *= 2;
  }
  //valores.clear();
  agregar_valor(valores,100000);
  t0 = clock();
  countSort(valores,100000);
  t1 = clock();
  float tiempo = ((t1-t0)/CLOCKS_PER_SEC);
  set_data(100000,tiempo);
}
