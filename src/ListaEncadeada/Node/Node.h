#pragma once

template <class Tipo>
class Node {
  private:
    Node<Tipo>* prev;
    Node<Tipo>* next;
    Tipo* value;

  public:
    Node(Tipo* _value = NULL, Node<Tipo>* _prev = NULL, Node<Tipo>* _next = NULL) {
      setprev(_prev);
      setnext(_next);
      setvalue(_value);
    }
    ~Node() {
      delete value;
    }
    Node<Tipo>* getnext() {
      return next;
    }
    Node<Tipo>* getprev() {
      return prev;
    }
    Tipo* getvalue() {
      return value;
    }
    void setnext(Node<Tipo>* _next) {
      next = _next;
    };
    void setprev(Node<Tipo>* _prev) {
      prev = _prev;
    };
    void setvalue(Tipo* _value) {
      value = _value;
    }
};
