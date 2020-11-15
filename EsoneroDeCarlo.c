//ESONERO-PROGRAMMAZIONE PROCEDURALE
//De Carlo Giulian
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int clear();                                                                    //definizione delle funzioni
int primaopzione(char plaintextM[128]);
int secondaopzione(char plaintextM[128]);

int main(void){
char plaintextM[128],opzione;
int ripeti,penultimo;
printf("Inserire una stringa di testo da cifrare:\n");
fgets(plaintextM, 128, stdin);                                                  //Salva la stringa di testo nel vettore e controlla la sua dimensione
penultimo=strlen(plaintextM)-1;
do{
  if(plaintextM[penultimo]!='\n'){                                              //l'if evita il problema del doppio Enter,il buffer viene pulito solo quando si supera il limite di caratteri
  clear();
 }
  printf("In quale maniera si vuol procedere?\n1)Digitare 1 se si vuole inserire autonomamente la chiave di cifratura.\n2)Digitare 2 se si vuol far generare una chiave di cifratura automaticamente.\n");
   scanf("%c",&opzione);
   switch(opzione){                                                             //menù per scegliere la modalità di utilizzo della chiave,se il valore non è 1 o 2 ripete
    case '1':
          printf("Selezionata la prima opzione!\n");
          primaopzione(plaintextM);
          ripeti=0;
          break;
    case '2':
          printf("Selezionata la seconda opzione!\n");
          secondaopzione(plaintextM);
          ripeti=0;
          break;
    default :
          printf("Scelta errata.\n");
          ripeti=1;
          if((plaintextM[penultimo]!='\n')||(opzione=='\n')) {printf("Premere nuovamente Enter.\n");}
          clear();
          break;
  }
 }while(ripeti);
}



int clear(){                                                                    //funzione che permette di eliminare il buffer
  char c;
  while((c= getchar()) != '\n' && c != EOF);
  return 0;
}



int primaopzione(char plaintextM[128]){                                         //funzione che svolge la prima scelta
  char keyK[128],cifraC[128],testofinale[128];
  int dimensioneK,dimensioneM,flag=0;
  dimensioneM=strlen(plaintextM);
  clear();
  do{
     printf("Inserire una stringa di testo utilizzata come chiave(la chiave deve essere maggiore o uguale al plaintext):\n");
     fgets(keyK, 128, stdin);
     dimensioneK=strlen(keyK);
     if(dimensioneK<dimensioneM){
       printf("ERRORE!la chiave deve essere maggiore del plaintext.\n");
       flag=1;
     }else{flag=0;}

 }while(flag);                                                                  //verifica le dimensioni della chiave
   for(int i=0;i<=dimensioneM;i++){
     cifraC[i]=(plaintextM[i] ^ keyK[i]);                                       //effettua lo xor tra il plaintext e la chiave (carattere per carattere)
   }
   for(int i=0;i<=dimensioneM;i++){
     testofinale[i]=(cifraC[i] ^ keyK[i]);                                      //effettua lo xor tra il testo cifrato e la chiave per ricevere il testo iniziale
   }
     printf("La stringa cifrata e': %s \n",cifraC);
     printf("Il testo iniziale e': %s \n",testofinale);
     return 0;
}



int secondaopzione(char plaintextM[128]){                                       //funzione che svolge la seconda scelta
  time_t t;
  char keyK[128],cifraC[128],testofinale[128];
  int dimensioneM;
  dimensioneM=strlen(plaintextM);
  srand((unsigned)time(&t));                                                    //Inizializza la generazione di numeri pseudocasuali utilizzando il tempo come seme
  for(int i=0;i<=dimensioneM;i++){
  keyK[i] = (rand()%96)+32;                                                     //genera i caratteri della key, evitando i primi 32 della tabella ASCII
  }
  printf("La chiave generata e': %s \n",keyK);
  for(int i=0;i<=dimensioneM;i++){
    cifraC[i]=(plaintextM[i] ^ keyK[i]);                                        //effettua lo xor tra il plaintext e la chiave (carattere per carattere)
  }
  for(int i=0;i<=dimensioneM;i++){
    testofinale[i]=(cifraC[i] ^ keyK[i]);                                       //effettua lo xor tra il testo cifrato e la chiave per ricevere il testo iniziale
  }
    printf("La stringa cifrata e': %s \n",cifraC);
    printf("Il testo iniziale e': %s\n",testofinale);
  return 0;
}
