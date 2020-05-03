typedef struct _node{

    int ns;
    struct _node * next;
} Node;

void insert(Node ** head, Node ** tail, int n);
void delete(Node ** head, Node ** tail ,int n);