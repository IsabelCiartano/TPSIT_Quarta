Date* createDate(int gg,int mm,int aa){
    Date* date=(Date*)malloc(sizeof(Date));
    date->gg=gg;
    date->mm=mm;
    date->aa=aa;
    return date;
}

void freeDate(Date*d){
    free(d);
}

Date*createDateFromCSV(char*s){
    char ** fields=split(s,",");
    int gg=atoi(fields[0]);
    int mm=atoi(fields[1]);
    int aa=atoi(fields[2]);
    Date*d=createDate(gg,mm,aa);
    freeArraystring(fields);// bisogna prima fare la free di fields 
    return d;
}

char* dateToCSV(Date* d){
    static char Buffer[MAX_STRING_LENGTH];
    sprintf(buffer,"%d/%d/%d",d->gg,d->mm,d->aa);
    return strdup(buffer);

}

Date ** datesFromCSV(FILE* fd,int*c){
    Date ** ret=NULL;
    char* line;int i=0;
    while(line=readLine(fd)){
        Date*d=createDateFromCSV(line);
        ret=(Date**)malloc(sizeof(Date*)*(i+1));
        ret[i]=d;
        i++;
    }
     ret=(Date**)malloc(sizeof(Date*)*(i+1));
     ret[i]=NULL;
     *c=i;
    return ret;
}


int dateCmp(Date d1, Date d2) {
    if (d1.aa != d2.aa)
        return (d1.aa > d2.aa) ? 1 : -1;

    if (d1.mm != d2.mm)
        return (d1.mm > d2.mm) ? 1 : -1;

    if (d1.gg != d2.gg)
        return (d1.gg > d2.gg) ? 1 : -1;

    return 0;
}