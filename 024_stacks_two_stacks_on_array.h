



#define MAX_STACK_SIZE 3
#define MIN_STACK_SIZE -1

using namespace std;

class TwoStacks
{
public:
  void push1 (int a);
  void push2 (int a);
  int pop1 ();
  int pop2 ();
  bool empty1 ();
  bool empty2 ();
  int top1 ();
  int top2 ();
  bool checkOverflow ();
  bool checkUnderflow ();

private:
  int stack[MAX_STACK_SIZE];
  int i_top1 = MIN_STACK_SIZE;
  int i_top2 = MAX_STACK_SIZE;
};

void TC1 ()
{
  cout << "==TC1==begin===============" << endl;
  TwoStacks st;
  cout << "push 1" << endl;
  st.push1(1);
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;
  cout << "push 2" << endl;
  st.push1(2);
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "push 3" << endl;
  st.push1(3);
  cout << "----------------------" << endl;
  cout << "top 1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "push 4" << endl;
  st.push1(4);
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "pop1" << endl;
  st.pop1();
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "pop1" << endl;
  st.pop1();
  cout << "----------------------" << endl;
  cout << "top 1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "pop1" << endl;
  st.pop1();
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "pop1" << endl;
  st.pop1();
  cout << "----------------------" << endl;
  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  cout << "pop2" << endl;
  st.pop2();
  cout << "----------------------" << endl;
  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;
  cout << "pop2" << endl;
  st.pop2();
  cout << "----------------------" << endl;
  cout << "pop2" << endl;
  st.pop2();
  cout << "----------------------" << endl;
  cout << "pop1" << endl;
  st.pop1();
  cout << "----------------------" << endl;
  cout << "==TC1==end===============" << endl << endl;
}

void TC2 ()
{
  cout << "==TC2==begin===============" << endl;
  TwoStacks st;
  cout << "push 1" << endl;
  st.push1(1);
  cout << "----------------------" << endl;

  cout << "push 2" << endl;
  st.push1(2);
  cout << "----------------------" << endl;

  cout << "push 3" << endl;
  st.push1(3);
  cout << "----------------------" << endl;

  cout << "push 4" << endl;
  st.push1(4);
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;

  cout << "==TC2==end===============" << endl << endl;
}

void TC3 ()
{
  cout << "==TC3==begin===============" << endl;
  TwoStacks st;

  cout << "push1 1" << endl;
  st.push1(1);
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "push2 3" << endl;
  st.push2(3);
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "push2 2" << endl;
  st.push2(2);
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;

  cout << "push1 2" << endl;
  st.push1(2);
  cout << "----------------------" << endl;

  cout << "push2 1" << endl;
  st.push2(1);
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "push2 1" << endl;
  st.push2(1);
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;

  cout << "push1 1" << endl;
  st.push1(1);
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;
  
  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "pop1" << endl;
  cout << st.pop1() << endl;
  cout << "----------------------" << endl;

  cout << "pop2" << endl;
  cout << st.pop2() << endl;
  cout << "----------------------" << endl;

  cout << "push1 1" << endl;
  st.push1(1);
  cout << "----------------------" << endl;

  cout << "top1" << endl;
  cout << st.top1() << endl;
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;
  
  cout << "pop2" << endl;
  cout << st.pop2() << endl;
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "pop2" << endl;
  cout << st.pop2() << endl;
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "pop2" << endl;
  cout << st.pop2() << endl;
  cout << "----------------------" << endl;

  cout << "top2" << endl;
  cout << st.top2() << endl;
  cout << "----------------------" << endl;

  cout << "==TC3==end===============" << endl << endl;
}
