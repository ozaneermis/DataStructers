#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head, *new;
node *deleteNode(node *head)
{
    int key;
    printf("Enter the node you want to delete ");
    scanf("%d", &key);
    if (head == NULL)
    {
        printf("All nodes have been erased");
        return NULL;
    }
    node *temp = head;
    if (head->data == key && head->next == NULL)
    {
        printf("List have one node");
        return head;
    }
    else if (head->data == key && head->next != NULL)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        while (temp->next->data != key)
        {
            if (temp->next->next == NULL)
            {
                printf("Not Found ");
                return head;
            }
            temp = temp->next;
        }
        node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
    return head;
}

node *addEnd(node *n, int value)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

node *addFront(node *n, int value)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}
struct node *destroy(struct node *head)
{
    if (head == NULL)
        return NULL;
    destroy(head->next);
    free(head);
}
void createList()
{
    int i, listNumber;
    printf("Enter the number of lists you want");
    scanf("%d", &listNumber);
    if (listNumber == 0)
        printf("Please restart the code and enter bigger than 0 ");
    for (i = 0; i < listNumber; i++)
    {
        /*i 1 den büyük olursa new sürekli ilk node'u oluşturup duracağından dolayı
        if statement'ı koymak zorundaydım.*/
        if (i == 0)
        {
            new = (node *)malloc(sizeof(node));
            head = new;
        }
        else
        {
            new->next = (node *)malloc(sizeof(node));
            /*Bu new = new -> next 'nin anlamı yeni node oluştuktan sonra new 
            bir sonraki node'u işaret etmesi gerekiyordu.*/
            new = new->next;
        }
        printf("Enter the Values Please");
        /*Burada new  nasıl tekrar head'e geldiğini ve tek tek data değerini 
        atandığını anlayamadım.*/
        scanf("%d", &new->data);
    }
    /* Bunun anlamı ise en son node-next'i NULL göstermezse tanımsız olur*/
    new->next = NULL;
}

void printList(struct node *n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        //Bir sonraki node geçmesi için yazılan kod
        n = n->next;
    }
}

int main()
{

    createList();
    int choice, x;

    while (1)
    {
        printf("1-Add a node in front of  the list\n");
        printf("2-Add a node to the end of the list\n ");
        printf("3-Print all nodes\n");
        printf("4-Delede a node\n");
        printf("5-Destroys Everything\n");
        scanf("%d", &choice);
        printf("Choice : %d\n", choice);
        switch (choice)
        {
        case 1:
            printf("Please enter a value to add\n ");
            scanf("%d", &x);
            head = addFront(head, x);
            break;
        case 2:
            printf("Please enter a valute to add\n");
            scanf("%d", &x);
            head = addEnd(head, x);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            head = deleteNode(head);
            break;
        case 5:
            destroy(head);
        }

        getch();
    }
}