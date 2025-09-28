#include <stdio.h>
#include <string.h>
struct Accessories {char id[10];char type[50];char name[100];float rate;char feature[100];char origin[100];};
struct Doors{char id[7]; char name[100]; float rate; char origin[100];};
struct Paints{char id[7]; char name[100]; float rate; char origin[100];};
struct Tiles{char id[7]; char name[100]; float rate; char origin[100];};
struct Windows{char id[7]; char name[100]; float rate; char origin[100];};
struct Wood{char id[7]; char name[100]; float rate; char origin[100];};
struct accessorylist{char name[100];float quantity;float rate;};
void printBill(float budget, float woodarea, float windowno, float doorno,float tilearea, float paintarea,struct accessorylist *usedaccessories, int usedAccessoryCount);
void setwood(const char *woodname, struct Wood wood[], int woodlength);
void setwindow(const char *windowname, struct Windows window[], int windowlength);
void setdoor(const char *doorname, struct Doors door[], int doorlength);
void setpaint(const char *paintname, struct Paints paint[], int paintlength);
void settile(const char *tilename, struct Tiles tile[], int tilelength);
float paintarea = 0.0,woodarea=0.0,tilearea=0.0,windowarea=0.0,doorarea=0.0;
struct accessorylist usedaccessories[100];  // or however many you want
int usedAccessoryCount = 0;
float budget = 0.0;

//Declaring global variables

    struct Accessories accessories[100];
    struct Doors door[100];
    struct Paints paint[100];
    struct Tiles tile[100];
    struct Windows window[100];
    struct Wood wood[100];
    char Woodname[100];
    char Windowname[100];
    char Tilename[100];
    char Paintname[100];
    char Doorname[100];
    float selectedWoodRate = 0.0;
    float selectedDoorRate = 0.0;
    float selectedPaintRate = 0.0;
    float selectedTileRate = 0.0;
    float selectedWindowRate = 0.0;
    float woodcost=0.0;
    float doorcost=0.0;
    float tilecost=0.0;
    float paintcost=0.0;
    float windowcost=0.0;
    float accessorycost=0.0;
    float roomlength,roombreadth,roomheight;

void Titleprint() {
    // ANSI escape code for magenta text
    printf("\033[1;35m");  // 1 = bold, 35 = magenta

    // ASCII art
    printf(
        "   _____ _____            ______ _______ _____ _   _  _____             _______       ____  _      ______ \n"
        "  / ____|  __ \\     /\\   |  ____|__   __|_   _| \\ | |/ ____|           |__   __|/\\   |  _ \\| |    |  ____|\n"
        " | |    | |__) |   /  \\  | |__     | |    | | |  \\| | |  __               | |  /  \\  | |_) | |    | |__   \n"
        " | |    |  _  /   / /\\ \\ |  __|    | |    | | | . ` | | |_ |              | | / /\\ \\ |  _ <| |    |  __|  \n"
        " | |____| | \\ \\  / ____ \\| |       | |   _| |_| |\\  | |__| |              | |/ ____ \\| |_) | |____| |____ \n"
        "  \\_____|_|  \\_\\/_/    \\_\\_|       |_|  |_____|_| \\_|\\_____|              |_/_/    \\_\\____/|______|______|\n"
        "                                                                                                          \n"
        "                                                                                                          \n"
    );

    // Reset color back to normal
    printf("\033[0m");

    
}

int AddAccessory(struct Accessories accessory[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Accessories new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Type: "); scanf(" %[^\n]", new.type);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Feature: "); scanf(" %[^\n]", new.feature);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    accessory[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%s,%.2f,%s,%s\n", new.id, new.type, new.name, new.rate, new.feature, new.origin);
    fclose(fp);
    return 1;
}
int RemoveAccessory(struct Accessories accessory[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of accessory to remove: ");
    scanf(" %[^\n]", remove_name);\

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(accessory[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                accessory[j] = accessory[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Accessory with Name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "id,type,name,rate,feature,origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%s,%.2f,%s,%s\n",
                accessory[i].id,
                accessory[i].type,
                accessory[i].name,
                accessory[i].rate,
                accessory[i].feature,
                accessory[i].origin);
    }

    fclose(fp);
    return 1;
}

int AddDoor(struct Doors door[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Doors new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    door[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%.2f,%s\n", new.id, new.name, new.rate, new.origin);
    fclose(fp);
    return 1;
}

int RemoveDoor(struct Doors door[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of door to remove: ");
    scanf(" %[^\n]", remove_name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(door[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                door[j] = door[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Door with name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "Door ID,Door Name,Cost per Door (INR),Material Origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%.2f,%s\n", door[i].id, door[i].name, door[i].rate, door[i].origin);
    }

    fclose(fp);
    return 1;
}

int AddPaint(struct Paints paint[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Paints new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    paint[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%.2f,%s\n", new.id, new.name, new.rate, new.origin);
    fclose(fp);
    return 1;
}

int RemovePaint(struct Paints paint[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of paint to remove: ");
    scanf(" %[^\n]", remove_name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(paint[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                paint[j] = paint[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Paint with name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "Paint ID,Paint Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%.2f,%s\n", paint[i].id, paint[i].name, paint[i].rate, paint[i].origin);
    }

    fclose(fp);
    return 1;
}

int AddTile(struct Tiles tile[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Tiles new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    tile[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%.2f,%s\n", new.id, new.name, new.rate, new.origin);
    fclose(fp);
    return 1;
}

int RemoveTile(struct Tiles tile[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of tile to remove: ");
    scanf(" %[^\n]", remove_name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(tile[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                tile[j] = tile[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Tile with name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "Tile ID,Tile Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%.2f,%s\n", tile[i].id, tile[i].name, tile[i].rate, tile[i].origin);
    }

    fclose(fp);
    return 1;
}

int AddWindow(struct Windows window[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Windows new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    window[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%.2f,%s\n", new.id, new.name, new.rate, new.origin);
    fclose(fp);
    return 1;
}

int RemoveWindow(struct Windows window[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of window to remove: ");
    scanf(" %[^\n]", remove_name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(window[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                window[j] = window[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Window with name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "Window ID,Window Name,Cost per Window (INR),Material Origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%.2f,%s\n", window[i].id, window[i].name, window[i].rate, window[i].origin);
    }

    fclose(fp);
    return 1;
}

int AddWood(struct Wood wood[], int *count, const char *filename) {
    if (*count >= 100) {
        printf("Array full, can't add more.\n");
        return 0;
    }

    struct Wood new;
    printf("Enter ID: "); scanf("%s", new.id);
    printf("Enter Name: "); scanf(" %[^\n]", new.name);
    printf("Enter Rate: "); scanf("%f", &new.rate);
    printf("Enter Origin: "); scanf(" %[^\n]", new.origin);

    wood[*count] = new;
    (*count)++;

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }
    fprintf(fp, "%s,%s,%.2f,%s\n", new.id, new.name, new.rate, new.origin);
    fclose(fp);
    return 1;
}

int RemoveWood(struct Wood wood[], int *count, const char *filename) {
    char remove_name[100];
    printf("Enter Name of wood to remove: ");
    scanf(" %[^\n]", remove_name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(wood[i].name, remove_name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                wood[j] = wood[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Wood with name \"%s\" not found.\n", remove_name);
        return 0;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    fprintf(fp, "Wood ID,Wood Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < *count; i++) {
        fprintf(fp, "%s,%s,%.2f,%s\n", wood[i].id, wood[i].name, wood[i].rate, wood[i].origin);
    }

    fclose(fp);
    return 1;
}

int LoadAccessories(const char *filename, struct Accessories accessory[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
    }
    char line[512];
    int records = 0;
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        return 0;
    }

    while (fgets(line, sizeof(line), fp) && records < 100) {
        line[strcspn(line, "\n")] = '\0';

        int read = sscanf(
            line, "%9[^,],%49[^,],%99[^,],%f,%99[^,],%99[^,\n]",
            accessory[records].id,
            accessory[records].type,
            accessory[records].name,
            &accessory[records].rate,
            accessory[records].feature,
            accessory[records].origin
        );

        if (read == 6) {
            records++;
        } else {
            printf("Format error in line: %s\n", line);
        }
    }

    fclose(fp);
    return records;
}

int LoadPaints(const char *filename, struct Paints paint[]) {
    FILE *file = fopen(filename,"r");
    if (file == NULL) {
        printf("Error opening File\n");
    }

    char line[512];
    int records = 0;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0;
    }

    while (fgets(line, sizeof(line), file) && records < 100) {
        line[strcspn(line, "\n")] = '\0';
        int read = sscanf(line, "%6[^,],%99[^,],%f,%99[^,\n]",
                           paint[records].id, paint[records].name,
                           &paint[records].rate, paint[records].origin);

        if (read == 4)
            records++;
        else
            printf("Format error in line: %s\n", line);
    }

    fclose(file);
    return records;
}

int LoadDoors(const char *filename, struct Doors door[]) {
    FILE *file = fopen(filename,"r");
    if (file == NULL) {
        printf("Error opening File\n");
    }

    char line[512];
    int records = 0;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0;
    }

    while (fgets(line, sizeof(line), file) && records < 100) {
        line[strcspn(line, "\n")] = '\0';
        int read = sscanf(line, "%6[^,],%99[^,],%f,%99[^,\n]",
                           door[records].id, door[records].name,
                           &door[records].rate, door[records].origin);

        if (read == 4)
            records++;
        else
            printf("Format error in line: %s\n", line);
    }

    fclose(file);
    return records;
}

int LoadTiles(const char *filename,struct Tiles tile[]){
    FILE *file=fopen(filename,"r");
    if(file==NULL){
        printf("Error Opening File\n");
    }
    char line[512];
    int records=0;
    
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0;
    }

    while(fgets(line,sizeof(line),file) && records<100){
        line[strcspn(line,"\n")]='\0';
        int read=sscanf(line,"%6[^,],%99[^,],%f,%99[^,\n]",tile[records].id,tile[records].name,&tile[records].rate,tile[records].origin);
    if(read==4)
    records++;
    else
    printf("Format error in line: %s\n",line);
    }
    fclose(file);
    return records;
}

int LoadWindows(const char *filename,struct Windows window[]){
    FILE *file=fopen(filename,"r");
    if(file==NULL){
        printf("Error Opening File\n");
    }
    char line[512];
    int records=0;
    
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0;
    }

    while(fgets(line,sizeof(line),file) && records<100){
        line[strcspn(line,"\n")]=='\0';
        int read=sscanf(line,"%6[^,],%99[^,],%f,%99[^,\n]",window[records].id,window[records].name,&window[records].rate,window[records].origin);
    if(read==4)
    records++;
    else
    printf("Format error in line: %s\n",line);
    }
    fclose(file);
    return records;
}

int LoadWood(const char *filename,struct Wood wood[]){
    FILE *file=fopen(filename,"r");
    if(file==NULL){
        printf("Error Opening File\n");
    }
    char line[512];
    int records=0;
    
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return 0;
    }

    while(fgets(line,sizeof(line),file) && records<100){
        line[strcspn(line,"\n")]=='\0';
        int read=sscanf(line,"%6[^,],%99[^,],%f,%99[^,\n]",wood[records].id,wood[records].name,&wood[records].rate,wood[records].origin);
    if(read==4)
    records++;
    else
    printf("Format error in line: %s\n",line);
    }
    fclose(file);
    return records;
}

void PrintAccessories(struct Accessories accessory[], int records) {
    printf("ID,Type,Name,Rate,Feature,Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %s, %.2f, %s, %s\n",
               accessory[i].id,
               accessory[i].type,
               accessory[i].name,
               accessory[i].rate,
               accessory[i].feature,
               accessory[i].origin);
    }
}

void PrintDoors(struct Doors door[],int records){
    printf("Door ID,Door Name,Cost per Door (INR),Material Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %.2f, %s\n",
               door[i].id,
               door[i].name,
               door[i].rate,
               door[i].origin);
    }
}
void PrintPaints(struct Paints paint[],int records){
    printf("Paint ID,Paint Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %.2f, %s\n",
               paint[i].id,
               paint[i].name,
               paint[i].rate,
               paint[i].origin);
    }
}
void PrintTiles(struct Tiles tile[],int records){
    printf("Tile ID,Tile Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %.2f, %s\n",
               tile[i].id,
               tile[i].name,
               tile[i].rate,
               tile[i].origin);
    }
}
void PrintWindows(struct Windows window[],int records){
    printf("Window ID,Window Name,Cost per Window (INR),Material Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %.2f, %s\n",
               window[i].id,
               window[i].name,
               window[i].rate,
               window[i].origin);
    }
    printf("\nRecords read: %d\n", records);
}
void PrintWood(struct Wood wood[],int records){
    printf("Wood ID,Wood Name,Cost per Square Meter (INR),Country of Origin\n");
    for (int i = 0; i < records; i++) {
        printf("%s, %s, %.2f, %s\n",
               wood[i].id,
               wood[i].name,
               wood[i].rate,
               wood[i].origin);
    }
    printf("\nRecords read: %d\n", records);
}

void showAllBedroomTemplates() {
    printf("\n--- BEDROOM TEMPLATE 1 ---\n");
    printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(1)                  CUPBOARD   |\n"
           "|  SIDE TABLE                            |\n"
           "|  _________                             |\n"
           "| |  BED    |                            |\n"
           "| |_________|                            |\n"
           "| (wooden wall)                          |\n"
           "|                             PLANT      |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
        printf("\033[0m");


    printf("\n--- BEDROOM TEMPLATE 2 ---\n");
    printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(2)                    CUPBOARD |\n"
           "|   _________                            |\n"
           "|  |  BED    |                           |\n"
           "|  |_________|                           |\n"
           "|                                        |\n"
           "| (wooden wall)                          |\n"
           "| PLANT                                  |\n"
           "+----------------------------------------+\n"
           "|                             DOOR       |\n");
        printf("\033[0m");

    printf("\n--- BEDROOM TEMPLATE 3 ---\n");
        printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT   |\n"
           "|  _________                             |\n"
           "| |  BED    |  SIDE TABLE                |\n"
           "| |_________|                            |\n"
           "|                                        |\n"
           "| STUDY DESK     TV UNIT       CUPBOARD  |\n"
           "|       (wooden wall)        LOUNGE      |\n"
           "+----------------------------------------+\n"
           "|                       DOOR             |\n");
    printf("\033[0m");
    printf("\n--- BEDROOM TEMPLATE 4 ---\n");
    printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)  WALL ART  BOOKSHELF|\n"
           "|                                        |\n"
           "|SIDE TABLE                              |\n"
           "|  _________                             |\n"
           "| |  BED    |                   TV UNIT  |\n"
           "| |_________|             (wooden wall)  |\n"
           "|                                        |\n"
           "|  LOUNGE             CUPBOARD           |\n"
           "|  PLANT                                 |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
        printf("\033[0m");
}

void showSelectedBedroomTemplate(int choice, int woodlength, int tilelength, int doorlength, int paintlength, int windowlength, float budget)
 {
    printf("\nYou selected Bedroom Template %d\n", choice);
    switch (choice) {
        case 1: 
            printf("\033[1;34m");
            printf("+----------------------------------------+\n"
           "|  WINDOW(1)                  CUPBOARD   |\n"
           "|  SIDE TABLE                            |\n"
           "|  _________                             |\n"
           "| |  BED    |                            |\n"
           "| |_________|                            |\n"
           "| (wooden wall)                          |\n"
           "|                             PLANT      |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
            printf("\033[0m");
            printf("Enter the dimensions of the room in the format :\n <length>\n <breadth \n <height>\n");
            scanf("%f",&roomlength);
            scanf("%f",&roombreadth);
            scanf("%f",&roomheight);
            printf("\n\n");
            float woodarea=0;
            float sideareab = roombreadth*roomheight;
            float totalarea = (roombreadth*roomheight*2)+(roomlength*roombreadth*2)+(roomlength*roomheight*2);
            float remainingarea=totalarea-(roomlength*roombreadth);
            printf("Please select type of wood : \n");
            PrintWood(wood,woodlength);
            printf("\nYour Choice : ");
            scanf("%s",Woodname);
            setwood(Woodname,wood,woodlength);
            woodarea=(sideareab*1);
            woodcost=selectedWoodRate*woodarea;
            remainingarea=remainingarea-woodarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for woodworks : Rs. %f\n\n ",woodcost);

            printf("\n\nPlease select type of window : (1 window is 0.1x0.1 meters) \n");
            PrintWindows(window,windowlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",Windowname);
            setwindow(Windowname,window,windowlength);
            float windowno=1;
            float windowarea=windowno*0.01;
            windowcost=selectedWindowRate*windowno;
            remainingarea=remainingarea-windowarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Windows : Rs. %f\n\n ",windowcost);

            printf("\n\nPlease select type of Door : (1 door is 2x0.8 meters) \n");
            PrintDoors(door,doorlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Doorname);
            setdoor(Doorname,door,doorlength);
            printf("Selected Door type : %s\n",Doorname);
            float doorno=1;
            float doorarea=doorno*0.8*2;
            doorcost=selectedDoorRate*doorno;
            remainingarea=remainingarea-doorarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Doors : Rs. %f\n\n ",doorcost);

            printf("\n\nPlease select type of Tiles : \n");
            PrintTiles(tile,tilelength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Tilename);
            settile(Tilename,tile,tilelength);
            float tilearea=roomlength*roombreadth;
            tilecost=selectedTileRate*tilearea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Tiles : Rs. %f\n\n ",tilecost);

            printf("\n\nPlease select type of Paint to apply : \n");
            PrintPaints(paint,paintlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Paintname);
            setpaint(Paintname,paint,paintlength);
            printf("Selected Paint type : %s\n",Paintname);
            paintcost=selectedPaintRate*(remainingarea+(roomlength*roombreadth));   
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Paintwork : Rs. %f\n\n ",paintcost);
            printBill(budget, woodarea, windowno, doorno, tilearea, paintarea, usedaccessories, usedAccessoryCount);
           break;
        case 2: 
           printf("+----------------------------------------+\n"
           "|  WINDOW(2)                    CUPBOARD |\n"
           "|   _________                            |\n"
           "|  |  BED    |                           |\n"
           "|  |_________|                           |\n"
           "|                                        |\n"
           "| (wooden wall)                          |\n"
           "| PLANT                                  |\n"
           "+----------------------------------------+\n"
           "|                             DOOR       |\n");
            break;
        case 3: 
           printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT   |\n"
           "|  _________                             |\n"
           "| |  BED    |  SIDE TABLE                |\n"
           "| |_________|                            |\n"
           "|                                        |\n"
           "| STUDY DESK     TV UNIT       CUPBOARD  |\n"
           "|       (wooden wall)        LOUNGE      |\n"
           "+----------------------------------------+\n"
           "|                       DOOR             |\n");  
           break;
        case 4:
            printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)  WALL ART  BOOKSHELF|\n"
           "|                                        |\n"
           "|SIDE TABLE                              |\n"
           "|  _________                             |\n"
           "| |  BED    |                   TV UNIT  |\n"
           "| |_________|             (wooden wall)  |\n"
           "|                                        |\n"
           "|  LOUNGE             CUPBOARD           |\n"
           "|  PLANT                                 |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
           break;       
        default:
            printf("Invalid template number.\n");
        
        
    }
    
}

void showAllLivingRoomTemplates() {
    printf("\n--- LIVING ROOM TEMPLATE 1 ---\n");
        printf("\033[1;34m");
    printf("+-----------------------------------------+\n"
           "|  WINDOW(1)                    DOOR      |\n"
           "|                TV UNIT                  |\n"
           "|       ______________________            |\n"
           "|      |                      |   PLANT🌿 |\n"
           "|      |   L-SHAPED SECTIONAL |           |\n"
           "|      |______________________|           |\n"
           "|                                         |\n"
           "|     MONSTERA PLANT         (wooden wall)|\n"
           "+-----------------------------------------+\n");
    printf("\033[0m");
    printf("\n--- LIVING ROOM TEMPLATE 2 ---\n");
        printf("\033[1;34m");
    printf("+------------------------------------+\n"
           "|  DOOR           WINDOW(2)          |\n"
           "|   ________                         |\n"
           "|  |        |                        |\n"
           "|  | COUCH  |            TV UNIT     |\n"
           "|  |________|                        |\n"
           "|(wooden wall)                       |\n"
           "|                             PLANT🌿|\n"
           "|       FIDDLE LEAF FIG              |\n"
           "+------------------------------------+\n");
    printf("\033[0m");

    printf("\n--- LIVING ROOM TEMPLATE 3 ---\n");
        printf("\033[1;34m");
    printf("+-----------------------------------------+\n"
           "|  WINDOW(full wall)              PLANT🌿|\n"
           "|   ________         ________            |\n"
           "|  | COUCH  |       | COUCH  |           |\n"
           "|  |________|       |________|           |\n"
           "|                                        |\n"
           "|        ** COFFEE TABLE **              |\n"
           "|(wooden wall)    TV UNIT (bottom wall)  |\n"
           "+-----------------------------------------+\n"
           "|  DOOR                                 |\n");
               printf("\033[0m");

    printf("\n--- LIVING ROOM TEMPLATE 4 ---\n");
        printf("\033[1;34m");
    printf("+-----------------------------------------+\n"
           "|  WINDOW(full wall)              PLANT🌿  |\n"
           "|  ________                                |\n"
           "| | COUCH  |                      TV UNIT  |\n"
           "| |________|                (wooden wall)  |\n"
           "|                                 BOOKSHELF|\n"
           "|     FIDDLE LEAF FIG  + Rug (optional)    |\n"
           "+-----------------------------------------+\n"
           "|  DOOR                                    |\n");
               printf("\033[0m");
}

void showSelectedLivingRoomTemplate(int choice,int woodlength,int tilelength,int doorlength,int paintlength,int windowlength,float budget) {
    printf("\nYou selected Living Room Template %d\n", choice);
    switch (choice) {
        case 1:
            printf("\033[1;34m");
            printf("+-----------------------------------------+\n"
           "|  WINDOW(1)                    DOOR      |\n"
           "|                TV UNIT                  |\n"
           "|       ______________________            |\n"
           "|      |                      |   PLANT🌿 |\n"
           "|      |   L-SHAPED SECTIONAL |           |\n"
           "|      |______________________|           |\n"
           "|                                         |\n"
           "|     MONSTERA PLANT         (wooden wall)|\n"
           "+-----------------------------------------+\n");
               printf("\033[0m");
            break;
        case 2:
            printf("\033[1;34m");
            printf("+------------------------------------+\n"
           "|  DOOR           WINDOW(2)          |\n"
           "|   ________                         |\n"
           "|  |        |                        |\n"
           "|  | COUCH  |            TV UNIT     |\n"
           "|  |________|                        |\n"
           "|(wooden wall)                       |\n"
           "|                             PLANT🌿|\n"
           "|       FIDDLE LEAF FIG              |\n"
           "+------------------------------------+\n");
    printf("\033[0m");
    

            printf("Enter the dimensions of the room in the format :\n <length>\n <breadth \n <height>\n");
            scanf("%f",&roomlength);
            scanf("%f",&roombreadth);
            scanf("%f",&roomheight);
            printf("\n\n");
            float sideareal = roomlength*roomheight;
            float sideareab = roombreadth*roomheight;
            float totalarea = (roombreadth*roomheight*2)+(roomlength*roombreadth*2)+(roomlength*roomheight*2);
            float remainingarea=totalarea-(roomlength*roombreadth);
            float woodarea=0;
            printf("Please select type of wood : \n");
            PrintWood(wood,woodlength);
            printf("\nYour Choice : ");
            scanf("%s",Woodname);
            setwood(Woodname,wood,woodlength);
            woodarea=(sideareab*1);
            woodcost=selectedWoodRate*woodarea;
            remainingarea=remainingarea-woodarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for woodworks : Rs. %f\n\n ",woodcost);
            printf("\n\nPlease select type of window : (1 window is 0.1x0.1 meters) \n");
            PrintWindows(window,windowlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",Windowname);
            setwindow(Windowname,window,windowlength);
            float windowno=2;
            float windowarea=windowno*0.01;
            windowcost=selectedWindowRate*windowno;
            remainingarea=remainingarea-windowarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Windows : Rs. %f\n\n ",windowcost);

            printf("\n\nPlease select type of Door : (1 door is 2x0.8 meters) \n");
            PrintDoors(door,doorlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Doorname);
            setdoor(Doorname,door,doorlength);
            printf("Selected Door type : %s\n",Doorname);
            float doorno=1;
            float doorarea=doorno*0.8*2;
            doorcost=selectedDoorRate*doorno;
            remainingarea=remainingarea-doorarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Doors : Rs. %f\n\n ",doorcost);

            printf("\n\nPlease select type of Tiles : \n");
            PrintTiles(tile,tilelength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Tilename);
            settile(Tilename,tile,tilelength);
            float tilearea=roomlength*roombreadth;
            tilecost=selectedTileRate*tilearea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Tiles : Rs. %f\n\n ",tilecost);

            printf("\n\nPlease select type of Paint to apply : \n");
            PrintPaints(paint,paintlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Paintname);
            setpaint(Paintname,paint,paintlength);
            printf("Selected Paint type : %s\n",Paintname);
            paintcost=selectedPaintRate*(remainingarea+(roomlength*roombreadth));   
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Paintwork : Rs. %f\n\n ",paintcost);
            printBill(budget, woodarea, windowno, doorno, tilearea, paintarea, usedaccessories, usedAccessoryCount);
            break;
        case 3:
             printf("+-----------------------------------------+\n"
           "|  WINDOW(full wall)              PLANT🌿|\n"
           "|   ________         ________            |\n"
           "|  | COUCH  |       | COUCH  |           |\n"
           "|  |________|       |________|           |\n"
           "|                                        |\n"
           "|        ** COFFEE TABLE **              |\n"
           "|(wooden wall)    TV UNIT (bottom wall)  |\n"
           "+-----------------------------------------+\n"
           "|  DOOR                                 |\n");
            break;
        case 4:
           printf("+-----------------------------------------+\n"
           "|  WINDOW(full wall)              PLANT🌿  |\n"
           "|  ________                                |\n"
           "| | COUCH  |                      TV UNIT  |\n"
           "| |________|                (wooden wall)  |\n"
           "|                                 BOOKSHELF|\n"
           "|     FIDDLE LEAF FIG  + Rug (optional)    |\n"
           "+-----------------------------------------+\n"
           "|  DOOR                                    |\n");
            break;
        default:
            printf("Invalid template number.\n");
    }
}

void showAllDiningRoomTemplates() {
    printf("\n--- DINING ROOM TEMPLATE 1 ---\n");
        printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(2)                             |\n"
           "|                                        |\n"
           "|         RECTANGULAR DINING TABLE       |\n"
           "|        _________________________       |\n"
           "|       |                         |      |\n"
           "|       |        4 CHAIRS         |      |\n"
           "|       |_________________________|      |\n"
           "|                                        |\n"
           "|            SMALL CUPBOARD              |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
            printf("\033[0m");


    printf("\n--- DINING ROOM TEMPLATE 2 ---\n");
        printf("\033[0m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT 🌿|\n"
           "|                                        |\n"
           "|    ROUND DINING TABLE (6 CHAIRS)       |\n"
           "|         ________________               |\n"
           "|        |                |              |\n"
           "|        |     TABLE      |              |\n"
           "|        |________________|              |\n"
           "|                                        |\n"
           "|  MINI BAR    CABINET    LOUNGE 🪑      |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
            printf("\033[0m");

    printf("\n--- DINING ROOM TEMPLATE 3 ---\n");
        printf("\033[1;34m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(3)                             |\n"
           "|                                        |\n"
           "|       DINING TABLE – 4 CHAIRS          |\n"
           "|     _________________________          |\n"
           "|    |                         |         |\n"
           "|    |        TABLE            |         |\n"
           "|    |_________________________|         |\n"
           "|                                        |\n"
           "|         SMALL STORAGE UNIT             |\n"
           "|    (wooden wall)            PLANT 🌿   |\n"
           "+----------------------------------------+\n");
    printf("\033[0m");


    printf("\n--- DINING ROOM TEMPLATE 4 ---\n");
        printf("\033[0m");
    printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT 🌿|\n"
           "|                                        |\n"
           "|      LARGE DINING TABLE – 8 CHAIRS     |\n"
           "|     ____________________________       |\n"
           "|    |                            |      |\n"
           "|    |         GRAND TABLE        |      |\n"
           "|    |____________________________|      |\n"
           "|                                        |\n"
           "|    SHOWCASE      WINE RACK    LOUNGE 🪑|\n"
           "+----------------------------------------+\n");
            printf("\033[0m");
}

void showSelectedDiningRoomTemplate(int choice,int woodlength,int tilelength,int doorlength,int paintlength,int windowlength,float budget) {
    printf("\nYou selected Dining Room Template %d\n", choice);
    switch (choice) {
        case 1:
             printf("+----------------------------------------+\n"
           "|  WINDOW(2)                             |\n"
           "|                                        |\n"
           "|         RECTANGULAR DINING TABLE       |\n"
           "|        _________________________       |\n"
           "|       |                         |      |\n"
           "|       |        4 CHAIRS         |      |\n"
           "|       |_________________________|      |\n"
           "|                                        |\n"
           "|            SMALL CUPBOARD              |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
            break;
        case 2:
             printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT 🌿|\n"
           "|                                        |\n"
           "|    ROUND DINING TABLE (6 CHAIRS)       |\n"
           "|         ________________               |\n"
           "|        |                |              |\n"
           "|        |     TABLE      |              |\n"
           "|        |________________|              |\n"
           "|                                        |\n"
           "|  MINI BAR    CABINET    LOUNGE 🪑      |\n"
           "+----------------------------------------+\n"
           "|                DOOR                    |\n");
            break;
        case 3:
            printf("\033[1;34m");
            printf("+----------------------------------------+\n"
           "|  WINDOW(3)                             |\n"
           "|                                        |\n"
           "|       DINING TABLE – 4 CHAIRS          |\n"
           "|     _________________________          |\n"
           "|    |                         |         |\n"
           "|    |        TABLE            |         |\n"
           "|    |_________________________|         |\n"
           "|                                        |\n"
           "|         SMALL STORAGE UNIT             |\n"
           "|    (wooden wall)            PLANT 🌿   |\n"
           "+----------------------------------------+\n");
               printf("\033[0m");

            printf("Enter the dimensions of the room in the format :\n <length>\n <breadth \n <height>\n");
            scanf("%f",&roomlength);
            scanf("%f",&roombreadth);
            scanf("%f",&roomheight);
            printf("\n\n");
            float woodarea=0;
            float sideareal = roomlength*roomheight;
            float totalarea = (roombreadth*roomheight*2)+(roomlength*roombreadth*2)+(roomlength*roomheight*2);
            float remainingarea=totalarea-(roomlength*roombreadth);
            printf("Please select type of wood : \n");
            PrintWood(wood,woodlength);
            printf("\nYour Choice : ");
            scanf("%s",Woodname);
            setwood(Woodname,wood,woodlength);
            woodarea=(sideareal*1);
            woodcost=selectedWoodRate*woodarea;
            remainingarea=remainingarea-woodarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for woodworks : Rs. %f\n\n ",woodcost);

            printf("\n\nPlease select type of window : (1 window is 0.1x0.1 meters) \n");
            PrintWindows(window,windowlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",Windowname);
            setwindow(Windowname,window,windowlength);
            float windowno=3;
            float windowarea=windowno*0.01;
            windowcost=selectedWindowRate*windowno;
            remainingarea=remainingarea-windowarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Windows : Rs. %f\n\n ",windowcost);

            /*printf("\n\nPlease select type of Door : (1 door is 2x0.8 meters) \n");
            PrintDoors(door,doorlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Doorname);
            setdoor(Doorname,door,doorlength);
            printf("Selected Door type : %s\n",Doorname);
            float doorno=1;
            float doorarea=doorno*0.8*2;
            doorcost=selectedDoorRate*doorno;
            remainingarea=remainingarea-doorarea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Doors : Rs. %f\n\n ",doorcost);*/

            printf("\n\nPlease select type of Tiles : \n");
            PrintTiles(tile,tilelength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Tilename);
            settile(Tilename,tile,tilelength);
            float tilearea=roomlength*roombreadth;
            tilecost=selectedTileRate*tilearea;
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Tiles : Rs. %f\n\n ",tilecost);

            printf("\n\nPlease select type of Paint to apply : \n");
            PrintPaints(paint,paintlength);
            printf("\nYour Choice : ");
            getchar();  
            scanf(" %[^\n]",&Paintname);
            setpaint(Paintname,paint,paintlength);
            printf("Selected Paint type : %s\n",Paintname);
            paintcost=selectedPaintRate*(remainingarea+(roomlength*roombreadth));   
            printf("\n----------------------------------------------------------------\n");
            printf("Expenses utilized for Paintwork : Rs. %f\n\n ",paintcost);
            printBill(budget, woodarea, windowno, 0, tilearea, paintarea, usedaccessories, usedAccessoryCount);
            break;
        case 4:
            printf("+----------------------------------------+\n"
           "|  WINDOW(full wall)             PLANT 🌿|\n"
           "|                                        |\n"
           "|      LARGE DINING TABLE – 8 CHAIRS     |\n"
           "|     ____________________________       |\n"
           "|    |                            |      |\n"
           "|    |         GRAND TABLE        |      |\n"
           "|    |____________________________|      |\n"
           "|                                        |\n"
           "|    SHOWCASE      WINE RACK    LOUNGE 🪑|\n"
           "+----------------------------------------+\n");
            break;
        default:
            printf("Invalid template number.\n");
    }
}

void setwood(const char *woodname, struct Wood wood[], int woodlength) {
    int found = 0;
    for (int i = 0; i < woodlength; i++) {
        if (strcmp(wood[i].name, woodname) == 0) {
            selectedWoodRate = wood[i].rate;
            printf("Selected wood: %s with rate %.2f\n", wood[i].name, selectedWoodRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Wood with name \"%s\" not found.\n", woodname);
    }
}

void setwindow(const char *windowname, struct Windows window[], int windowlength) {
    int found = 0;
    for (int i = 0; i < windowlength; i++) {
        if (strcmp(window[i].name, windowname) == 0) {
            selectedWindowRate = window[i].rate;
            printf("Selected window: %s with rate %.2f\n", window[i].name, selectedWindowRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Window with name \"%s\" not found.\n", windowname);
    }
}

void setdoor(const char *doorname, struct Doors door[], int doorlength) {
    int found = 0;
    for (int i = 0; i < doorlength; i++) {
        if (strcmp(door[i].name, doorname) == 0) {
            selectedDoorRate = door[i].rate;
            printf("Selected door: %s with rate %.2f\n", door[i].name, selectedDoorRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Door with name \"%s\" not found.\n", doorname);
    }
}

void setpaint(const char *paintname, struct Paints paint[], int paintlength) {
    int found = 0;
    for (int i = 0; i < paintlength; i++) {
        if (strcmp(paint[i].name, paintname) == 0) {
            selectedPaintRate = paint[i].rate;
            printf("Selected paint: %s with rate %.2f\n", paint[i].name, selectedPaintRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Paint with name \"%s\" not found.\n", paintname);
    }
}
void settile(const char *tilename, struct Tiles tile[], int tilelength) {
    int found = 0;
    for (int i = 0; i < tilelength; i++) {
        if (strcmp(tile[i].name, tilename) == 0) {
            selectedTileRate = tile[i].rate;
            printf("Selected tile: %s with rate %.2f\n", tile[i].name, selectedTileRate);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Tile with name \"%s\" not found.\n", tilename);
    }
}

float pickaccessory(struct Accessories accessory[], int accessorylength,struct accessorylist acclist[], int *usedcount) {
    char name[100];
    float quantity, cost = 0.0;
    int found;

    printf("\n------------------- Accessories -------------------\n");
    PrintAccessories(accessory, accessorylength);

    while (1) {
        printf("\nEnter the name of accessory to add (or type 'done' to finish): ");
        scanf(" %[^\n]", name);

        if (strcmp(name, "done") == 0)
            break;

        found = 0;
        for (int i = 0; i < accessorylength; i++) {
            if (strcmp(accessory[i].name, name) == 0) {
                printf("Enter quantity : ");
                scanf("%f", &quantity);
                float itemCost = quantity * accessory[i].rate;
                cost += itemCost;
                strcpy(acclist[*usedcount].name, accessory[i].name);
                acclist[*usedcount].rate = accessory[i].rate;
                acclist[*usedcount].quantity = quantity;
                (*usedcount)++;
                printf("Added %s x %.2f (Rs. %.2f each) = Rs. %.2f\n",
                       accessory[i].name, quantity, accessory[i].rate, itemCost);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Accessory with name \"%s\" not found.\n", name);
        }
    }

    return cost;
}

void budgetdisp(float woodcost,float windowcost,float doorcost,float tilecost,float paintcost,float accessorycost,float budget) {
    float totalExpense=woodcost+windowcost+doorcost+tilecost+paintcost+accessorycost;
    printf("\033[1;37m");
    printf("\n======================= Expense Summary =======================\n");
    printf("Woodwork Expenses : Rs. %.2f\n",woodcost);
    printf("Window Expenses : Rs. %.2f\n",windowcost);
    printf("Door Expenses : Rs. %.2f\n",doorcost);
    printf("Tile Expenses : Rs. %.2f\n",tilecost);
    printf("Paint Expenses : Rs. %.2f\n",paintcost);
    printf("Accessory Expenses : Rs. %.2f\n",accessorycost);
    printf("---------------------------------------------------------------\n");
    printf("Total Expense : Rs. %.2f\n",totalExpense);
    printf("Budget Provided : Rs. %.2f\n",budget);
    printf("\n================================================================\n");
    printf("\033[0m");

 if (totalExpense > budget) {
        float excess = totalExpense - budget;
        printf("\033[1;31m");
        printf("Your total expense exceeds the budget by Rs. %.2f.\n", excess);
        printf("\033[0m");
    } else if (totalExpense < budget) {
        float savings = budget - totalExpense;
        printf("\033[1;32m");
        printf("Your design is under budget by Rs. %.2f.\n", savings);
        printf("\033[0m");
        } else {
        printf("\033[1;33m");
        printf("You have exactly matched your budget.\n");
        printf("\033[0m"); }
}
void printBill(float budget, float woodarea, float windowno, float doorno, float tilearea, float paintarea, struct accessorylist usedaccessories[], int usedAccessoryCount) {
    float totalAccessoryCost=0.0;
    float totalCost=woodcost+windowcost+doorcost+tilecost+paintcost+accessorycost;

    char bill[5000];
    int offset=0;
    printf("\033[1;37m");
    offset+=sprintf(bill+offset, "=========================== DETAILED BILL ===========================\n");
    offset+=sprintf(bill+offset, "--- Main Components ---\n");
    offset+=sprintf(bill+offset, "Wood (%s): %.2f sq.m x Rs. %.2f = Rs. %.2f\n",Woodname,woodarea,selectedWoodRate,woodcost);
    offset+=sprintf(bill+offset, "Window (%s): %.2f units x Rs. %.2f = Rs. %.2f\n",Windowname,windowno,selectedWindowRate,windowcost);
    offset+=sprintf(bill+offset, "Door (%s): %.2f units x Rs. %.2f = Rs. %.2f\n",Doorname,doorno,selectedDoorRate,doorcost);
    offset+=sprintf(bill+offset, "Tiles (%s): %.2f sq.m x Rs. %.2f = Rs. %.2f\n",Tilename,tilearea,selectedTileRate,tilecost);
    offset+=sprintf(bill+offset, "Paint (%s): %.2f sq.m x Rs. %.2f = Rs. %.2f\n",Paintname,paintarea,selectedPaintRate,paintcost);
    offset+=sprintf(bill+offset, "--- Accessories Used ---\n");

    for (int i=0; i<usedAccessoryCount; i++) {
        float itemCost=usedaccessories[i].quantity*usedaccessories[i].rate;
        totalAccessoryCost+=itemCost;
        offset+=sprintf(bill+offset, "%s: %.2f units x Rs. %.2f = Rs. %.2f\n",usedaccessories[i].name,usedaccessories[i].quantity,usedaccessories[i].rate,itemCost);
    }

    offset+=sprintf(bill+offset, "Accessory Total: Rs. %.2f\n",totalAccessoryCost);
    offset+=sprintf(bill+offset, "--------------------------------------------------------------------\n");
    offset+=sprintf(bill+offset, "TOTAL EXPENSE : Rs. %.2f\n",totalCost);
    offset+=sprintf(bill+offset, "BUDGET        : Rs. %.2f\n",budget);
    printf("\033[0m");
    if (totalCost>budget) {
        float over=totalCost-budget;
            printf("\033[1;31m");
        offset+=sprintf(bill+offset, "OVER BUDGET by Rs. %.2f\n",over);
            printf("\033[0m");
    } else if (totalCost<budget) {
        float saved=budget-totalCost;
            printf("\033[1;32m");
        offset+=sprintf(bill+offset, "UNDER BUDGET by Rs. %.2f\n",saved);
            printf("\033[0m");
    } else {
            printf("\033[1;34m");
        offset+=sprintf(bill+offset, "Matched budget exactly.\n");
            printf("\033[0m");

    }
    printf("\033[1;37m");
    offset+=sprintf(bill+offset, "====================================================================\n");
    printf("%s",bill);
    printf("\033[0m");
    char choice[10];
    printf("Would you like to export the bill to a file? (yes/no): ");
    scanf("%s",choice);

    if (strcmp(choice, "yes")==0 || strcmp(choice, "Yes")==0) {
        FILE *fp=fopen("Interior_Bill.txt", "w");
        if (fp==NULL) {
            printf("Error: Could not write to file.\n");
            return;
        }
        fprintf(fp, "%s",bill);
        fclose(fp);
        printf("Bill exported successfully to 'Interior_Bill.txt'\n");
    } else {
        printf("Bill was not exported.\n");
    }
}

void designRoom(int woodlength,int tilelength,int doorlength,int paintlength,int windowlength,int accessorylength,float budget) {
    int roomChoice, designChoice, templateChoice;
    struct accessorylist usedaccessories[100];
    int usedAccessoryCount = 0;

    printf("\nWhich room would you like to design?\n");
    printf("1. Bedroom\n2. Living Room\n3. Dining Room\nEnter your choice: ");
    scanf("%d", &roomChoice);

    printf("Choose design type:\n1. Custom Design\n2. Preset Design\nEnter your choice: ");
    scanf("%d", &designChoice);

    if (designChoice == 2) {
        switch (roomChoice) {
            case 1:
                showAllBedroomTemplates();
                printf("\nEnter your template choice (1-4): ");
                scanf("%d", &templateChoice);
                showSelectedBedroomTemplate(templateChoice,woodlength,tilelength,doorlength,paintlength,windowlength,budget);
                break;
            case 2:
                showAllLivingRoomTemplates();
                printf("\nEnter your template choice (1-4): ");
                scanf("%d", &templateChoice);
                showSelectedLivingRoomTemplate(templateChoice,woodlength,tilelength,doorlength,paintlength,windowlength,budget);
                break;
            case 3:
                showAllDiningRoomTemplates();
                printf("\nEnter your template choice (1-4): ");
                scanf("%d", &templateChoice);
                showSelectedDiningRoomTemplate(templateChoice,woodlength,tilelength,doorlength,paintlength,windowlength,budget);
                break;
            default:
                printf("Invalid room choice.\n");
        }

    }
    
            else if(designChoice == 1){
                printf("Custom bill Creation\n");
        printf("Enter the dimensions of the room in the format :\n <length>\n <breadth \n <height>\n");
        scanf("%f",&roomlength);
        scanf("%f",&roombreadth);
        scanf("%f",&roomheight);
        printf("\n\n");
        float sidearea = roomlength*roomheight;
        float totalarea = (roombreadth*roomheight*2)+(roomlength*roombreadth*2)+(roomlength*roomheight*2);
        float remainingarea=totalarea;
        printf("Please select type of wood : \n");
        PrintWood(wood,woodlength);
        printf("\nYour Choice : ");
        scanf("%s",Woodname);
        setwood(Woodname,wood,woodlength);
        printf("Do you want to cover the sides of the room with wood? (y/n)\n");
        char woodside;
        int woodsideno;
        float woodarea=0;
        scanf(" %c",&woodside);
        if(woodside=='y'){
            printf("Enter the number of sides to be covered : ");
            scanf("%d",&woodsideno);
            woodarea=(sidearea*woodsideno);}
        else if(woodside=='n'){
            printf("Enter the Area to be covered by wood (in square meters) : ");
            scanf("%f",&woodarea);}
        else{
        printf("Invalid Entry - Assuming No woodworks\n");
}    
        woodcost=selectedWoodRate*woodarea;
        remainingarea=remainingarea-woodarea;
        printf("\n----------------------------------------------------------------\n");
        printf("Expenses utilized for woodworks : Rs. %f\n\n ",woodcost);

        printf("\n\nPlease select type of window : (1 window is 0.1x0.1 meters) \n");
        PrintWindows(window,windowlength);
        printf("\nYour Choice : ");
        getchar();  
        scanf(" %[^\n]",Windowname);
        setwindow(Windowname,window,windowlength);
        float windowno;//in case different dimension windows are required by user, he can use decimals
        printf("Enter the number of windows you want to include in this room : ");
        scanf(" %f",&windowno);
        float windowarea=windowno*0.01;
        windowcost=selectedWindowRate*windowno;
        remainingarea=remainingarea-windowarea;
        printf("\n----------------------------------------------------------------\n");
        printf("Expenses utilized for Windows : Rs. %f\n\n ",windowcost);

        printf("\n\nPlease select type of Door : (1 door is 2x0.8 meters) \n");
        PrintDoors(door,doorlength);
        printf("\nYour Choice : ");
        getchar();  
        scanf(" %[^\n]",&Doorname);
        setdoor(Doorname,door,doorlength);
        float doorno;//in case different dimension doors are required by user, he can use decimals
        printf("Enter the number of Doors you want to include in this room : ");
        scanf(" %f",&doorno);
        float doorarea=doorno*0.8*2;
        doorcost=selectedDoorRate*doorno;
        remainingarea=remainingarea-doorarea;
        printf("\n----------------------------------------------------------------\n");
        printf("Expenses utilized for Doors : Rs. %f\n\n ",doorcost);

        printf("\n\nPlease select type of Tiles : \n");
        PrintTiles(tile,tilelength);
        printf("\nYour Choice : ");
        getchar();  
        scanf(" %[^\n]",&Tilename);
        settile(Tilename,tile,tilelength);
        float tilearea=roomlength*roombreadth;
        tilecost=selectedTileRate*tilearea;
        printf("\n----------------------------------------------------------------\n");
        printf("Expenses utilized for Tiles : Rs. %f\n\n ",tilecost);

        printf("\n\nPlease select type of Paint to apply : \n");
        PrintPaints(paint,paintlength);
        printf("\nYour Choice : ");
        getchar();  
        scanf(" %[^\n]",&Paintname);
        setpaint(Paintname,paint,paintlength);
        printf("Selected Paint type : %s\n",Paintname);
        float paintarea = (remainingarea+(roomlength*roombreadth));
        paintcost=selectedPaintRate*paintarea;   
        printf("\n----------------------------------------------------------------\n");
        printf("Expenses utilized for Paintwork : Rs. %f\n\n ",paintcost);

        accessorycost = pickaccessory(accessories, accessorylength,usedaccessories,&usedAccessoryCount);
        printf("\n----------------------------------------------------------------\n");
        printf("Total Expenses for Accessories: Rs. %.2f\n", accessorycost);
        printBill(budget, woodarea, windowno, doorno, tilearea, paintarea, usedaccessories, usedAccessoryCount);}
 else {
        printf("Custom design feature coming soon...\n");
    }
}

int main() {
    Titleprint();
    
    const char Doorfilename[] = "Doors.csv";
    const char Paintfilename[] = "Paints.csv";
    const char Accessoryfilename[] = "Accessories.csv";
    const char Tilefilename[] = "Tiles.csv";
    const char Windowfilename[] = "Windows.csv";
    const char Woodfilename[] = "Wood.csv";
    int accessorylength = LoadAccessories(Accessoryfilename, accessories);
    int doorlength = LoadDoors(Doorfilename, door);
    int paintlength = LoadPaints(Paintfilename, paint);
    int tilelength = LoadTiles(Tilefilename, tile);
    int windowlength = LoadWindows(Windowfilename, window);
    int woodlength = LoadWood(Woodfilename, wood);
    int outflag = -1;

    while (outflag != 0) {
            printf("\033[1;36m");
        printf("\n_____________________________________________________________________________");
        printf("\n----------------------Interior Design and Planning Tool----------------------");
        printf("\n_____________________________________________________________________________");

        printf("\nFeatures available : \nEnter (1) To Preview available components\nEnter (2) To Alter prevailing Data\nEnter (3) To Start creating a bill and To design\nOR\nEnter (0) To Exit the application\nYour response: ");
        scanf("%d", &outflag);
            printf("\033[0m");
        if (outflag == 1) {
            int flag = -1;
            while (flag != 0) {
                printf("\033[1;35m");
                printf("\n                       DATA PREVIEW                       \n");
                printf("\nFor Accessories, enter 1\nFor Doors, enter 2\nFor Paints, enter 3\nFor Tiles, enter 4\nFor Windows, enter 5\nFor Wood, enter 6\nTo exit, enter 0\nEnter your choice: ");
                scanf("%d", &flag);
                    printf("\033[0m");
                if (flag == 1)
                    PrintAccessories(accessories, accessorylength);
                else if (flag == 2)
                    PrintDoors(door, doorlength);
                else if (flag == 3)
                    PrintPaints(paint, paintlength);
                else if (flag == 4)
                    PrintTiles(tile, tilelength);
                else if (flag == 5)
                    PrintWindows(window, windowlength);
                else if (flag == 6)
                    PrintWood(wood, woodlength);
                else if (flag == 0)
                    printf("Returning to main menu.\n");
                else
                    printf("Invalid choice.\n");
            }
        }
    
    else if (outflag == 2) {
    int alterflag = -1;
    while (alterflag != 0) {
            printf("\033[1;33m");
        printf("\nEnter (1) To Add an Accessory\nEnter (2) To Remove an Accessory\nEnter (3) To Add Door\nEnter (4) To Remove Door\nEnter (5) To Add Paints\nEnter (6) To Remove Paints\nEnter (7) To Add Tiles\nEnter (8) To Remove Tiles\nEnter (9) To Add Windows\nEnter (10) To Remove Windows\nEnter (11) To Add Wood\nEnter (12) To Remove Wood\nEnter (0) To Exit\nYour Response: ");
        scanf("%d", &alterflag);
            printf("\033[0m");

        if (alterflag == 1)
            AddAccessory(accessories, &accessorylength, Accessoryfilename);
        else if (alterflag == 2)
            RemoveAccessory(accessories, &accessorylength, Accessoryfilename);
        else if (alterflag == 0)
            printf("Returning to main menu.\n");
        else if (alterflag == 3)
            AddDoor(door,&doorlength,Doorfilename);
        else if (alterflag == 4)
            RemoveDoor(door,&doorlength,Doorfilename);
        else if (alterflag == 5)
            AddPaint(paint,&paintlength,Paintfilename);
        else if (alterflag == 6)
            RemovePaint(paint,&paintlength,Paintfilename);
        else if (alterflag == 7)
            AddTile(tile,&tilelength,Tilefilename);
        else if (alterflag == 8)
            RemoveTile(tile,&tilelength,Tilefilename);
        else if (alterflag == 9)
            AddWindow(window,&windowlength,Windowfilename);
        else if (alterflag == 10)
            RemoveWindow(window,&windowlength,Windowfilename);
        else if (alterflag == 11)
            AddWood(wood,&woodlength,Woodfilename);
        else if (alterflag == 12)
            RemoveWood(wood,&woodlength,Woodfilename);
        else
            printf("Invalid Entry. Please try again.\n");
    }
}

        else if (outflag == 3) {
            printf("\033[1;37m");
        printf("\n___________________________________________________________\n");
        printf("                            Design                     ");
        printf("\n___________________________________________________________");
        printf("\n");
        printf("\n----------------------Drafting a bill----------------------");
        printf("\n");
        float budget;
        printf("\nPlease enter your total budget for this room (in INR): ");
        scanf("%f",&budget);
            printf("\033[0m");
        designRoom(woodlength,tilelength,doorlength,paintlength,windowlength,accessorylength,budget);
        budgetdisp(woodcost,windowcost,doorcost,tilecost,paintcost,accessorycost,budget);
        }
        else if (outflag == 0)
            printf("Exiting application.\n");
        else
        printf("Invalid choice. Please try again.\n");
    }
    return 0;