#include "clnklist.c"

int main(){
    node *head = init();
    node *p = head;
    int i;

//    for(i = 0; i < 10; i++){
//    p = insert(p, i,i);
//    }
    p = insert(p, 1,0);
    display(p);
    printf("123");
//    display(rear(p));
//    display(p);

    printf("¿ªÊ¼²éÕÒ~\n");
    printf("1 ==> %d ", find(p, 5));
    printf("2 ==> %d ", find(p, 11));
	
}
