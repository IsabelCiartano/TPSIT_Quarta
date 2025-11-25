
Event* createEvent(char*title;Date*date){
    Event* event=(Event*)malloc(sizeof(Event));
    event->title=strdup(title);
    event->date=date
    return event;
}

int getId(Event* e){
    return e->id;
}

void setDate(Event* e,Date* date){
   freeDate(e->date);
  e->date=date;
}

void freeEvent(Event* e){
    free(e->title);
    freeDate(e->date);
    free(e);
}

char* eventToCSV(Event* e){
    static char buffer[MAX_STRING_LENGTH];
    sprintf(buffer,"%s %d %d %d",e->title,e->date->gg,e->date->mm,e->date->aa);
    return strdup(buffer);
}



void sortEventsByName(Event **events, int n) {
    int k, sup;
    for (sup = n - 1; sup > 0; sup--) {
        for (k = 0; k < sup; k++) {
            if (strcmp(events[k]->title, events[k+1]->title) > 0) {
                Event *tmp = events[k];
                events[k] = events[k+1];
                events[k+1] = tmp;
            }
        }
    }
}


Event** findEventsInRange(Event** events,Date from,Date to;int* outCount){
    *outCount=0;
   Event**c=NULL;
    for(int k=0;events!=NULL;k++){
        if(dateCmp(events[k]->date,&from)>=0 && dateCmp(events[k]->date,&to)<=0){
            c = (Events**)malloc(sizeof(Event*)*(*outCount+1));
            c[*outCount]=events[k];
            (*outCount)++;
        }
    }
    return c;
}