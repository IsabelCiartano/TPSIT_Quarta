#define MAX_STRING_LENGTH 256

typedef struct {
    int giorno;
    int mese;
    int anno;
} Date;

typedef struct {
    int id;
    char* titolo;
    Date* data;
} Meeting;

Date* createDate(int g, int m, int a){
    Date* d=(Date*)malloc(sizeof(Date));
    d->g=g;
    d->m=m;
    d->a=a;
    return d;
}

void freeDate(Date* d){
    free(d);
}

Meeting* createMeeting(char* titolo, Date* data){
    Meeting* m=(Meeting*)malloc(Meeting);
    m->titolo=strdup(titolo);
    m->data=data;
    return m;
}

void freeMeeting(Meeting* m){
    free(m->titolo);
    freeDate(m->data);
    free(m);
}

char* dateToCSV(Date* d){
    static char buffer=[MAX_STRING_LENGTH];
    sprintf(buffer,"%d/%d/%d",d->g,d->m,d->a);
    return strdup(buffer);
}

Date* dateFromCSV(char* s){
    char**fields=split(s,'/');
    int g=atoi(fields[0]);
    int m=atoi(fields[1]);
    int a=atoi(fields[2]);
    Date* d=createDate(g,m,a);
    free(fields);
    return d;
}

char* meetingToCSV(Meeting* m){
    static char buffer=[MAX_STRING_LENGTH];
    sprintf(buffer,"%s %d %d %d",m->titolo,m->data->g,m->data->m,m->data->a);
    return strdup(buffer);
}

Meeting** meetingsFromCSV(FILE* fp, int* outCount){
    Meeting ** meetings=NULL;
    *outCount=0;
    char* line;
    while((line=readLine(fd))){
        char ** fields=splitString(line,',');
        int id=fields[0];
        int titolo=fields[1];
        Date* d=(Date*)malloc(Date);
        d=createDateFromCSV(fields[2]);
        meetings=(Meeting**)malloc(sizof(Meeting*)*(outCount+1));
        meetings[*outCount]=createMeeting(id,titolo,d);
        *outCount++; 
    }
      meetings=(Meeting**)malloc(sizeof(Meeting*)*(outCount+1));
        meetings[*outCount]=NULL;
        *outCount++;
     free(fields)
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


void sortMeetingsByDate(Meeting** arr, int count){
    int k,sup;
    for(sup=count-1;sup>0;sup--){
        for(k=0;k<count;k++){
            if(dateCmp(arr[k],arr[k+1])>=0){
                Meeting* tmp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=tmp;
            }
        }
    }
}

Meeting** findMeetingsInRange(Meeting** arr, int count, Date da, Date a, int* outCount){
    Meeting **m=NULL;
    *outCount=0;
    for(int k=0;k<count;k++){
        if(dateCmp(arr[k],&da)>=0 && dateCmp(arr[k],&a)<=0){
            m=(Meeting*)malloc(sizeof(Meeting*)*(*outCount+1));
            m[outCount]=arr[k];
            *outCount++;
        }
    }
    m=(Meeting*)malloc(sizeof(Meeting*)*(*outCount+1));
            m[outCount]=NULL;
            *outCount++;
    return m;
}
