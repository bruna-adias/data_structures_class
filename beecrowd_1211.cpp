#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class tipoCelula {
	public:
		tipoCelula(){
			next = NULL;
		};
		char value[250];
		tipoCelula* next;
};

class lista {
	public:
		lista(){
			topo = NULL;
		};
		tipoCelula* topo;
};


void insere(lista* vetor, char stringInserida[250], int tamanho){
	int i = 0;
	tipoCelula* aux = vetor->topo;
	tipoCelula* celulaInserida = new tipoCelula();
	strcpy(celulaInserida->value, stringInserida);

	if(aux == NULL){
		vetor->topo = celulaInserida;
		return;
	}

	if(strcmp(aux->value, stringInserida) > 0){
		celulaInserida->next = aux;
		vetor->topo = celulaInserida;
		return;
	}

	while (aux->next != NULL){
		if(strcmp(aux->next->value, stringInserida) > 0)
			break;

		aux = aux->next;
	}

	celulaInserida->next = aux->next;
	aux->next = celulaInserida;
}
 
int main() {
    
    int quantidadeDeCasos;

    while(scanf("%d", &quantidadeDeCasos) == 1){
		lista* vetorStrings = new lista();

		for (int i = 0; i < quantidadeDeCasos; i++)
		{
			char stringProvisoria[250];
			scanf("%s", stringProvisoria);

			insere(vetorStrings, stringProvisoria, i);
		}

    int numeroCaracteresEconomizados = 0;

	tipoCelula* aux = vetorStrings->topo;
	
	while(aux->next != NULL){
		for(int j = 0; aux->value[j]; ++j){
			if(aux->value[j] == aux->next->value[j])
				numeroCaracteresEconomizados++;
			else
				break;
		}

		aux = aux->next;
	}

    cout << numeroCaracteresEconomizados << endl;
 
    }

    return 0;
}



