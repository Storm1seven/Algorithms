# include<stdio.h>
# include<string.h>
int main(){
    struct donor{
        char id[50];
        char group[3];
        int age;
        int ml;
    };
    int n;
    scanf("%d", &n);
    struct donor a[n];
    for(int i = 0; i < n; i++){
        scanf("%s %s %d %d", a[i].id, a[i].group, &a[i].age, &a[i].ml);
    }
    char group[3];
    scanf("%s", group);
    for(int i = 0; i < n; i++){
        if (a[i].age < 50 && strcmp(a[i].group, group) == 0){
            printf("%s %d\n", a[i].id, a[i].ml);
        }
    }
    char id[50];
    scanf("%s", id);
    int total = 0;
    for(int i = 0; i<n; i++){
        if (strcmp(id, a[i].id) == 0){
            total+=a[i].ml;
        }
    }
    printf("%d\n", total);
    return 0;
}