#include <iostream>

using namespace std;
 
class celula{
    public: 
        celula(){
            this->prox = NULL;
        }
        celula(string _string){
            this->String = _string;
            this->prox = NULL;
        }
        string String;
        celula* prox;

};

class lista{
    public:
        lista(){
            this->primeiro = NULL;
        };
        celula* primeiro;
};


void insere(lista* vetor, string stringInserida){
    celula* aux = vetor->primeiro;
	celula* celulaInserida = new celula();
    celulaInserida->String = stringInserida;

	if(aux == NULL){
		vetor->primeiro = celulaInserida;
		return;
	}

	if(aux->String.compare(stringInserida) > 0){
		celulaInserida->prox = aux;
		vetor->primeiro = celulaInserida;
		return;
	}

	while (aux->prox != NULL){
		if(aux->prox->String.compare(stringInserida) > 0)
			break;

		aux = aux->prox;
	}

    if(aux->String == stringInserida)
        return;

	celulaInserida->prox = aux->prox;
	aux->prox = celulaInserida;
}


int tamanhoString(char* string){
    int i = 0;

    while(string[i] != '\0')
        i++;

    return i;
}



int main() {
    lista* listaAmigos = new lista();
    lista* listaNaoAmigos = new lista();
    char maiorNome[20];
    int tamanhoMaiorString = 0;
    string maiorNomeString;


    while(true){
        string nomeString;
        string querSerAmigo;
        cin >> nomeString;

        if(nomeString == "FIM")
            break;

        cin >> querSerAmigo;


        if(querSerAmigo == "YES"){
            if(tamanhoMaiorString < nomeString.length()){
                maiorNomeString = nomeString;
                tamanhoMaiorString = nomeString.length();
            }
            insere(listaAmigos, nomeString);
        } else 
            insere(listaNaoAmigos, nomeString);
        }

    celula* aux = listaAmigos->primeiro;

    for (int i = 0; i < 2; i++)
    {
        while(aux != NULL){
            cout << aux->String << endl;
            aux = aux->prox;
        }
        aux = listaNaoAmigos->primeiro;
    }
    
    cout << endl << "Amigo do Habay:" << endl;
    cout << maiorNomeString << endl;
 
    return 0;
}
