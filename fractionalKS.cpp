#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
    Item(int val, int w){
        value=val;
        weight=w;
    }
};

bool cmp(Item &a, Item &b){
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}

double ks(vector<Item>& items, int W){
    sort(items.begin(), items.end(), cmp);
    double val=0;
    double currw=0;
    for(int i=0; i<items.size(); i++){
        if(currw+items[i].weight<=W){
            currw+=items[i].weight;
            val+=items[i].value;
        }
        else{
            int rem=W-currw;
            val+=items[i].value * ((double)rem/items[i].weight);
            break;
        }
    }
    return val;
}

int main() {
     vector<Item> items = {
        Item(60, 10),
        Item(100, 20),
        Item(120, 30)
    };
    int W = 50; // Maximum weight capacity of the knapsack

    // Calculate and print the maximum value
    double maxValue = ks(items, W);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

}
