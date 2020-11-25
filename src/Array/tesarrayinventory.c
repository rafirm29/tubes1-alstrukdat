#include <stdio.h>
#include "arraydininventory.h"

int main(){
    TabInventory T;
    Kata Steel, Plastic, Wood;
    Inventory Inv1, Inv2, Inv3, InvSub;
    Inv1 = MakeInventory(Steel,10);
    Inv2 = MakeInventory(Plastic,20);
    Inv3 = MakeInventory(Wood,15);
    InvSub = MakeInventory(Plastic, 8);
    MakeEmptyInventory(&T,5);
    printf("maxel tab %d\n", MaxElInventory(T));
    printf("Neff array %d\n", NeffInventory(T));
    AddInventory(&T,Inv1);
    TulisIsiTabInventory(T);
    AddInventory(&T,Inv2);
    AddInventory(&T,Inv3);
    TulisIsiTabInventory(T);
    printf("maxel tab %d\n", MaxElInventory(T));
    printf("Neff array %d\n", NeffInventory(T));
    SubtractInventory(&T,InvSub);
    TulisIsiTabInventory(T);
}