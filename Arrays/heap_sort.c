#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int size,data_generated=0;
int check(int data_generated)
{
    if(data_generated == 0)
        return 0;
    else
        return 1;
}

void max_heapify(int arr[], int i,int size)
{
    int temp,largest;
    //int largest=i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= size && arr[l] > arr[i])
        largest = l;
    else
        largest=i;

    if (r <= size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr, largest, size);
    }
}

void build_max_heap(int arr[],int size)
{
    for (int i = size / 2 ; i >= 1; i--)
        max_heapify(arr, i, size);
}

void heapSort(int arr[], int size)
{
    int temp;
    build_max_heap(arr,size);

    for (int i = size; i >= 2; i--)
    {
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        size= size - 1;
        max_heapify(arr, 1, size);
    }
}

void asce(int arr[],int size)
{
    for (int i = 1; i <= size; ++i){
        for (int j = i + 1; j <= size; ++j){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void desc(int arr[],int size)
{
    for (int i = 1; i <= size; ++i){
        for (int j = i + 1; j <= size; ++j){
            if (arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void print_array(int arr[],int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int heap_extract_max(int arr[],int size)
{
    if(size<1)
        printf("Heap underflow\n");
    int max=arr[1];
    arr[1]=arr[size];
    size=size-1;
    max_heapify(arr,1,size);
    return max;
}

void heap_increase_key(int arr[],int i,int key)
{
    if(key<arr[i])
        printf("New key is smaller than current key \n");
    arr[i]=key;
    while(i>1 && arr[i/2]<arr[i])
    {
        int temp;
        temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }

}

void max_heap_insert(int arr[],int key,int size)
{
    size++;
    arr[size]=INT_MIN;
    heap_increase_key(arr,size,key);
}

int search(int arr[],int key_old,int size)
{
    for(int i=1;i<=size;i++)
    {
        if(arr[i]==key_old)
            return i;
    }
}

int delete_ele(int arr[],int size,int delete_element)
{
    int flag=0;
    for(int i=1;i<=size;i++)
    {
        if(arr[i]==delete_element)
        {
            flag=1;
            for(int j=i;j<size;j++)
            {
                arr[j]=arr[j+1];
            }
            size--;
            break;
        }
    }
    return flag;
}


int main()
{
    time_t start,end;
    double t_random,t_ascending,t_desc;

    int maximum,key_old,key_new,index,delete_element;
    int flag_value;

    int x;
    printf("0 --> Exit\n");
    printf("1 --> random array input\n");
    printf("2 --> Display the array. \n");
    printf("3 --> Sorted array using Max-Heap Sort.\n");
    printf("4 --> Sort array in descending order\n");
    printf("5 --> TC to sort ascending of random data\n");
    printf("6 --> TC to sort ascending of data already sorted in ascending order\n");
    printf("7 --> TC to sort ascending of data already sorted in descending order\n");
    printf("8 --> TC of all cases\n");
    printf("9 --> Extract largest element\n");
    printf("10 --> Replace value at a node with new value\n");
    printf("11 --> Insert a new element\n");
    printf("12 --> Delete an element\n");

    srand(time(0));
    size= rand() % 100;
    int arr[size],key;
    while(1)
    {
        printf("\n which operation to be done \n");
        scanf("%d",&x);
        switch (x)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("size = %d\n", size);
                for (int i = 1; i <= size; i++)
                {
                    arr[i] = rand() % 1000;
                }
                printf("Random data generated successfully \n");
                data_generated=1;
                break;
            case 2:
                if(check(data_generated) == 1)
                {
                    print_array(arr, size);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 3:
                if(check(data_generated) == 1)
                {
                    heapSort(arr, size);
                    printf("After sorting the array in ascending order \n");
                    print_array(arr, size);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 4:
                if(check(data_generated) == 1)
                {
                    desc(arr, size);
                    printf("After sorting the array in descending order \n");
                    print_array(arr, size);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 5:
                if(check(data_generated) == 1)
                {
                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_random= end - start;
                    printf("Time taken in ms of rand: %f\n", t_random);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;

            case 6:
                if(check(data_generated) == 1)
                {
                    asce(arr, size);

                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_ascending= end - start;
                    printf("Time taken in ms of ascending data: %f\n", t_ascending);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 7:
                if(check(data_generated) == 1)
                {
                    desc(arr, size);

                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_desc= end - start;
                    printf("Time taken in ms of descending data: %f\n", t_desc);

                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 8:
                if(check(data_generated) == 1)
                {
                    heapSort(arr, size);

                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_ascending= end - start;


                    desc(arr, size);

                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_desc= end - start;


                    start=clock();
                    heapSort(arr, size);
                    end=clock();
                    t_random= end - start;

                    printf("Value of n Ascending Data  Descending Data  Random Data \n");
                    printf("%d \t %f \t %f \t %f ",size, t_ascending, t_desc, t_random);
                }
                else
                {
                    printf("First generate random data \n");
                }

                break;

            case 9:
                if(check(data_generated) == 1)
                {
                    build_max_heap(arr, size);
                    print_array(arr, size);
                    printf("\n");
                    maximum=heap_extract_max(arr, size);
                    printf("Extracted Largest element %d\n", maximum);
                    size--;
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 10:
                if(check(data_generated) == 1)
                {
                    build_max_heap(arr, size);
                    printf("\n");
                    print_array(arr, size);
                    printf("\n");
                    printf("Enter the key value to be changed :- ");
                    scanf("%d",&key_old);
                    index=search(arr, key_old, size);
                    printf("Enter new key value :- ");
                    scanf("%d",&key_new);
                    heap_increase_key(arr, index, key_new);
                    build_max_heap(arr, size);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 11:
                if(check(data_generated) == 1)
                {
                    build_max_heap(arr, size);
                    printf("Enter the element to be inserted :- ");
                    scanf("%d",&key);
                    max_heap_insert(arr, key, size);
                    size++;
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            case 12:
                if(check(data_generated) == 1)
                {
                    build_max_heap(arr, size);
                    printf("Array data \n");
                    print_array(arr, size);
                    printf("Enter the element to be deleted :- ");
                    scanf("%d",&delete_element);
                    flag_value=delete_ele(arr, size, delete_element);
                    if(flag_value == 1)
                    {
                        printf("Element deleted succesfully\n");
                        size--;
                    }
                    else
                        printf("Element not found \n");
                    build_max_heap(arr, size);
                }
                else
                {
                    printf("First generate random data \n");
                }
                break;
            default:
                printf("enter correct no \n");
                break;
        }
    }
}
