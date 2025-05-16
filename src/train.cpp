// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* temp = new Car;
  temp->light = light;
  if (first == nullptr) {
    first = temp;
    temp->prev = first;
    temp->next = first;
  } else {
    temp->prev = first->prev;
    first->prev->next = temp;
    first->prev = temp;
    temp->next = first;
  }
}

int Train::getLength() {
  if (first == nullptr) {
    return 0;
  }
  first->light = 1;
  Car* temp = first;
  int length = 0;
  while (true) {
    temp = temp->next;
    length++;
    countOp++;
    if (temp->light == 1) {
      temp->light = 0;
      for (int i = 0; i < length; i++) {
        temp = temp->prev;
        countOp++;
      }
      if (temp->light == 0) {
        return length;
      }
      length=0;
    }
  }
}


int Train::getOpCount() {
  return countOp;
}

Train::~Train() {
  if (!first) return;
  Car* temp = first->next;
  while (temp != first) {
    Car* t = temp->next;
    delete temp;
    temp = t;
  }
  delete first;
  first = nullptr;
}
