#include <algorithm>
#include "packagingMachine.h"

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}


//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================
// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {

    std::sort(objs.begin(), objs.end());

    int counter = 0;
    for (auto it = objs.begin() ; it != objs.end(); it++) {
        if (it->getWeight() <= boxCapacity) {
            objects.push(*it);
            objs.erase(it);
            counter++;
            it--; // Quando se faz um erase o apontador fica a apontar para o próximo objeto
            //torna-se necessário corrigir o apontador
        }
    }
	return counter;
}


//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
// TODO
Box PackagingMachine::searchBox(Object& obj) {
    Box tempBox;
    HeapBox tempBoxes;
    while(!boxes.empty()) {
        tempBox = boxes.top();
        if(boxes.top().getFree() >= obj.getWeight()) {
            boxes.pop();
            while(!tempBoxes.empty()) {
                boxes.emplace(tempBoxes.top());
                tempBoxes.pop();
            }
            return  tempBox;
        }
        else {
            tempBoxes.emplace(tempBox);
            boxes.pop();
        }
    }

    while(!tempBoxes.empty()) {
        boxes.emplace(tempBoxes.top());
        tempBoxes.pop();
    }
    Box new_box = Box(boxCapacity);
    return new_box;
}



//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
// TODO
unsigned PackagingMachine::packObjects() {
	return 0;
}


//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;
	return res;
}
