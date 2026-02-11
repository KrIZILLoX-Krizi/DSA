



#define STACK_SIZE 5





class Stack
{
public:
  void sPush (int data);
  void sPop (void);
  bool sEmpty (void);
  int sTop (void);

private:
  int top = -1;
  int capacity = STACK_SIZE;
  int size = 0;
  int stack[STACK_SIZE];
};