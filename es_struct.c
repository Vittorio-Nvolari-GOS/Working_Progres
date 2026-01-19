/*
ESERCIZIO STRUCT IN C - GESTIONE LIBRERIA
==========================================

OBIETTIVO: Completa il programma per gestire una libreria di libri

COSA DEVI FARE:
1. Definisci la struct Libro con i seguenti campi:
   - id (int)
   - titolo (array di 50 caratteri)
   - autore (array di 30 caratteri)
   - anno (int)
   - prezzo (float)

2. Implementa le seguenti funzioni:
   - void aggiungiLibro(Libro *libreria, int *num_libri)
   - void visualizzaLibri(Libro *libreria, int num_libri)
   - void cercaLibro(Libro *libreria, int num_libri)
   - void modificaPrezzo(Libro *libreria, int num_libri)
   - void valoreTotale(Libro *libreria, int num_libri)

3. Completa la funzione main() con un menu interattivo

VINCOLI:
- Usa un array statico di massimo 100 libri
- Usa strcmp() per confrontare stringhe
- Gestisci il caso di libreria vuota
- Valida l'input dell'utente

SUGGERIMENTI:
=============
- Per leggere una stringa intera con spazi: scanf(" %[^\n]", variabile);
- Per confrontare stringhe: strcmp(str1, str2) == 0
- Incremento di un puntatore: (*num_libri)++
- Accesso a campo di struct: libreria[i].titolo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Libro
{
    int id;
    char titolo[50];
    char autore[30];
    int anno[4];
    float prezzo;
}Libro;




// TODO: Implementa questa funzione
void aggiungiLibro(Libro *libreria, int *num_libri) 
{
    num_libri++;
    int i= num_libri;
    libreria[i].id=num_libri;
    printf("Quale è il titolo? \n");
    fgets(libreria[i].titolo,50,stdin);
    printf("Quale è l'autore? \n");
    fgets(libreria[i].autore,30,stdin);
    printf("Quale è l'anno? \n");
    scanf("%d",&libreria[i].anno);
    printf("Quale è il prezzo? \n");
    scanf("%f",&libreria[i].prezzo);       
    // Chiedi id, titolo, autore, anno, prezzo
    // Aggiungi il libro all'array
    // Incrementa num_libri
}

// TODO: Implementa questa funzione
void visualizzaLibri(Libro *libreria, int num_libri) 
{
    if(num_libri==0)
        printf("Nessun libro gay");
    else
    {
    for(int i=0;i<num_libri;i++)
        {
            printf("--------------------------------------");
            printf("%d\n",libreria[i].id);
            printf("%c\n",libreria[i].titolo);
            printf("%c\n",libreria[i].autore);
            printf("%d\n",libreria[i].anno);
            printf("%f\n",libreria[i].prezzo);
            printf("--------------------------------------");

        }
    }
      // Se num_libri == 0, stampa "Nessun libro"
    // Altrimenti, stampa tutti i libri in un formato leggibile
}

// TODO: Implementa questa funzione
void cercaLibro(Libro *libreria, int num_libri) 
{
    char tmp[50];
    int i=1;
    printf("inserisci il titolo che vuoi cercare: ");
    fgets(tmp,50,stdin);
    for(i=1;i<num_libri;i++)
    {
        if(strcmp(tmp,libreria[i].titolo)==0)
        {
            printf("%d\n",libreria[i].id);
            printf("%c\n",libreria[i].titolo);
            printf("%c\n",libreria[i].autore);
            printf("%d\n",libreria[i].anno);
            printf("%f\n",libreria[i].prezzo);
        }else{
            printf("Non trovato");
        }
    }
    



    

    // Chiedi il titolo da cercare
    // Usa strcmp() per confrontare i titoli
    // Se trovato, stampa i dettagli del libro
    // Se non trovato, stampa "Non trovato"
}

// TODO: Implementa questa funzione
void modificaPrezzo(Libro *libreria, int num_libri) 
{
    float tmp=0;
    printf("inserisci l'id del libro");
    scanf("%f",&tmp);
    for(int i=0;i<num_libri;i++)
    {
        if(tmp==libreria[i].id)
        {
            printf("Il prezzo attuale è :%f\n",libreria[i].prezzo);
            printf("inserisci il prezzo nuovo: \n");
            scanf("%f",&libreria[i].prezzo);
        }
        else
            printf("Libro non trovato");
    }

    // Chiedi l'ID del libro
    // Cerca il libro per ID
    // Se trovato, chiedi il nuovo prezzo e aggiornalo
    // Se non trovato, stampa "Non trovato"
}

// TODO: Implementa questa funzione
void valoreTotale(Libro *libreria, int num_libri)
{
    float somma=0;
    for(int i=0;i<num_libri;i++)
    {
        somma+=libreria[i].prezzo;
    }
    printf("Il valore totale è: %f ",somma);

    
    // Somma i prezzi di tutti i libri
    // Stampa il valore totale
}

int main() 
{
    Libro* libri[100];
    int scelta=0;
    int* numLibri=0;
    do
    {
        printf("______Menu_____\n");
        printf("1. Aggiungi libro\n");
        printf("2. Visualizza libri\n");
        printf("3. Cerca libro\n");
        printf("4. Modifica prezzo\n");
        printf("5. Valore totale\n");
        printf("6. Esci");

        switch (scelta)
        {
        case 1:
            aggiungiLibro(libri,*numLibri);
            break;
        case 2:
            void visualizzaLibri(libri,numLibri);
            break;
        case 3:
            cercaLibro(libri,numLibri);
            break;
        case 4:
            modificaPrezzo(libri,numLibri);
            break;
        case 5:
            valoreTotale(libri,numLibri);
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    
    } while (scelta==6 );
    
    
   
   
    
    return 0;
}
