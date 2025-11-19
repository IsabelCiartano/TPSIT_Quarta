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