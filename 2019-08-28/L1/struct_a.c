#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct flight_type {
  char flight_num[7];
  int altitude; // In meters
  int longitude; // In hundredths of a degree
  int latitude; // In hundredths of a degree
  int heading; // In radians
  double speed; // In m/s
} FLIGHT_TYPE;

// Prototypes
void print_record(FLIGHT_TYPE *rec);

int main() {
  // Let's create three drones in the stack and one on the heap;
  FLIGHT_TYPE drone_one; // Can use the typedef name
  FLIGHT_TYPE drone_two = {"ABC123", 52, 13012, -7730, 123, 2.3};
  struct flight_type drone_three; // Can still use the normal struct type
  FLIGHT_TYPE *drone_four = NULL; // Can dynamically allocate
  drone_four = malloc(sizeof(FLIGHT_TYPE)); // Dynamic allocation of memory 

  // Add a name to each of the four structs
  strncpy(drone_one.flight_num, "DRN1", 4);
  strncpy(drone_two.flight_num, "DRN2", 4); // This only overwrites the first 4 chars!
  strncpy(drone_three.flight_num, "DRN3", 4);
  strncpy(drone_four->flight_num, "DRN4", 4); // Remember -> for dynamic alloc structs

  // print_record expects an address for the struct in memory
  print_record(&drone_one); // drone_one is not a pointer, so use the & operator
  print_record(&drone_two);
  print_record(&drone_three);
  print_record(drone_four);  // drone_four is already a pointer

  free(drone_four); // Don't forget to free any malloc'd data
  
  return 0;
}

void print_record(FLIGHT_TYPE *rec) {
  printf("------------------\n");
  printf("%s\n-----\n", rec->flight_num);
  printf("Pos: %.2f, %.2f\n", rec->latitude/100.0, rec->longitude/100.0);
  printf("Alt: %d m\n", rec->altitude);
  printf("Hdg: %d rad\n", rec->heading);
  printf("Spd: %.2lf m/s\n", rec->speed);
  printf("------------------\n\n");
}
