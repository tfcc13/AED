# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

    //TODO
template <class T>
bool StackExt<T>::empty() const {
    return values.empty();
}

//TODO
template <class T>
T& StackExt<T>::top() {
    T* x = new T();
    if (!values.empty()) {
        *x = values.top();
        return *x;
    }
    else {
        throw std::runtime_error("Stack is empty.");
    }
}

//TODO
template <class T>
void StackExt<T>::pop() {
    if (values.empty()) return;
    if (values.top() == minimums.top()) {
        cout << "Taking the minimum: " << minimums.top() << '\n' ;
        minimums.pop();

    }
    values.pop();
}

//TODO
//! Se os mínimos repetirem-se acrescenta na stack
template <class T>
void StackExt<T>::push(const T& val) {
    values.push(val);
    if (minimums.empty() || val <= minimums.top()) {
        minimums.push(val);
        cout << "pushing the minimum: " << minimums.top() << '\n' ;
    }
}

//TODO

template <class T>
T& StackExt<T>::findMin() {
    T* x = new T;
    if(!minimums.empty()) {
            *x = minimums.top();
        }
    return *x;
}

