#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//ESERCIZIO 3!!!
// Struttura per memorizzare i dati di un singolo processo
struct Processo 
{
    int id;
    int arrivo;
    int durata;
    int priorita;
    int fine;
};

void schedulaProcessiES1(vector<Processo> vettProcessi) 
{
   
    for(int i=0;i<n-1;i++){
      vettProcessi[i].fine=vettProcessi[i].arrivo+vettProcessi[i].durata;

        vettProcessi.inizio[i+1]= vettProcessi[i].fine;

    }

    
    for(int i=0;i<n;i++){

        cout<< vettProcessi[i].id ;
        cout<vettProcessi[i].arrivo;
        cout<<vettProcessi[i].fine;
             

    }
    
    
    
    
    
}




void schedulaProcessiES2(vector<Processo> vettProcessi) 
{   
    //SCRIVI QUI IL CODICE PER L'ESERCIZIO 2

    vettProcessi[0].fine=vettProcessi[0].durata;
    
    for(int i=0;i<n-1;i++){ 
        
        
     

        if(vettProcessi[i].priorita>vettProcessi[i+1].priorita){
           swap(vettProcessi[i],vettProcessi[i+1]);

        }
        else if (vettProcessi[i].priorita==vettProcessi[i+1].priorita){
            if(vettProcessi.durata[i]>vettProcessi[i+1].durata)
                swap(vettProcessi[i],vettProcessi[i+1]);
            else if  if(vettProcessi.durata[i]==vettProcessi[i+1].durata)
             if(vettProcessi[i].inizio>vettProcessi[i+1].inizio)
             swap(vettProcessi[i],vettProcessi[i+1]);

    }
    }
    for(int i=0;i<n;i++){
        vettProcessi[i].fine=vettProcessi[i].arrivo+vettProcessi[i].durata;

        vettProcessi.inizio[i+1]= vettProcessi[i].fine;
               
    }


    for(int i=0;i<n;i++){

        cout<< vettProcessi[i].id ;
        cout<vettProcessi[i].arrivo;
        cout<<vettProcessi[i].fine;
             

    }

}


int main()
{
    ifstream file("input.txt");
    
    // Controllo se il file esiste e si apre correttamente
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }

    int n;
    file >> n; // Legge il numero totale di processi dalla prima riga

    vector<Processo> vettProcessi(n);

    // Popola il vettore di processi
    for (int i = 0; i < n; i++) 
    {
        file >> vettProcessi[i].id 
             >> vettProcessi[i].arrivo 
             >> vettProcessi[i].durata 
             >> vettProcessi[i].priorita;
    }
    
    file.close();

    //Test esercizio 1
    schedulaProcessiES1(vettProcessi);
    
    //Test esercizio 2
    schedulaProcessiES2(vettProcessi);
    return 0;
}
