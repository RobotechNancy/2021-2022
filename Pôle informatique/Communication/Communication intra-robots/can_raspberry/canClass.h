#if !defined CANCLASS_H
#define CANCLASS_H
#include <thread>

    class Can{
      public:
        int s;
        int idMessageActuel;
        Can();
        int send(int addr, int codeFct);
        int send(int addr, int codeFct ,int data[], int data_len);
        int listen();
        int start_listen();
    };
    struct CanResponse;
    

#endif
