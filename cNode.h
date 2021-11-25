class Node {
  public: 
    int number;
    Node* prev;
    int distance;
    int color;

    Node(int _number);
    void setColor(int _color);
    int getColor();
    int getNumber();
};