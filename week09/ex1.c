
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void AgeIncrease (int frames);
int OldestIndex (int frames);

struct PageTable {
  int frame_number;
  bool valid;
}*PageTable;

struct FrameTable {
  int page_number;
  int age;
}*FrameTable;

int main (void){

  FILE *fTemp=fopen("input.txt", "r");
  int pages = -1;
  int temp;
  while (!feof(fTemp)){
    fscanf(fTemp, "%d", &temp);
    pages++;
  }

  
  
  printf("Number of frames:\n");
  int frames;
  scanf("%d", &frames);
  
  PageTable=malloc(sizeof(PageTable)*pages);
  FrameTable=malloc(sizeof(FrameTable)*frames);
  
  int i;
  for (i=0;i<pages; i++){
    PageTable[i].valid=false;
  }
  
  for (i=0;i<frames;i++){
    FrameTable[i].age=0;
  }
  

  FILE *fp=fopen("input.txt", "r");
  int request;
  int frame_table_counter=0;
  int page_miss_counter=0;
  int page_hit_counter=0;
  int request_counter=0;
  int memory_ref_counter=0;

  //add frame size to page faults later
  while (!feof(fp)){
    fscanf(fp, "%d", &request);
    request_counter++;
    if (PageTable[request].valid==false){
      FrameTable[frame_table_counter].page_number=request;
      PageTable[request].valid=true;
      PageTable[request].frame_number=frame_table_counter;
      frame_table_counter++;
      page_miss_counter++;
      memory_ref_counter++;
    }  
    else{
      page_hit_counter++;
    }
    
    if (frame_table_counter==frames){
      break;
    }
  }
  
  
  while (!feof(fp)){
    fscanf(fp, "%d", &request);
    request_counter++;
    AgeIncrease(frames);
    if (PageTable[request].valid==false){
      int oldest_page=OldestIndex(frames);
      PageTable[FrameTable[oldest_page].page_number].valid=false;
      FrameTable[oldest_page].page_number=request;
      FrameTable[oldest_page].age=0;
      PageTable[request].frame_number=oldest_page;
      PageTable[request].valid=true;
      page_miss_counter++;
      memory_ref_counter++;
    }
    else{
      page_hit_counter++;
    }
    
  }
  
  printf("Total page Miss %d\n", page_miss_counter);
  printf("Total page Hits %d\n", page_hit_counter);
  printf("Hit/Miss ratio = %f\n", (double)page_hit_counter/page_miss_counter);

  fclose(fp);
  free(PageTable);
  free(FrameTable);
  
  return 0;
}

void AgeIncrease (int frames){
  int i;
  for (i=0;i<frames;i++){
    FrameTable[i].age++;
  }
}

int OldestIndex (int frames){
  int oldest=-1;
  int i;
  int index;
  for (i=0;i<frames;i++){
    if (oldest<FrameTable[i].age){
      oldest=FrameTable[i].age;
      index=i;
    }
  }
  return index;
}
