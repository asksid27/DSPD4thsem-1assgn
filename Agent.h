#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED



typedef struct Agent{
    char name[50];
    int agent_id;
    char phone_no[13];
    float commission;
    char address_to_deliver[100];
    struct Agent * next;

}Agent;



#endif // AGENT_H_INCLUDED
