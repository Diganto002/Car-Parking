#include<stdio.h>
#include<stdlib.h>

#define MAX_CAPACITY 20

struct Queue
{
    int front, rear , size;
    unsigned data;
    int *array;
};

struct Queue *createQueue(unsigned data)
{
    struct Queue *car = malloc(sizeof(struct Queue));
    car->data= data;
    car->front = car->size=0;
    car->rear = data -1;
    car->array=(int*)malloc(car->data *sizeof(int));
    return car;
}

int isEmpty(struct Queue *car)
{
    return (car->size == car ->data);
}

int isFull(struct Queue *car)
{
    return (car->size == car ->data);
}

void enqueue(struct Queue *car, int item)
{
    if(isFull(car))
    return;
    car->rear = (car-> rear +1)% car->data;
    car->array[car->rear] =item;
    car->size= car->size + 1;
}

int dequeue(struct Queue *car)
{
    if(isEmpty(car))
    return -1;
    int item = car->array[car-> front];
    car->front = (car-> front +1) % car ->data;
    car->size = car ->size -1;
    return item;
}

int main()
{
    struct Queue *carParking = createQueue(MAX_CAPACITY);
    int choice, plateNumber;

    while(1)
    {
        printf("\nEnter your choice: \n1.Entry car: \n2. Remove car: \n3. Display all cars: \n4. Number of cars in parking: \n5. Exit \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        if(isFull(carParking))
        {
            printf("The parking lot is full\n");
        }
        else
        {
            printf("Enter the car's plate number: ");
            scanf("%d", &plateNumber);
            enqueue(carParking,plateNumber);
            printf("Car with plate number %d has been added to the parking area. \n",plateNumber);
        }
            break;
        case 2:
        if(isEmpty(carParking)){
            printf("Car parking is already empty\n");
        }
        else
        {
            int removePlateNumber = dequeue(carParking);
            printf("Car with plate number %d has been removed from the parking area.\n",removePlateNumber);

        }
        break;

        case 3:
        printf("Cars currently in the parking area: ");
        for(int i=carParking->front; i<=carParking->rear; i++)
        {
            printf("%d ",carParking->array[i]);
        }
        printf("\n");
        break;

        case 4:
        printf("Number of car in parking: %d",carParking->size);
        break;

        case 5:
        printf("Exiting the program... \n");
       exit(0);

        default:
        printf("Invalid choice! Please try again \n");

        }
    }
    return 0;
}
