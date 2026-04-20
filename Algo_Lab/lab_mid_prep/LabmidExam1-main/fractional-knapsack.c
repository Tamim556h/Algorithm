#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
    int index;
} Item;

void sortItems(Item items[], int n) {
    // Sort items by value/weight ratio in descending order
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(items[j].ratio > items[i].ratio){
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    Item items[n];
    
    printf("Enter weights of items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&items[i].weight);
        items[i].index = i+1;
    }
    
    printf("Enter values of items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&items[i].value);
        items[i].ratio = (float)items[i].value/items[i].weight;
    }
    
    printf("Enter maximum capacity: ");
    scanf("%d",&W);
    
    sortItems(items,n);
    
    float totalValue = 0;
    printf("\nItems taken:\n");
    for(int i=0;i<n && W>0;i++){
        if(items[i].weight <= W){
            printf("Item %d (whole) \n", items[i].index);
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            printf("Item %d (%.2f fraction)\n", items[i].index, (float)W/items[i].weight);
            totalValue += items[i].value * ((float)W/items[i].weight);
            W = 0;
        }
    }
    
    printf("Maximum Profit: %.2f\n", totalValue);
    return 0;
}
