#include "relation.h"

// look into the following header--you can "pick apart" std::pairs using std::tie!
#include <tuple>
using namespace std;

Relation::Relation(const std::set<std::pair<int, int>>& elements)
    : elements(elements) {}

bool Relation::isRelatedTo(int x, int y) {
  std::set<std::pair<int, int>>::iterator it;
  for (it = elements.begin(); it != elements.end(); it++) {
    if(it->first == x && it->second == y) {
      return true;
    }
  }
  return false;
}

std::set<int> Relation::isRelatedToLeft(int x) {
  std::set<int> s;
  std::set<std::pair<int, int>>::iterator it;
  for (it = elements.begin(); it != elements.end(); it++) {
    if(it->second == x) {
      s.insert(it->first);
    }
  }
  return s;
}

std::set<int> Relation::isRelatedToRight(int x) {
  std::set<int> s;
  std::set<std::pair<int, int>>::iterator it;
  for (it = elements.begin(); it != elements.end(); it++) {
    if(it->first == x) {
      s.insert(it->second);
    }
}
return s;
}

bool Relation::isFunction() {
  std::set<int> yValues;
  std::set<int> xValues;
  std::set<std::pair<int, int>>::iterator it;
  for (it = elements.begin(); it != elements.end(); it++) { 
     int x = it->first;
     yValues = isRelatedToRight(x);
     if(yValues.size() != 1) {
     return false;
     }
  }
 return true;
}

bool Relation::isInjective() { 
    if(!isFunction()) {
      return false;
    }
    std::set<std::pair<int, int>>::iterator it;
    std::set<int> yValues;
    std::set<int> xValues;
    for (it = elements.begin(); it != elements.end(); it++) { 
      int y = it->second;
      xValues = isRelatedToLeft(y);
      if(xValues.size() != 1) {
        return false;
      }     
    }
  return true;
}

bool Relation::isSymmetric() {
   std::set<std::pair<int, int>>::iterator it;
    std::set<std::pair<int, int>>::iterator it2;
    for (it = elements.begin(); it != elements.end(); it++) {      
      int x = it->first;
      int y = it->second;
      bool symExists = false;
      for (it2 = elements.begin(); it2 != elements.end(); it2++) {
        if(it2->first == y && it2->second == x) {
          symExists = true;
        }
      }
      if(!symExists) {
        return false;
      }
    }
    return true;
}

bool Relation::isTransitive() {
    std::set<std::pair<int, int>>::iterator it;
    std::set<std::pair<int, int>>::iterator it2;
    std::set<std::pair<int, int>>::iterator it3;        
    for (it = elements.begin(); it != elements.end(); it++) {     
      int x = it->first;
      int y = it->second;
      for (it2 = elements.begin(); it2 != elements.end(); it2++) {
        int x2 = it2->first;
        int y2 = it2->second;
        if(y == x2) {
          bool transitiveArrow = false;
          for (it3 = elements.begin(); it3 != elements.end(); it3++) {
            if(it3->first == x && it3->second == y2) {
              transitiveArrow = true;
              break;
              }          
            } 
          if(!transitiveArrow) {
            return false;
          }
        }
      }
   }
  return true;
}
