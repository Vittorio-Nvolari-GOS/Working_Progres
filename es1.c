#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char nome[30];
    int eta;
}Dati;

int main() { 
    
   int scelta, lunghezza=0, i=0, j; 
   Dati *vettore = NULL;
    
   do
   {     
    printf("--- Menù ---\n");        
    printf("Scegli l'operazione da eseguire:\n");    
    printf("1. Inserisci\n");
    printf("2. Cancella\n");
    printf("3. Ricerca\n");
    printf("4. Visualizza\n"); 
    printf("5. Esci\n");
    printf("Scelta: "); 
    scanf(" %d", &scelta);

    switch (scelta) { 
         case 1: 
                 
                printf("Inserisci...\n");
                vettore = realloc(vettore, (i + 1) * sizeof(Dati)); 
                
                printf("Dammi il nome...\n");
                scanf("%s",vettore[i].nome);

                 printf("Dammi l'età...\n");
                scanf("%d",&vettore[i].eta);

                i++;
                lunghezza++;
                
                break; 

        case 2: 
                int k;
                char nome_cancella[30];

                printf("Cancella...\n");
                   
                printf("Dammi il nome...\n");
                scanf("%s",nome_cancella);

                for(j=0; j<=lunghezza; j++) {
                            if(strcmp(nome_cancella,vettore[j].nome)==0){
                                printf("%s, %d trovato in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1);

                                for (i=j; i<lunghezza-1; i++) {
                                     vettore[k]=vettore[k+1];
                                }
                            }
                    lunghezza--;
                    vettore = realloc(vettore, lunghezza * sizeof(Dati));           
                }        
                break; 
        
         case 3: 
                int opzione, eta_ricerca;
                char nome_ricerca[30];

                do{
                    
                    printf("Ricerca...\n");
                    printf("1. Nome\n");
                    printf("2. Età\n");
                    printf("3. Esci\n");
                    printf("Scelta: ");
                    scanf("%d",&opzione);
                
                    if (opzione==1){
                        printf("Dammi il nome...\n");
                        scanf("%s",nome_ricerca);

                        for(j=0; j<lunghezza; j++) {
                            if(strcmp(nome_ricerca,vettore[j].nome)==0){
                                printf("%s, %d in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1);
                            }
                        }
                    }
                
                    if (opzione==2){
                        printf("Dammi l'età...\n");
                        scanf("%d",&eta_ricerca);

                        for(j=0; j<lunghezza; j++) {
                            if(eta_ricerca==vettore[j].eta){
                                printf("%s, %d in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1);
                            }
                        }
                    }
                }while (opzione!=3);
                
                break;            
    
         case 4:
                
                printf("Visualizza...\n");
                printf("Inizio -> ");
                
                
                for(j=0; j<lunghezza; j++) {
                        printf("[%d, %s, %d] -> ", j+1, vettore[j].nome, vettore[j].eta );
                    }
                printf("Fine");
                printf("\n");
                printf("lunghezza vettore: %d\n", lunghezza);
                
                break; 
                        
      case 5:
                free(vettore); 
                return 0;             
      default: 
                       printf("Errore: Scelta non valida.\n"); 
        }   
   }while(scelta!=5);
   
   
   return 0; 
}

//TEORIA DELL'ESERCIZIO:
/*Il programma usa un puntatore a una struct dati per gestire alcune informazioni sulle persone.
L'aspetto più importante è l'uso della funzione realloc che aumenta lo spazio di una struct (all'inizio il
vettore è vuoto e il puntatore è impostato a NULL), questo permette di non sprecare memoria in anticipo,
diversamente da un array statico di dimensioni fisse.
L’accesso ai campi nome ed età è diretto, anche se abbiamo un puntatore, avviene attraverso l’utilizzo
dell'operatore punto perché l'indice tra parentesi quadre si occupa già di puntare alla cella corretta.
La cancellazione avviene per nome, per mia scelta ma potrebbe essere per età o posizione, tramite un
confronto tra stringhe. Individuato il dato da eliminare, il programma esegue uno spostamento a sinistra di
ogni elemento successivo a quello rimosso che viene copiato nella posizione precedente, sovrascrivendo di
fatto il dato da cancellare.
Al termine di questo spostamento, la lunghezza dell'array viene ridotta e la memoria viene nuovamente
ridimensionata con la realloc.
Infine, il programma si conclude sempre con la liberazione totale della memoria tramite la funzione free.
Come esercizio si potrebbero trasformare le varie opzioni delle voci di menù in funzioni.


Questo è un esercizio che implementa un sistema di gestione dinamico per un elenco di persone in C. Ecco i punti chiave:

Struttura dati
Una struct che memorizza nome ed età di una persona.

Concetto principale
Usa memoria dinamica con realloc() per espandere/ridurre l'array a seconda delle necessità, evitando di sprecare memoria allocando spazio fisso in anticipo.

Le 5 operazioni del menu:
Inserisci: Alloca spazio per un nuovo elemento e lo aggiunge in coda
Cancella: Cerca una persona per nome e la rimuove, spostando gli elementi successivi a sinistra
Ricerca: Trova persone per nome o per età
Visualizza: Mostra tutto l'elenco in formato [posizione, nome, eta]
Esci: Libera la memoria e termina
Aspetti tecnici importanti:
vettore = realloc(vettore, (i + 1) * sizeof(Dati)) → ridimensiona la memoria
vettore[i].nome → accede ai campi direttamente (l'indice [i] si occupa già della dereferenziazione del puntatore)
free(vettore) → libera la memoria allocata
Gestione manuale della lunghezza con la variabile lunghezza
Nota importante
Il codice ha un bug nella sezione di cancellazione (case 2): usa vettore[k] invece di vettore[i] nello spostamento degli elementi, e la variabile k non è mai inizializzata.

Come suggerito nel commento finale, il codice potrebbe essere migliorato trasformando le diverse operazioni del menu in funzioni separate.
*/

//ESERCZIO DA FARE:
