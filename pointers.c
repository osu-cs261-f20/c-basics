#include <stdio.h>

#include "student.h"

void make_it_32(int* it) {
  printf("\n== inside make_it_32(), it: %p\n", it);
  printf("== inside make_it_32(), &it: %p\n", &it);
  *it = 32;
}

int main() {
  int n = 16;
  int* n_ptr = &n;
  int** n_ptr_ptr = &n_ptr;

  printf("== n: %d\n", n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== &n: %p\n", &n);
  printf("== *n_ptr: %d\n", *n_ptr);
  printf("== &n_ptr: %p\n", &n_ptr);

  *n_ptr = 8;
  printf("\n== n: %d\n", n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== &n: %p\n", &n);
  printf("== *n_ptr: %d\n", *n_ptr);
  printf("== &n_ptr: %p\n", &n_ptr);

  make_it_32(&n);
  printf("\n== n: %d\n", n);
  printf("== n_ptr: %p\n", n_ptr);
  printf("== &n: %p\n", &n);
  printf("== *n_ptr: %d\n", *n_ptr);
  printf("== &n_ptr: %p\n", &n_ptr);

  void* v_ptr = &n;
  printf("\n== *((int*)v_ptr): %d\n", *((int*)v_ptr));

  int* n_ptr2 = v_ptr;
  printf("== *n_ptr2: %d\n", *n_ptr2);

  double pi = 3.1415;
  v_ptr = &pi;
  printf("== *((double*)v_ptr): %f\n", *((double*)v_ptr));

  struct student s = {.name = "Princess Leia"};
  v_ptr = &s;
  struct student* s_ptr = v_ptr;
  /* s_ptr->name == (*s_ptr).name */
  printf("== s_ptr->name: %s\n", s_ptr->name);
  printf("== ((struct student*)v_ptr)->name: %s\n",
    ((struct student*)v_ptr)->name);
}
