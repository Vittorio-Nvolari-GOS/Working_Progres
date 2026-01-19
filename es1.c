#include &lt;stdio.h&gt;
#include &lt;stdbool.h&gt;
#include &lt;string.h&gt;
#include &lt;stdlib.h&gt;

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
    printf(&quot;--- Menù ---\n&quot;);        
    printf(&quot;Scegli l&#39;operazione da eseguire:\n&quot;);    
    printf(&quot;1. Inserisci\n&quot;);
    printf(&quot;2. Cancella\n&quot;);
    printf(&quot;3. Ricerca\n&quot;);
    printf(&quot;4. Visualizza\n&quot;);
    printf(&quot;5. Esci\n&quot;);
    printf(&quot;Scelta: &quot;);
    scanf(&quot; %d&quot;, &amp;scelta);

    switch (scelta) {
         case 1:
                 
                printf(&quot;Inserisci...\n&quot;);

                vettore = realloc(vettore, (i + 1) * sizeof(Dati));
               
                printf(&quot;Dammi il nome...\n&quot;);
                scanf(&quot;%s&quot;,vettore[i].nome);

                 printf(&quot;Dammi l&#39;età...\n&quot;);
                scanf(&quot;%d&quot;,&amp;vettore[i].eta);

                i++;
                lunghezza++;
               
                break;

        case 2:
                int k;
                char nome_cancella[30];

                printf(&quot;Cancella...\n&quot;);
                   
                printf(&quot;Dammi il nome...\n&quot;);
                scanf(&quot;%s&quot;,nome_cancella);

                for(j=0; j&lt;=lunghezza; j++) {
                            if(strcmp(nome_cancella,vettore[j].nome)==0){
                                printf(&quot;%s, %d trovato in posizione %d\n&quot;, vettore[j].nome, vettore[j].eta, j+1);

                                for (i=j; i&lt;lunghezza-1; i++) {
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
                   
                    printf(&quot;Ricerca...\n&quot;);
                    printf(&quot;1. Nome\n&quot;);
                    printf(&quot;2. Età\n&quot;);
                    printf(&quot;3. Esci\n&quot;);
                    printf(&quot;Scelta: &quot;);
                    scanf(&quot;%d&quot;,&amp;opzione);
               
                    if (opzione==1){
                        printf(&quot;Dammi il nome...\n&quot;);
                        scanf(&quot;%s&quot;,nome_ricerca);

                        for(j=0; j&lt;lunghezza; j++) {
                            if(strcmp(nome_ricerca,vettore[j].nome)==0){
                                printf(&quot;%s, %d in posizione %d\n&quot;, vettore[j].nome, vettore[j].eta, j+1);
                            }
                        }
                    }
               
                    if (opzione==2){
                        printf(&quot;Dammi l&#39;età...\n&quot;);
                        scanf(&quot;%d&quot;,&amp;eta_ricerca);

                        for(j=0; j&lt;lunghezza; j++) {

                            if(eta_ricerca==vettore[j].eta){
                                printf(&quot;%s, %d in posizione %d\n&quot;, vettore[j].nome, vettore[j].eta, j+1);
                            }
                        }
                    }
                }while (opzione!=3);
               
                break;            
   
         case 4:
               
                printf(&quot;Visualizza...\n&quot;);
                printf(&quot;Inizio -&gt; &quot;);
               
               
                for(j=0; j&lt;lunghezza; j++) {
                        printf(&quot;[%d, %s, %d] -&gt; &quot;, j+1, vettore[j].nome, vettore[j].eta );
                    }
                printf(&quot;Fine&quot;);
                printf(&quot;\n&quot;);
                printf(&quot;lunghezza vettore: %d\n&quot;, lunghezza);
               
                break;
                       
      case 5:
                free(vettore);
                return 0;            
      default:
                       printf(&quot;Errore: Scelta non valida.\n&quot;);
        }  
   }while(scelta!=5);
   

   
   return 0;
}