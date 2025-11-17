//  myLib.c

void errore(char* s, int n) {
    printf("Errore %d in %s (%s) \n (exiting with error level %d)\n", errno, s, strerror(errno), n);
    exit(n);
}

char* readLine(FILE* f) {
    char buffer[MAX_STRING_LENGTH];
    int i;
    for(i = 0;
        ((buffer[i]=fgetc(f))!='\n') && (buffer[i]!=EOF); //buffer temporaneo per immagazzinare i dati 
        i++) { }  
    buffer[i] = '\0';
    return (i==0)? NULL: strdup(buffer);
}

// ATTENZIONE: Altera la stringa originale con strtok() cerca le occorrenze 
char** splitString(char* s, char separator) {
    char** tokens = NULL;
    char delimiter[2] = {separator, '\0' };//stringa per il secondo parametro di strtok stringa con un carattere 
    int count = 0;
    char* token = strtok(s, delimiter);//strtok fuori ciclo restituisce l'indirizzo della prima sottostringa primo carattere 
    //passo la stringa da decomporre e la stringa delimiter 
    while(token != NULL) {//finchè trova sottostringhe 
        // realloc(): come malloc(), ma rialloca la memoria copiando i vecchi dati
        tokens = realloc(tokens, sizeof(char*) * (count + 1));//se non ce niente di allocato fa come la malloc se invece ce qualcosa copia i vecchi dati 
        //fa una free se c'era gia qualcosa 
        tokens[count] = strdup(token);//nella posizione count di tokens duplico la sottostringa che ho strovato 
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL; // Terminatore
    return tokens;
}

void disposeStringArray(char** arr) {//eliminare il vettore di stringhe memory leak 
    for(char** temp = arr; *temp; temp++) {//inizializza un puntutore =arr che però è**
                                          //test quello puntato da temp è diverso da 0 o NULL
                                          //incremento aritmetica punta alla cella successiva 
        free(*temp);//dealloco la stringa 
    }
    free(arr);//dealloco ancora il blocco del vettore 
}

int randomRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}//srand(time(null)) srand(pid)
